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
char buf[100];
int vis[10], tot;
int solve(int n)
{
    for(int i = 0; i < 10; ++i) vis[i] = 0;
    tot = 0;
    int x;
    for(x = n; tot < 10; x += n)
    {
        sprintf(buf, "%d", x);
        for(int i = 0; buf[i]; ++i)
        {
            if(!vis[buf[i] - '0'])
            {
                vis[buf[i] - '0'] = 1;
                ++tot;
                if(tot == 10)
				{
                    return x;
				}
            }
        }
    }
    return x;
}
int main()
{
#ifdef ACM_TEST
    freopen("A-small-attempt.in", "r", stdin);
    freopen("A-small-attempt.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        int n;
        scanf("%d", &n);
        if(n == 0)
        {
            printf("Case #%d: INSOMNIA\n", cas);
        }
        else
        {
            printf("Case #%d: %d\n", cas, solve(n));
        }
    }
    return 0;
}
