#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi gr;
vector<int> mt;
vector<char> used; 
bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<gr[v].size(); ++i) {
		int to = gr[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			mt[v] = to;
			return true;
		}
	}
	return false;
}

int main() {
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    printf("Case #%d: ", test);
    int n;
    cin >> n;
    vs a(n), b(n);
    map<string, int> ma, mb;
    vii e;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      int ia = ma.size(), ib = mb.size();
      if (ma.count(a[i])) ia = ma[a[i]];
      else ma[a[i]] = ia;
      if (mb.count(b[i])) ib = mb[b[i]];
      else mb[b[i]] = ib;
      e.emplace_back(ia, ib);
    }
    gr.clear();
    gr.resize(ma.size() + mb.size());
    for (pii p : e) {
      gr[p.first].push_back(p.second+ma.size());
      gr[p.second+ma.size()].push_back(p.first);
    }
    int res = n - (int)ma.size() - (int)mb.size();
//    cerr << res << ' ' < ma.size() << ' ' << mb.size() << endl;
    mt.assign (gr.size(), -1);
    for (int run = 1; run;) {
      run = 0;
      used.assign(gr.size(), false);
      for (int v=0; v<ma.size(); ++v) if (mt[v] == -1 && try_kuhn(v)) {
        run = 1;
        ++res;
      }
    }
/*    for (int mask = 0; mask < (1 << n); ++mask) {
      set<string> x, y;
      int cnt = 0;
      for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
        x.insert(a[i]);
        y.insert(b[i]);
        ++cnt;
      }
      bool fail = 0;
      for (int i = 0; i < n; ++i) if (!(mask & (1 << i))) {
        if (!x.count(a[i]) || !y.count(b[i])) fail = 1;
      }
      if (!fail) res = max(res, n - cnt);
    }*/
    cout << res << endl;
  }
  return 0;
}
