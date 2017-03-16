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

bool ans[60][60];

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
        int N, M;
        cin >> N >> M;
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++)
                ans[i][j] = 1;
        for(int i = 0; i < N; i++)
            ans[0][i] = ans[i][0] = 0;
        if(M > (1 << (N - 2)))
            cout << "Case #" << tt << ": IMPOSSIBLE\n";
        else
        {
            cout << "Case #" << tt << ": POSSIBLE\n";
            if(M == (1 << (N - 2)))
            {
                for(int i = 1; i < N; i++)
                    ans[0][i] = 1;
            }
            else
            {
                int i = N - 1;
                while(M)
                {
                    i--;
                    if(M % 2)
                        ans[0][i] = 1;
                    M >>= 1;
                }
            }
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                    cout << ans[i][j];
                cout << '\n';
            }
        }
    }
    return 0;
}
