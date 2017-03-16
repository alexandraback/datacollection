
#include <stdio.h>
//#include <math.h>

long long fairnum[100];

long long reverse(long long a) {
    long long r=0;
    while (a) {
        r=r*10+a%10;
        a=a/10;
    }
    return r;
}

int faircnt(void) {
    long long a,b;
    int i;
    int cnt=0;
    scanf("%lld %lld",&a,&b);
    for (i=0;fairnum[i];i++)
        if (a<=fairnum[i] && fairnum[i]<=b) cnt++;
    return cnt;
}

void maketable(void) {
    long long sq,i;
    int j=0;
    i=1;
    sq=i*i;
    while (i<=10000005) {
        if (sq==reverse(sq) && i==reverse(i)) {
            //printf("%lld %lld %lld\n",i,sq,reverse(sq));
            //cnt++;
            fairnum[j++]=sq;
        }
        sq+=2*i+1;
        i++;
    }
    //return cnt;
}

int main(int argc, char **argv) {
    int i,t;
    //printf("rev %lld=%lld\n",1234LL,reverse(1234LL));
    maketable();
    scanf("%d",&t);
    for (i=1;i<=t;i++) {
        printf("Case #%d: %d\n",i,faircnt());
    }
    return 0;
}