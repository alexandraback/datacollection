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


void dfs(string s, VI&a, int cnt, int len) {
    if ((int)s.size() == len) {
        a.pb(cnt);
        return;
    }
    if (s[len] == '?')
        for (int i = 0; i < 10; i++)
            dfs(s, a, cnt * 10 + i, len + 1);
    else
        dfs(s, a, cnt * 10 + (s[len] - '0'), len + 1);
}

void solve(string s, string t) {
    VI a, b;
    dfs(s, a, 0, 0);
    dfs(t, b, 0, 0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int min = inf;
    PII res;
    for (int i = 0; i < (int)a.size(); i++)
        for (int j = 0; j < (int)b.size(); j++)
            if (abs(a[i] - b[j]) < min) {
                min = abs(a[i] - b[j]);
                res = mp(a[i], b[j]);
            }
    stringstream ss;
    ss << res.X << " " << res.Y;
    string t1, t2;
    ss >> t1 >> t2;
    int l1 = abs((int)t1.size() - (int)s.size());
    int l2 = abs((int)t2.size() - (int)t.size());
    for (int i = 0; i < l1; i++)
        t1 = '0' + t1;
    for (int i = 0; i < l2; i++)
        t2 = '0' + t2;
    cout << t1 << " " << t2 << endl;
}


int main() {
#ifdef MANGOGAO
    // freopen("data.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/B-small-attempt0.in", "r", stdin);
    // freopen("/Users/Lodour/Downloads/A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif


    fastcin;
    int t, cnt = 0;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        cout << "Case #" << ++cnt << ": ";
        solve(s, t);
    }

    return 0;
}

