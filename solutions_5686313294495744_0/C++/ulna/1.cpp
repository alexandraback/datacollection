#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <cctype>
#include <utility>
#include <cassert>
#include <ctime>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define buli(x) __builtin_popcountll(x)
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define iter(c) __typeof((c).begin())
#define tr(c,i) for (iter(c) i=(c).begin();i!=(c).end();i++)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)
#define repl(i,s,e) for (int (i)=(s);(i);i=e[i])

#define TASK "C-small-attempt0 (1)"

int n;
string a[1055], b[1055];
int match[2055];
bool used[2055];
vector<int> g[2055];
map<string, int> c, d;
        
bool dfs(int v) {
 	used[v] = true;
	for (auto u : g[v]) {
	 	int w = match[u];

		if (w < 0 || !used[w] && dfs(w)) {
		 	match[u] = v;
			match[v] = u;
			return true;
		}
	}

	return false;
}                                                           
int main() {
	#ifdef home
		freopen(TASK".in","r",stdin);
		freopen(TASK".out","w",stdout);
	#endif 

	int t;

	scanf("%d", &t);

	for (int _t = 0; _t < t; _t++) {
	 	scanf("%d", &n);

		c.clear(), d.clear();

		int e = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			if (c.find(a[i]) == c.end()) c[a[i]] = e++;
			if (d.find(b[i]) == d.end()) d[b[i]] = e++;
		}

		for (int i = 0; i < e; i++) g[i].clear();

		for (int i = 0; i < n; i++) {
		 	g[c[a[i]]].emplace_back(d[b[i]]);
			g[d[b[i]]].emplace_back(c[a[i]]);
		}

		int res = 0;

		clr(match, -1);

		for (int i = 0; i < e; i++) {
		 	if (match[i] == -1) {
				clr(used, false);
		 	 	if (dfs(i)) {
		 	 	 	res++;
				}
			}
		}

		printf("Case #%d: %d\n", _t + 1, n - e + res);
	}
           
	#ifdef home
		eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif                                                                          
	return 0;
}