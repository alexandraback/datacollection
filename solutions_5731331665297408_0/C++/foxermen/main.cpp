#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <list>
#include <ctime>

#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> lint;

const int N = (int)(1e2) + 7;
const ll MD = 1000000000;
const int KOL = 9;
const int M = (int)(1e6) + 7;
const ll INF = (ll)(1e9) + 7;
const ll MOD = (ll)(1e9) + 7;
const ld eps = 1e-12;

vector<int> a[N];
vector<int> b[N];
set<int> ss[N];
string s[N];
int n, m, iii;
int w[10];
int mark[10];

void dfs(int v)
{
    mark[v] = 1;
    if (v == w[iii] - 1)
        ++iii;
    if (iii >= n)
        return ;
    for (int i = 0; i < a[v].size(); ++i)
        if (!b[v][i] && ss[a[v][i]].find(v) == ss[a[v][i]].end() && a[v][i] == w[iii] - 1)
        {
            b[v][i] = 1;
            ss[v].insert(a[v][i]);
            dfs(a[v][i]);
            i = 0;
        }
}

bool ok()
{
    for (int i = 0; i < N; ++i)
    {
        b[i].clear();
        for (int j = 0; j < a[i].size(); ++j)
            b[i].pb(0);
        ss[i].clear();
    }
    for (int i = 0; i < 10; ++i)
        mark[i] = 0;
    iii = 0;
    dfs(w[0] - 1);
    bool f = 0;
    for (int i = 0; i < n; ++i)
        if (!mark[i])
            f = 1;
    return !f;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int ii = 1; ii <= tt; ++ii)
    {
        for (int i = 0; i < N; ++i)
            a[i].clear();
        cin >> n >> m;
        string res = "";
        for (int i = 0; i < n * 5; ++i)
            res += "a";
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            a[x].pb(y);
            a[y].pb(x);
        }
        for (int i = 0; i < n; ++i)
            w[i] = i + 1;
        int kol = 0;
        do
        {
            if (ok())
            {
                string rr = "";
                for (int i = 0; i < n; ++i)
                    rr += s[w[i] - 1];
                res = min(res, rr);
            }
        } while (next_permutation(w, w + n));
        printf("Case #%d: ", ii);
        cout << res << endl;
    }
    return 0;
}
