#include <bits/stdc++.h>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

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
#define iter(it,s) for(__typeof(s.begin())it = s.begin();it!=s.end();it++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool vis[1000001];

int rev (int n) {
  int x = 0;
  while (n)
    x *= 10, x += n % 10, n /= 10;
  return x;
}

int bfs (int n) {
  mem (vis, 0);
  queue <int> q;
  q.push(1);
  vis[1] = 1;
  if (n == 1)
    return 0;
  int res = 1;
  while (sz(q)) {
    int si = sz(q);
    while (si --) {
      int cur = q.front();
      q.pop();
      int r = rev (cur);
      if (!vis[r]) {
        if (r == n)
          return res;
        vis[r] = 1;
        q.push(r);
      }
      if (!vis[cur + 1]) {
        if (cur + 1 == n)
          return res;
        vis[cur + 1] = 1;
        q.push(cur + 1);
      }
    }
    res ++;
  }
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a1.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	FOR (cs , 1 , t + 1) {
	  int n;
	  cin >> n;
	  printf ("Case #%d: %d\n", cs, bfs(n) + 1);
	}
	return 0;
}
