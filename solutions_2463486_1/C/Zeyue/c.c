#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int t, p;
long long a, b;
int ret;

int getNumWidth(unsigned long long num) {
    int width = 0;
    while (num > 0){
        width++;
        num = num / 10;
    }
    return width;
}

int isPalindrome( long long num) {
    long long
        d = 0,
        p = num,
        r = 0;
    while (num > 0)  {
        d = num % 10;
        r = r * 10 + d;
        num = num / 10;
    }
    return (p == r);
}

int transposition(int num)
{  
    int i = 0;
    int trans = 0;
    while (num != 0) {  
        i = num % 10;  
        num = num / 10;
        trans = trans*10 + i;
    }  
    return trans;  
}  

long long nextPalindrome(long long num) {
    /* tow case:
       12311 -> 12321
       12321 -> 12421
       choose minium which is bigger than num itself
    */
    long long newNum = 0;
    long long newNum2 = 0;

    int width = getNumWidth(num);
    long long half = (num/pow(10, width/2));

    if (width%2 == 0) {
        newNum = (half+1)*pow(10, width/2) + transposition(half+1);
        newNum2 = (half)*pow(10, width/2) + transposition(half);
    } else {
        newNum = (half+1)*pow(10, width/2) + transposition((half+1)/10);
        newNum2 = (half)*pow(10, width/2) + transposition(half/10);
    }
    
    if (newNum2 > num) {
        newNum = newNum2;
    }
    
    return newNum;
}

int calLarge(long long a, long long b) {
    long long i = sqrt(a);
    int count = 0;
    while (i*i <= b) {
        if (i*i >= a && isPalindrome(i*i)) {
            count++;
        }
        i = nextPalindrome(i);
    }
    return count;
}

int calSmall(int a, int b) {
    int fsnum[10] = {1, 4, 9, 121, 484};
    int min = 0, max = 0;    
    int i;
    if (a > 484) return 0;
    for (i=0; i<5; i++) {
        if (fsnum[i] >= a) {
            min = i;
            break;
        }
    }
    for (i=4; i>=0; i--) {
        if (fsnum[i] <= b) {
            max = i;
            break;
        }
    }
    if (max < min) {
        return 0;
    } else {
        return (max - min + 1);
    }
}

int main() {
    /* freopen("c-small.in", "r", stdin); */
    
    scanf("%d", &t);

    for (p=0; p<t; p++) {
        scanf("%lld %lld", &a, &b);
        ret = calLarge(a, b);
        printf("Case #%d: %d\n", p+1, ret);
    }
    return 0;
}
