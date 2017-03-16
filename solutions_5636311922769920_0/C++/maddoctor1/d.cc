#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int T, S, K, C,cas = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &K, &C, &S);
        long long base = 1;
        for(int i = 0; i < C - 1; i++) {
            base = base * (long long)K;
        }
        int num = S;
        printf("Case #%d:", ++cas);
        if(num > S) {
            printf("  IMPOSSIBLE\n");
            continue;
        } 
        for(int i = 1; i <= num; i++) {
            //long long st = (long long)(i - 1) * base * (long long)C; 
            long long ed = (long long)i * base ;
            //long long mid = ed - base + 1 + 1;
            printf(" %lld", ed);
        }
        printf("\n");
    }
    return 0;
}
