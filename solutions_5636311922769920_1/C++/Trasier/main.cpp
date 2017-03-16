/*  */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti				set<int>
#define stpii			set<pair<int, int> >
#define mpii			map<int,int>
#define vi				vector<int>
#define pii				pair<int,int>
#define vpii			vector<pair<int,int> >
#define rep(i, a, n) 	for (int i=a;i<n;++i)
#define per(i, a, n) 	for (int i=n-1;i>=a;--i)
#define clr				clear
#define pb 				push_back
#define mp 				make_pair
#define fir				first
#define sec				second
#define all(x) 			(x).begin(),(x).end()
#define SZ(x) 			((int)(x).size())
#define lson			l, mid, rt<<1
#define rson			mid+1, r, rt<<1|1
#define INF				0x3f3f3f3f
#define mset(a, val)	memset(a, (val), sizeof(a))

// #define LOCAL_DEBUG
typedef long long LL;
int K, C, S;

LL Pow(LL base, int n) {
	LL ret = 1;

	while (n) {
		if (n & 1)
			ret *= base;
		base *= base;
		n >>= 1;
	}
	return ret;
}

void solve() {
	if (C == 1) {
		if (S < K) {
			cout << " IMPOSSIBLE" << "\n";
		} else {
			rep(i, 1, K+1)
				cout << " " << i;
			cout << "\n";
		}

		return ;
	}

	if (K <= 1) {
		if (S < K) {
			cout << " IMPOSSIBLE" << "\n";
		} else {
			rep(i, 1, K+1)
				cout << " " << i;
			cout << "\n";
		}

		return ;
	}

	int mn = (K + 1) >> 1;

	if (S < mn) {
		cout << " IMPOSSIBLE" << "\n";
		return ;
	}

	vector<LL> ans;
	LL delta = Pow(K, C-1), ed = delta * K;
	LL l = 2, r = ed - 1;
	int cnt = 0;

	delta += delta;
	while (cnt < mn) {
		if (cnt < mn) {
			ans.pb(l);
			l += delta;
			l += 2;
			++cnt;
		}
		if (cnt < mn) {
			ans.pb(r);
			r -= delta;
			r -= 2;
			++cnt;
		}
	}

	int sz = SZ(ans);
	#ifdef LOCAL_DEBUG
	assert(sz == mn);
	#endif
	rep(i, 0, sz) {
		#ifdef LOCAL_DEBUG
		assert(ans[i]>=1 && ans[i]<=ed);
		#endif
		cout << " " << ans[i];
	}
	cout << "\n";

	#ifdef LOCAL_DEBUG
	sort(all(ans));
	int m = unique(all(ans)) - ans.begin();
	assert(m == sz);
	#endif
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef LOCAL_DEBUG
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif

	int t;

	scanf("%d", &t);
	rep(tt, 1, t+1) {
		scanf("%d%d%d", &K, &C, &S);
		cout << "Case #" << tt << ":";
		solve();
	}


	#ifdef LOCAL_DEBUG
		//printf("time = %ldms.\n", clock());
	#endif

	return 0;
}
