#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))


using namespace std;

const int maxe = 2016;
const int maxv = 2016;

struct HopcroftKarp {
    int nx, ny, E, adj[maxe], next[maxe], last[maxv], run[maxv], level[maxv], que[maxv], matx[maxv], maty[maxv];

    void init(int _nx, int _ny) {
        nx = _nx; ny = _ny;
        E = 0; ms(last, -1);
        ms(matx, -1); ms(maty, -1);
    }

    void add(int x, int y) {
        adj[E] = y; next[E] = last[x]; last[x] = E++;
    }

    bool bfs() {
        int qsize = 0;

        For(x, 1, nx) if (matx[x] != -1) level[x] = -1;
        else {
            level[x] = 0;
            que[qsize++] = x;
        }

        bool found = false;

        Rep(i, qsize) {
            for (int x = que[i], e = last[x]; e != -1; e = next[e]) {
                int y = adj[e];
                if (maty[y] == -1) found = true;
                else if (level[maty[y]] == -1) {
                    level[maty[y]] = level[x] + 1;
                    que[qsize++] = maty[y];
                }
            }
        }

        return found;
    }

    int dfs(int x) {
        for (int &e = run[x]; e != -1; e = next[e]) {
            int y = adj[e];
            if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y]))) {
                matx[x] = y;
                maty[y] = x;
                return 1;
            }
        }
        return 0;
    }

    int maxmat() {
        int total = 0;

        while (bfs()) {
            For(x, 1, nx) run[x] = last[x];
            For(x, 1, nx) if (matx[x] == -1) total += dfs(x);
        }

        return total;
    }
} hopkarp;

const int nm = 2016;

int m, n;
string a[nm], b[nm];

void solve(int test) {
	cout << "Case #" << test << ": ";
	map<string, int> cs, cs2;
	cin >> m;
	int nx = 0, ny = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
		if (!cs[a[i]])
			cs[a[i]] = ++nx;
		if (!cs2[b[i]])
			cs2[b[i]] = ++ny;
	}
	hopkarp.init(nx, ny);
	for (int i = 1; i <= m; ++i)
		hopkarp.add(cs[a[i]], cs2[b[i]]);
	cout << m - (nx + ny) + hopkarp.maxmat() << "\n";
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve(i);
}
