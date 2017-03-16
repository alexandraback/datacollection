//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vpii;

#define rep(i,a,b) for(auto i=a,i##_n=b;i<i##_n;++i)
#define rrep(i,a,b) for(auto i=b,i##_n=a;i-->i##_n;)

#endif /* CSL_STD_H_ */


/**
 *  Name : std.cpp
 *  Date : 2016年4月16日 上午8:59:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 1010
vi g[N], gg[N];
int v[N], w[N];
int ans;
vpii h;

void dfs(int u, int f, int st, int ww) {
  if (v[u]) {
  	if (ww != w[u]) return;
  	ans = max(ans, st - v[u]);
  	if (st - v[u] == 2) h.push_back(make_pair(u, f));
  	return;
  }
  v[u] = st, w[u] = ww;
  for(auto& v : g[u]) {
  	dfs(v, u, st + 1, ww);
  }
}

int ma, cnt;
void search(int u, int f, int st) {
//  cout << "1: " << u << " " << f << " " << st << endl;
  if (v[u]) return; v[u] = true;
//  cout << "2: " << u << " " << f << " " << st << endl;
  if (st > ma) ma = st;
  for(auto& v : gg[u]) {
//  	cout << "v: " << v << endl;
  	if (v == f) continue;
  	search(v, u, st + 1);
  }
}
void count(int u, int f) {
  ma = 1;
  search(u, f, 1);
  cnt += ma;
  
  ma = 1;
  search(f, u, 1);
  cnt += ma;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ": ";
	int n; cin >> n; 
	rep(i, 1, n+1) g[i].clear(), gg[i].clear();
	rep(i, 1, n+1) { int x; cin >> x; g[i].push_back(x); gg[x].push_back(i); }
//	rep(i, 1, n+1) {
//		cout << "i = " << i << " : ";
//		for(auto& ggi : gg[i])  cout << ggi << " "; cout << endl;
//	}
	
	memset(v, 0x00, sizeof v);
	ans = 1, h.clear();
	int x = 1;
	rep(i, 1, n+1) if (!v[i]) dfs(i, 0, 1, x++);
	
  	memset(v, 0x00, sizeof v);
  	cnt = 0;
	for (auto& p : h) count(p.first, p.second);
	
	cout << max(cnt, ans) << endl;
  }
  return 0;
}

