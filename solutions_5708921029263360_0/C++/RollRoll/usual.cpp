#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for(int i = 0; i < (x); i++)
#define DEP(i,x) for(int i = (x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define ALL(x) (x).begin(), (x).end()
#define SZ(v) ((int)v.size())
#define UNIQUE(v) sort(ALL(v)); v.erase(unique(ALL(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-8
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
// ************************************************************************

int J, P, S, K;
int s12[22][22];
int s13[22][22];
int s23[22][22];

void solve() {
    scanf("%d%d%d%d", &J, &P, &S, &K);
    vector<pair<int, PII> > v;
    set(s12,0);
    set(s23,0);
    set(s13,0);
    for (int i = 1; i <= J; i++)
        for (int j = 1; j <= P; j++)
            for (int k = 1; k <= S; k++) {
                if (s12[i][j] >= K || s23[j][k] >= K || s13[i][k] >= K)
                    continue;
                s12[i][j]++;
                s23[j][k]++;
                s13[i][k]++;
                v.pb(mp(i, mp(j, k)));
            }
    printf("%d\n", (int)v.size());
    for (auto i : v)
        cout << i.X << " " << i.Y.X << " " << i.Y.Y << endl;
}

int main() {
#ifdef MANGOGAO
    // freopen("data.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/C-small-attempt0.in", "r", stdin);
    // freopen("/Users/Lodour/Downloads/A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int t, cnt = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++cnt);
        // printf("%d\n", solve());
        solve();
    }

    return 0;
}

