#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 1010;
int a[N][2];
map<string, int> mp1, mp2;
int idx1, idx2;
int getIdx1(string s) {
	if (mp1.find(s) == mp1.end()) {
		mp1[s] = idx1++;
	}
	return mp1[s];
}
int getIdx2(string s) {
	if (mp2.find(s) == mp2.end()) {
		mp2[s] = idx2++;
	}
	return mp2[s];
}

int _n, _m;
int mp[N][N], matx[N], maty[N]; bool fy[N];

int path(int u) {
  rep(v, _m) if (mp[u][v] && !fy[v]) {
    fy[v] = 1;
    if (!~maty[v] || path(maty[v])) {
      matx[u] = v, maty[v] = u;
      return 1;
    }
  }
  return 0;
}
int hungary() {
  int ret = 0;
  clr(matx, 0xff), clr(maty, 0xff);
  rep(i, _n) if (!~matx[i]) {
    clr(fy, 0);
    ret += path(i);
  }
  return ret;
}

int main() {
	freopen("C-large.in", "r", stdin);
	//freopen("C-small-attempt0.in", "r", stdin);
	freopen("c-ans-large", "w", stdout);
	int T, ca = 1;
	string s1, s2;
	for (scanf("%d", &T); T--; ) {
		int n; cin >> n;
		idx1 = 0; mp1.clear();
		idx2 = 0; mp2.clear();
		int ans = 0;
		clr(mp, 0);
		rep(i, n) {
			cin >> s1 >> s2;
			a[i][0] = getIdx1(s1);
			a[i][1] = getIdx2(s2);
			mp[a[i][0]][a[i][1]] = 1;
		}
		_n = idx1, _m = idx2;
		int ret = hungary();
		ret = idx1 + idx2 - ret;
		
		ans = n - ret;
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}


