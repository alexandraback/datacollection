#include <bits/stdc++.h>

using namespace std;

const int me = 1025;
typedef long long Long;

int t;
int n;
pair<string, string> a[me];
map<string, int> m[3];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int cc = 0; cc < t; cc ++){
        cin >> n;
        for(int i = 1; i <= n; i ++)
            cin >> a[i].first >> a[i].second;
        sort(a + 1, a + n + 1);
        for(int i = 0; i < 3; i ++)
            m[i].clear();
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            if(m[1].count(a[i].first) && m[2].count(a[i].second))
                ans ++;
            m[1][ a[i].first ] ++,
            m[2][ a[i].second ] ++;
        }
        cout << "Case #" << cc + 1 << ": " << ans << endl;
    }


    return 0;
}
