#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FILE "file"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const ull ULLINF = numeric_limits<ull>::max();
const double PI = acos(-1.0);

int main()
{
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++)
    {
        int n;
        cin >> n;
        vector<string> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        set<string> fst, scd;
        int ans = 0;
        for(int mask = 0; mask < (1 << n); mask++)
        {
            fst.clear();
            scd.clear();
            for(int i = 0; i < n; i++)
            {
                if(!(mask & (1 << i)))
                {
                    fst.insert(a[i]);
                    scd.insert(b[i]);
                }
            }
            bool ok = 1;
            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    if(fst.find(a[i]) == fst.end() || scd.find(b[i]) == scd.end())
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok)
                ans = max(ans, __builtin_popcount(mask));
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
    return 0;
}
