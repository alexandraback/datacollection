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
        int num = (int)(ceil(K * 1.0 / C));
        printf("Case #%d:", ++cas);
        if(num > S) {
            printf("  IMPOSSIBLE\n");
            continue;
        } 
        for(int i = 1; i <= num; i++) {
            int now = (i - 1) * C + 1;
            long long st = (long long)(now - 1) * base; 
            long long tmp = base;
            for(int j = 1; j < C; j++) {
                if(j + now > K) break;
                tmp /= K;
                st += tmp * (long long)(j + now - 1);
            }
            //long long mid = ed - base + 1 + 1;
            printf(" %lld", st + 1);
        }
        printf("\n");
    }
    return 0;
}
