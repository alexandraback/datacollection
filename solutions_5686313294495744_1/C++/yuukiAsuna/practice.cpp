#include <bits/stdc++.h>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 1e3 + 10,MOD = 7+1e9;
map<string, int> mpl, mpr;
string a[N][2];
bool vis[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        memset(vis, 0, sizeof vis);
        mpl.clear(), mpr.clear();
        for(int i = 0;i < n;i ++) 
        {
            cin >> a[i][0] >> a[i][1];
            mpl[a[i][0]] ++, mpr[a[i][1]] ++;
        }
        int ans = n;
        while(1)
        {
            bool ok = 0;
            for(int i = 0;i < n;i ++) if(!vis[i])
            {
                int x = mpl[a[i][0]], y = mpr[a[i][1]];
                if(x >= 2 && y >= 2)
                {
                    ok = 1;
                    vis[i] = 1;
                    mpl[a[i][0]] --, mpr[a[i][1]] --;
                    break;
                }
            }
            if(ok) ans --;
            else break;
        }
        printf("Case #%d: %d\n", ++ca, n - ans);
    }
    return 0;
}