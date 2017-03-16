#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
const int maxn = 200;
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
        vector <int> ans;
        int cnt[5000] = {0}, n;
        cin >> n;
        for(int i = 0; i < 2*n-1; i++)
        for(int j = 0; j < n; j++)
        {
            int x; cin >> x;
            cnt[x]++;
        }
        for(int i = 0; i < 5000; i++)if(cnt[i] % 2 == 1)cout << i << " ";
        cout << "\n";
    }
    return 0;
}
