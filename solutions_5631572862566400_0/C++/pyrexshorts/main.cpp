#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
const int maxn = 11;
int _main()
{
    int n, f[maxn], m, ans= 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        f[i] = x-1;
    }
    m = 1 << n;
    for(int i = m-1; i >= 0; i--)
    {
        int a[maxn] = {0}, cnt = 0;
        for(int j = 0; j < n; j++)if(i & (1 << j))a[cnt++] = j;
        do
        {
            bool g = 1;
            for(int j = 0; j < cnt; j++)if(a[(j-1+cnt) % cnt] != f[a[j]] && a[(j+1) % cnt] != f[a[j]])g = 0;
            if(g)ans = max(ans, cnt);
        }while(next_permutation(a, a + cnt));
    }
    return ans;
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
        cout << "Case #" << i << ": " << _main() << "\n";
    }
    return 0;
}
