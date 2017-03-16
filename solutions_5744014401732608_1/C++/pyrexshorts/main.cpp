#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
const int maxn = 52;
ll b, m;
bool ans[maxn][maxn];
bool sbit(ll a, ll b)
{
    return (ll)1 << a & b;
}
void _main()
{
    cin >> b >> m;
    if((ll)1 << (b-2) < m)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    for(int i = 1; i <= b-1; i++)
    for(int j = i+1; j <= b-1; j++)ans[i][j] = 1;
    for(ll i = b-3; i >= 0; i--)if(sbit(i, m))
    {
        ans[i+2][b] = 1;
        m -= (ll)1 << i;
    }
    if(m != 0)
    {
        for(ll i = b-2; i >= 0; i--)if(sbit(i, m))
        {
            for(int j = 1; j <= i+1; j++)ans[j][b] = 1;
            break;
        }
    }
    for(int i = 1; i <= b; i++, cout << "\n")
    for(int j = 1; j <= b; j++)cout << ans[i][j];
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": ";
        memset(ans, 0, sizeof(ans));
        _main();
    }
    return 0;
}
