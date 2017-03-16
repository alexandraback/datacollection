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

int jp[5][5], js[5][5], ps[5][5];

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
        int J, P, S, K;
        cin >> J >> P >> S >> K;
        memset(jp, 0, sizeof(jp));
        memset(js, 0, sizeof(js));
        memset(ps, 0, sizeof(ps));
        vector<pair<int, pair<int, int>>> v;
        for(int i = 1; i <= J; i++)
        {
            for(int j = 1; j <= P; j++)
            {
                for(int k = 1; k <= S; k++)
                {
                    if(jp[i][j] == K || js[i][k] == K || ps[j][k] == K)
                        continue;
                    else
                    {
                        v.pb(mp(i, mp(j, k)));
                        jp[i][j]++;
                        js[i][k]++;
                        ps[j][k]++;
                    }
                }
            }
        }
        cout << "Case #" << tt << ": " << v.size() << '\n';
        for(auto k: v)
            cout << k.first << " " << k.second.first << " " << k.second.second << '\n';
    }
    return 0;
}
