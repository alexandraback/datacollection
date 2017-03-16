#include <bits/stdc++.h>

using namespace std;
                                                                          	
#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file ""     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <ll, ll> PII;
typedef double ld;
                                                                                          
const int N = 2e3; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vector <int> cycle;
int in_c[N], to[N];            
int u[N], d[N], p[N];

void dfs(int x) {
	if (u[x] == 2) return;
	if (u[x] == 1) {
		cycle.pb(x);
		u[x] = 2;
		dfs(to[x]);
		return;
	}                 	
	u[x] = 1;
	dfs(to[x]);
	u[x] = 2;
}

int dp(int x) {
	if (x == 0) return -INF;
	if (u[x]) return d[x];
	u[x] = 1;
	d[x] = dp(to[x]) + 1;
	p[x] = p[to[x]];
	return d[x];
}

void del(int x) {
	if (x == 0 || to[to[x]] == x) return;
	//cerr << x << "\n";
	int s = to[x];
	to[x] = 0;
	del(s);
}
           
int main () {
#ifdef machine42
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
#endif		
	ios_base :: sync_with_stdio (0);
	cin.tie(0);

	int tests;
	cin >> tests;
	forn(test, 1, tests) {
		cout << "Case #" << test << ": ";
	//	cerr << "Case #" << test << ":\n";
		int n;
		cin >> n;
		forn(i, 1, n)
			cin >> to[i];
		vector <int> ge;
		int ans = 0;
		forn(i, 1, n) {
			memset(u, 0, sizeof(u));
			cycle.clear();
			dfs(i);
			if (find(cycle.begin(), cycle.end(), i) == cycle.end()) continue;
		    ans = max(ans, (int)cycle.size());
			if ((int)cycle.size() == 2) 
				if (i < to[i]) ge.pb(i);
			if ((int)cycle.size() > 2) {     
				for (auto x : cycle)
					in_c[x] = 1;			
			}
		}
		forn(i, 1, n)
			if (in_c[to[i]]) to[i] = 0;	
		int mrg = 0;                       
		while (ge.size()) {
			memset(u, 0, sizeof(u));
			for (auto x : ge) {
				u[x] = 1, u[to[x]] = 1;
				d[x] = 1, d[to[x]] = 1;
				p[x] = x, p[to[x]] = to[x];
			}                            
			int at = -1;
			forn(i, 1, n)
				if (at == -1 || dp(i) > dp(at))
					at = i;
			if (dp(at) < 1) break;     
			int e = p[at];                       
			mrg += dp(at);
			del(at);	       

			memset(u, 0, sizeof(u));
			for (auto x : ge) 
				u[x] = 1, u[to[x]] = 1;    
			at = -1;
			forn(i, 1, n) {
				if (d[i] > 0 && p[i] == to[e]) {
					if (at == -1 || dp(i) > dp(at))
						at = i;					
				}
			}                  
			mrg += dp(at); 
			del(at);                 
			e = min(e, to[e]);  
			to[to[e]] = 0;
			to[e] = 0;
                                       
			ge.erase(find(ge.begin(), ge.end(), e));
		}                             
		ans = max(ans, mrg);
		cout << ans << "\n";
		memset(u, 0, sizeof(u));
		memset(d, 0, sizeof(d));
		memset(p, 0, sizeof(p));
		memset(in_c, 0, sizeof(in_c));
	//	cerr << "Case #" << test << ":\n";
	}
	
	return 0;         	
}
