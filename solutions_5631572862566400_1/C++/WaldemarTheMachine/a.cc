#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 2000000007
#define y1 uu1
#define y2 uu2
#define hash mash
const double EPS = 1E-12;
const double PI = acos(-1.0);
const LL mod = 1000000007;

using namespace std;

int n;
int a[1005];
int vis[1005];
vector<int> from[1005];

int magic(int idx, int ban) {
	int mx = 0;
	FOR(i, from[idx].size()) {
		if (from[idx][i] != ban)
			mx = max(mx, magic(from[idx][i], ban));
	}
	return 1 + mx;
}

void solve() {
	cin >> n;
	FOR(i,n) {
		from[i].clear();
	}

	FOR(i, n) {
		cin >> a[i];
		a[i]--;
		from[a[i]].push_back(i);
	}

	int bst = 0;
	FOR(i,n) {
		CLEAR(vis);
		int idx = i;
		int cnt = 0;
		while (!vis[idx]) {
			vis[idx] = 1;
			idx = a[idx];
			cnt++;
		}
		if (idx == i)
			bst = max(bst, cnt);
	}

	CLEAR(vis);
	int sum = 0;
	FOR(i,n) {
		if (a[a[i]] == i && !vis[i] && !vis[a[i]]) {
			vis[i] = 1;
			vis[a[i]] = 1;
			sum += magic(i,a[i]) + magic(a[i],i);
		}
	}

	bst = max(bst, sum);

	cout << bst << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  int tt;
  cin >> tt;

  FOR(t,tt) {
  	cout << "Case #" << t+1 << ": ";
  	solve();
  }

  return 0;
}
