#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

long T, A, B;
long result[100000000];

long isP(long x){
    char d[100];
    long len = 0;
    while (x > 0){
        d[len ++] = x % 10;
        x /= 10;
    }
    for (long i = 0; i + i < len; i ++) 
        if (d[i] != d[len - 1 - i]) return 0;
    return 1;
}

long getSeq(long x){
    long l = 0, r = min(x, 20000000L);
    while (l < r){
        long mid = (l + r + 1LL) >> 1;
        if (mid * mid > x) r = mid - 1;
        else l = mid;
    }
    return l;
}

int main(void){
    for (long i = 1; i <= 20000000; i ++){
        if (isP(i) && isP(i * i)) result[i] = 1;
    }
    for (long i = 1; i <= 20000000; i ++) result[i] += result[i - 1];
    scanf("%lu", &T);
    for (long tc = 0; tc < T; tc ++){
        scanf("%lu%lu", &A, &B);
        printf("Case #%lu: %lu\n", tc + 1, result[getSeq(B)] - result[getSeq(A - 1)]);
    }
    
    return 0;
}
