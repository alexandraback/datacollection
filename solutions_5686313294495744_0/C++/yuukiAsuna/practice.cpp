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
const int N = 20,MOD = 7+1e9;
map<string,bool> mpl, mpr;
string a[N][2];
int id[N], oid[N];
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
        string s1, s2;
        for(int i = 0;i < n;i ++) cin >> a[i][0] >> a[i][1];
        int ALL = (1<<n);
        int ans = 0;
        for(int i = 1;i < ALL;i ++)
        {
            int cnt = 0;
            mpl.clear(), mpr.clear();
            for(int j = 0;j < n;j ++)
            {
                if((i>>j)&1) mpl[a[j][0]] = 1, mpr[a[j][1]] = 1;
                else id[cnt ++] = j;
            }
            bool ok = 1;
            for(int j = 0;j < cnt;j ++)
            {
                int x = id[j];
                if(mpl.count(a[x][0]) && mpr.count(a[x][1])) continue;
                ok = 0;
                break;
            }
            if(ok) ans = max(ans, cnt);
        }
        printf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}