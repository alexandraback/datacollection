#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

int T, A, B;
int result[100000000];

int isP(int x){
    char d[100];
    int len = 0;
    while (x > 0){
        d[len ++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i + i < len; i ++) 
        if (d[i] != d[len - 1 - i]) return 0;
    return 1;
}

int getSeq(int x){
    int l = 0, r = min(x, 20000000);
    while (l < r){
        int mid = (l + r + 1) >> 1;
        if (mid * mid > x) r = mid - 1;
        else l = mid;
    }
    return l;
}

int main(void){
    for (int i = 1; i <= 20000000; i ++){
        if (isP(i) && isP(i * i)) result[i] = 1;
    }
    for (int i = 1; i <= 20000000; i ++) result[i] += result[i - 1];
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc ++){
        scanf("%d%d", &A, &B);
        printf("Case #%d: %d\n", tc + 1, result[getSeq(B)] - result[getSeq(A - 1)]);
    }
    
    return 0;
}
