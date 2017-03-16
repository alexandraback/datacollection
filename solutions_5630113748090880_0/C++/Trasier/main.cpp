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
const int maxn = 110;
const int maxm = 2505;
int a[maxn][maxn];
int c[maxm];
int n;

void solve() {
	memset(c, 0, sizeof(c));
	rep(i, 0, n+n-1)
		rep(j, 0, n)
			++c[a[i][j]];
	vi ans;
	rep(i, 1, maxm) {
		if (c[i] & 1)
			ans.pb(i);
	}
	
	#ifdef LOCAL_DEBUG
	assert(SZ(ans) == n);
	#endif
	rep(i, 0, n) {
		if (i == 0)
			printf("%d", ans[i]);
		else
			printf(" %d", ans[i]);
	}
	putchar('\n');
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef LOCAL_DEBUG
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
	
	int t;
	
	cin >> t;
	rep(tt, 1, t+1) {
		cin >> n;
		rep(i, 0, n+n-1)
			rep(j, 0, n)
				cin >> a[i][j];
		printf("Case #%d: ", tt);
		solve();
	}
	
	#ifdef LOCAL_DEBUG
		// printf("time = %ldms.\n", clock());
	#endif
	
	return 0;
}
