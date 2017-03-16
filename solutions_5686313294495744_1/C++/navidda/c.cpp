#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 2000 + 10;

int match[3][MAXN];
bool mark[MAXN];
vector<int> adj[MAXN];
int n, m, p;

bool dfs(int x) {
	if (mark[x]) return false;

	mark[x] = true;
	for (int i = 0; i < SZ(adj[x]); i ++) {
		int v = adj[x][i];
		if (match[1][v] == -1 || dfs(match[1][v])) {
			match[0][x] = v;
			match[1][v] = x;
			return true;
		}
	}
	return false;
}


void bi_match() {
	CLR(match, -1);
	for (int i = 0; i < n; i ++) {
		CLR(mark, 0);
		bool check = false;
		for (int j = 0; j < n; j ++)
			if (!mark[j] && match[0][j] == -1)
				check |= dfs(j);
		if (!check) break;
	}
}
/*
bool mk[MAXN], color[MAXN];
int label[MAXN];
vector <int> tadj[MAXN];
void dfs1(int v, bool cl = 0) {
	color[v] = cl;
	mk[v] = 1;
	for (int i = 0; i < SZ(tadj[v]); i++) {
		int u = tadj[v][i];
		if (!mk[u])
			dfs1(u, !cl);
	}
}
*/
int main () {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> p;
		set <string> n1, n2;
		vector <pair<string, string> > edges;
		for (int i = 0; i < p; i ++) {
			string a, b;
			cin >> a >> b;
			edges.pb(mp(a, b));
			n1.insert(a);
			n2.insert(b);
		}
		n = SZ(n1);
		m = SZ(n2);
		for (int i = 0; i < n + m; i++)
			adj[i].clear();
		map <string, int> mp1, mp2;
		int tempid = 0;
		FOREACH(it, n1)
			mp1[*it] = tempid ++;
		FOREACH(it, n2)
			mp2[*it] = tempid ++;
		for (int i = 0; i < SZ(edges); i++) {
			adj[mp1[edges[i].X]].pb(mp2[edges[i].Y]);
			adj[mp2[edges[i].Y]].pb(mp1[edges[i].X]);
		}
		/*
		for (int i = 0; i < N; i++) {
			cout << i << " : ";
			for (int j = 0; j < SZ(adj[i]); j++)
				cout << adj[i][j] << " , ";
			cout << endl;
		}
		*/
		bi_match();
		int ans = 0;
		FOR(i, n) ans += (match[0][i] != -1);
		cout << "Case #" << t << ": ";
		cout << p + ans - n - m << endl;
	}
	return 0;
}
