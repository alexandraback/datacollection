#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    for(int t = 0; t < T; ++t) {
        printf("Case #%d:", t+1);
        int K, C, S; scanf("%d%d%d", &K, &C, &S);
        if(1 + max(0, K-C) > S)
            printf(" IMPOSSIBLE\n");
        else {
            long long s = 1LL;
            for(int i = 1; i <= min(K, C); ++i)
                s += (i-1) * (long long)pow(K, C-i);
            printf(" %lld", s);
            for(int i = C+1; i <= K; ++i)
                printf(" %lld", 1LL + (i-1) * (long long)pow(K, C-1));
            printf("\n");
        }
    }
}

