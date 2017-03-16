
#include <stdio.h>

int R,N,M,K;

int powN(int n, int p) {
    int r=0;
    while (n % p==0) {r++;n=n/p;}
    return r;
}

int max(int a, int b) {return a>b?a:b;}

void goody(void) {
    int max3=0;
    int max5=0;
    int max7=0;
    int oddpow2=0;
    int max2=0;
    int i,v,p2;
    int left;
    for (i=0;i<K;i++) {
        scanf("%d",&v);
        max3=max(max3,powN(v,3));
        max5=max(max5,powN(v,5));
        max7=max(max7,powN(v,7));
        p2=powN(v,2);
        max2=max(max2,p2);
        oddpow2 |= p2 & 1;
    }
    //printf("max3=%d max5=%d max2=%d odd2=%d\n",max3,max5,max2,oddpow2);
    left=N;
    while (max7) {
        printf("7");
        max7--;
        left--;
    }
    while (max5) {
        printf("5");
        max5--;
        left--;
    }
    while (max3>max2) {
        printf("3");
        max3--;
        left--;
    }
    if (max3+max2==left) {
        while (max3) {
            printf("3");
            max3--;
            left--;
        }
        while (max2) {
            printf("2");
            max2--;
            left--;
        }
        return;
    }
    if (oddpow2==0 && max2>=2 && left+1<=max2+max3) { //even pow2 --> implies 4
        printf("4");
        max2-=2;
        left--;
    }
    while (max3 && max3+max2>left) {
        printf("6");
        max3--;
        left--;
    }
    while (max3) {
        printf("3");
        max3--;
        left--;
    }
    while (2*left>max2) {
        printf("2");
        max2-=1;
        left--;
    }
    while (3*left>max2) {
        printf("4");
        max2-=2;
        left--;
    }
    while (left>0) {
        printf("8");
        max2-=3;
        left--;
    }
}

void lucky(void) {
    int i;
    scanf("%d %d %d %d",&R,&N,&M,&K);
    for (i=1;i<=R;i++) {
        goody();
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int t;
    scanf("%d",&t);
    printf("Case #1:\n");
    lucky();
    return 0;
}