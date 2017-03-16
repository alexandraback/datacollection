#pragma comment(linker, "/stack:32000000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

vector<vector<int> > g;
vector<int> used;
vector<int> mt;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

void solve() {
  int m; scanf("%d", &m);
  map<string, int> m1, m2;
  
  g.clear();
  forn(i, m) {
    string s1, s2; cin >> s1 >> s2;
    if (m1.count(s1) == 0) m1[s1] = sz(m1), g.pb(vector<int>());
    if (m2.count(s2) == 0) m2[s2] = sz(m2);
    g[m1[s1]].pb(m2[s2]);
  }

  mt.assign(sz(m2), -1);
  used.assign(sz(m1), false);
  int cc = 0;
  for (int v=0; v<sz(m1); ++v) {
		used.assign (sz(m1), false);
		cc += try_kuhn (v);
	}
  int ans = m - (sz(m1) + sz(m2) - cc);
  printf("%d\n", ans);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  int T; scanf("%d", &T);
  for (int tn = 1; tn <= T; ++tn) {
    printf("Case #%d: ", tn);
    solve();
  }
	return 0;
}