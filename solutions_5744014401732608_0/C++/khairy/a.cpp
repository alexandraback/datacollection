#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple // you can ignore
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vi v[7];

int cnt(int i, int snk) {
	if (i == snk)
		return 1;
	int res = 0;
	for (auto j : v[i]) {
		res += cnt (j, snk);
	}
	return res;
}

int main() {
  freopen("test.in", "rt", stdin);
  freopen("o.txt", "wt", stdout);
  int t;
  scanf ("%d", &t);
  FOR (cs, 1, t + 1) {
	  int n, m;
	  scanf ("%d%d", &n, &m);
	  vpi edges;
	  FOR (i , 0 , n)
		  FOR (j , i + 1, n)
			  edges.eb(i, j);
	  int si = sz(edges);
	  FOR (msk , 0 , (1 << si)) {
		  FOR (i , 0 , n)
			v[i].clear();
		  FOR (i , 0 , si) {
			  if ((msk >> i) & 1) {
				  v[edges[i].first].eb(edges[i].second);
			  }
		  }
		  if (cnt(0, n - 1) == m) {
			  printf ("Case #%d: POSSIBLE\n", cs);
			  int mat[7][7];
			  mem (mat, 0);
			  FOR (i , 0 , n) {
				  for (auto j : v[i]) {
					  mat[i][j] = 1;
				  }
			  }
			  FOR (i , 0 , n) {
			  	  FOR (j , 0 , n)
				  	  printf ("%d", mat[i][j]);
			  	  printf ("\n");
			  }
			  goto yes;
		  }
	  }
	  printf ("Case #%d: IMPOSSIBLE\n", cs);
	  yes:;
  }
  return 0;
}
