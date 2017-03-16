#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define sa(n) scanf("%d", &(n))
#define ll  long long 

const int maxn = 111;
int GG[maxn][maxn];
int main(void)
{
#ifdef LOCAL
    freopen("//Users/zhaoyang/in2.txt", "r", stdin);
    freopen("//Users/zhaoyang/out2.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int got = 1; got <= T; got++) {
        ll B, M;
        cin >> B >> M;
        memset(GG, 0, sizeof(GG));
        for (ll i = 1; i < B - 1; i++) {
            for (ll j = i + 1; j <= B - 1; j++) {
                GG[i][j] = 1;
            }
        }
        printf("Case #%d: ", got);
        if(M > (1ll << (B - 2))) {
            printf("IMPOSSIBLE\n");
        } else {
            int t = 2;
            ll m = M;
            if(M == (1ll << (B - 2))) {
                for (ll i = 1; i < B; i++)  GG[i][B] = 1;
            }
            else {
                while(m > 0) {
                    if(m & 1) {
                        GG[t][B] = 1;
                    }
                    t++;
                    m >>= 1;
                }
            }
            printf("POSSIBLE\n");
            for (ll i = 1; i <= B; i++) {
                for (ll j = 1; j <= B; j++) {
                    printf("%d", GG[i][j]);
                }
                puts("");
            }
        }
    }
    return 0;
}
