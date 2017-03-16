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

#define MX 1010

int V; 
vector<int> G[MX];
vector<int> rG[MX];
vector<int> vs; 

bool vis[MX];
int cmp[MX]; 

void init() {
    rep(i, MX) {
	G[i].clear();
	rG[i].clear();
    }
}

void add_edge(int from, int to)
{
    G[from].pb(to);
    rG[to].pb(from);
}

void dfs(int v)
{
    vis[v] = true;

    for (int to : G[v]) {
	if (!vis[to]) dfs(to);
    }

    vs.push_back(v);
}

void rdfs(int v, int k)
{
    vis[v] = true;
    cmp[v] = k;

    for (int to : rG[v]) {
	if (!vis[to]) rdfs(to, k);
    }
}

int scc()
{
    memset(vis, 0, sizeof(vis));

    vs.clear();
    rep(v, V) if (!vis[v]) dfs(v);

    memset(vis, 0, sizeof(vis));

    int k = 0;
    reverse(ALL(vs));

    for (int v : vs) if (!vis[v]) rdfs(v, k++);

    return k;
}

int TC;
int N;
int ret;
int to[1010];

int dp[1010];
vi ng[1010];
bool us[1010];
int in[1010];

void DFS(int v)
{
    for (int to : ng[v]) {
	us[cmp[to]] = 1;
	DFS(to);

	dp[v] = max(dp[v], dp[to] + 1);
    }
}

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d: ", tc);
	ret = 0;

	init();

	cin >> N;
	rep(i, N) {
	    cin >> to[i];
	    --to[i];
	    add_edge(i, to[i]);
	}

	V = N;
	scc();

	rep(i, N) ng[i].clear();
	memset(in, 0, sizeof(in));
	memset(us, 0, sizeof(us));	
	memset(dp, 0, sizeof(dp));

	rep(i, N) {
	    if (cmp[i] != cmp[to[i]]) {
		ng[to[i]].pb(i);
		++in[i];
	    }
	}

	rep(i, N) if (!in[i]) {
	    DFS(i);
	}

	int c0 = 0;

	rep(i, N) if (!us[cmp[i]] && cmp[i] == cmp[to[i]]) {
	    int tmp = 0;

	    int cur = to[i];

	    vi vec;
	    vec.pb(i);

	    while (true) {
		vec.pb(cur);
		cur = to[cur];

		if (cur == i) break;
	    }

	    reverse(ALL(vec));

	    us[cmp[i]] = 1;

	    int sz = vec.size();

	    ret = max(ret, sz); //cycle

	    if (sz == 2) {
		tmp = max(tmp, dp[vec[0]] + dp[vec[1]] + 2);
	    }

	    ret = max(ret, tmp);
	    c0 += tmp;
	}

	printf("%d\n", max(ret, c0));
    }

    return 0;
}
