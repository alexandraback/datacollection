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
const int maxl = 105;
char s[maxl];
int a[maxl];
// int dp[maxl];

int dfs(int dep, int d) {
	if (dep == 0)	return a[dep]==d ? 0:1;
	
	return (a[dep]==d) ? dfs(dep-1, d) : dfs(dep-1, d^1) + 1;
}

void solve() {
	int n = strlen(s);
	
	rep(i, 0, n)	a[i] = (s[i]=='+') ? 0:1;
	
	int ans = dfs(n-1, 0);
	printf("%d\n", ans);
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
		scanf("%s", s);
		printf("Case #%d: ", tt);
		solve();
	}
	
	#ifdef LOCAL_DEBUG
		printf("time = %ldms.\n", clock());
	#endif
	
	return 0;
}
