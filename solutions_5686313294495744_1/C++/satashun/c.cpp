#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

//bipartite matching
const int MAX_V = 2010;
int V; 
vector<int> g[MAX_V];
int match[MAX_V];
bool used[MAX_V];

inline void add_edge(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

bool dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
	int u = g[v][i], w = match[u];
	if (w < 0 || (!used[w] && dfs(w))) {
	    match[v] = u;
	    match[u] = v;
	    return true;
	}
    }
    return false;
}

int bipartite_matching()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; ++v) {
	if (match[v] < 0) {
	    memset(used, 0, sizeof(used));
	    res += dfs(v);
	}
    }
    return res;
}

int TC;
int N;
string _l[1010], _r[1010];
int l[1010], r[1010];

map<string, int> Tl, Tr;
int c1, c2;

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d: ", tc);
	Tl.clear();
	Tr.clear();

	c1 = c2 = 0;
	rep(i, 2010) g[i].clear();

	cin >> N;

	rep(i, N) {
	    cin >> _l[i] >> _r[i];
	    if (!Tl.count(_l[i])) Tl[_l[i]] = c1++;
	    if (!Tr.count(_r[i])) Tr[_r[i]] = c2++;
	    l[i] = Tl[_l[i]];
	    r[i] = Tr[_r[i]];
	}

	V = c1 + c2;
	rep(i, N) add_edge(l[i], r[i] + c1);
	int m = bipartite_matching();
	cout << N - (V - m) << endl;
    }

    return 0;
}
