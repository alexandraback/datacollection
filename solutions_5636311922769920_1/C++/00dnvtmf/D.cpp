//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 100010;
int K, C, S;
int main()
{
#ifdef ACM_TEST
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d:", cas);
        scanf("%d%d%d", &K, &C, &S);
        if(K > S * C)
        {
            printf(" IMPOSSIBLE\n");
        }
        else
        {
            for(int i = 0; i < K;)
            {
                LL res = 0;
                for(int j = 0; j < C; ++j, ++i)
                {
                    res = res * K + (i >= K ? 0 : i);
                }
                ++res;
                printf(" %lld", res);
            }
            puts("");
        }
    }
    return 0;
}
