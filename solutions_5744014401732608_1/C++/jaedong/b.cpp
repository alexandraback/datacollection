#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
int b;
long long m;

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%d%lld", &b, &m);

        long long best = 1LL << (b - 2);
        if (m <= best) {
            printf("Case #%d: POSSIBLE\n", cs);
            for (int i = 0; i < b - 1; i++) {
                for (int j = 0; j < b - 1; j++)
                    printf("%d", i < j ? 1 : 0);
                int bit;
                if (m == best)
                    bit = 1;
                else {
                    if (i)
                        bit = m & (1LL << (i - 1)) ? 1 : 0;
                    else
                        bit = 0;
                }
                printf("%d\n",  bit);
            }
            for (int i = 0; i < b; i++)
                printf("0");
            puts("");
        } else
            printf("Case #%d: IMPOSSIBLE\n", cs);
    }
}
