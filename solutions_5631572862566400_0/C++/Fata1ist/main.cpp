#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1111;

int T;
int n, sumBlocks, maxH, ans;
int p[MAXN], used[MAXN];
vi g[MAXN];

void init() {
	memset(used, 0, sizeof(used));
	forn(i, n)
		g[i].clear();		
}

void dfs(int v, int h) {
	//cerr << "dfs: " << v << endl;
	
	used[v] = 1;
	maxH = max(maxH, h);
	for (auto w: g[v])
		dfs(w, h + 1);	
}

int main() {
	
	cin >> T;
	forn(tt, T) {
		printf("Case #%d: ", tt + 1);
		
		cin >> n;
		
		init();
		
		forn(i, n) {
			cin >> p[i];
			p[i]--;
			assert(i != p[i]);
			g[p[i]].pb(i);	
		}
		
		sumBlocks = 0;
		/*
		cerr << "g: \n";
		forn(i, n)
			for (auto j: g[i])
				cerr << i << " -> " << j << endl;
		*/		
		forn(i, n)
			forn(j, n)
				if (i != j && !used[i] && !used[j] && p[i] == j && p[j] == i) { //shmatok
					//cerr << i << ' ' << j << endl;
					
					used[i] = 1;
					used[j] = 1;
					
					bool erased;
					erased = 0;
					forn(k, g[i].size())
						if (g[i][k] == j) {
							swap(g[i][k], g[i].back());
							g[i].pop_back();
							erased = 1;
							break;		
						}
						
					assert(erased);
					
					erased = 0;
					forn(k, g[j].size())
						if (g[j][k] == i) {
							swap(g[j][k], g[j].back());
							g[j].pop_back();
							erased = 1;
							break;		
						}
					
					assert(erased);
					
					maxH = 0;
					dfs(i, 1);
					sumBlocks += maxH;
					
					maxH = 0;
					dfs(j, 1);
					sumBlocks += maxH;
				}
		
		ans = sumBlocks;
		
		forn(i, n) {
			if (!used[i]) {
				int iter = 1;
				int v = p[i];
				
				while (iter < 3 * n && v != i) {
					iter++;
					v = p[v];
				}
				
				if (iter < 3 * n) {
					assert(iter != 1 && iter != 2);
					ans = max(ans, iter);	
				}
			}
		}
		
		cout << ans << '\n';		
	}
	
	return 0;
}                  