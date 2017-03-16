#include <bits/stdc++.h>
using namespace std;
bitset<10> seen;
int N, x;
int main () {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &x);
        printf("Case #%d: ", i+1);
        seen.reset();
        bool done = 0;
        for (int k = 1; k < 1000000 && !done; ++k) {
            long long t = x;
            t *= k;
            char str[100];
            sprintf(str, "%lld", t);
            for (int j = strlen(str)-1; j >= 0; --j) seen[str[j]-'0'] = 1;
            bool fail = 0;
            for (int j = 0; j < 10; ++j) {
                if (!seen[j]) fail = 1;
            }
            if (!fail) {
                printf("%lld\n", t);
                done = 1;
            }
        }
        if (!done) puts("INSOMNIA");
    }
}