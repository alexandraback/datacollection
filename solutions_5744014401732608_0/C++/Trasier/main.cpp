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

typedef long long LL;
const int maxn = 55;
int n;
LL M;
char s[maxn][maxn];

void dfs(LL M, LL bound, int b) {
	if (M == bound)	return ;
	
	if (M == bound+1) {
		s[0][n-1] = '0';
		return ;
	}
	
	LL half = bound >> 1;
	if (M <= half) {
		s[b][n-1] = '0';
	} else {
		M -= half;
	}

	dfs(M, half, b-1);
}

void solve() {
	int k = n - 2;
	
	LL bound = 1LL << k;

	if (M > bound) {
		puts("IMPOSSIBLE");
		return;
	}

	memset(s, '0', sizeof(s));
	rep(i, 0, n) s[i][n] = '\0';
	rep(i, 0, n) {
		rep(j, i+1, n) {
			s[i][j] = '1';
		}
		s[i][n-1] = '0';
	}
	
	s[0][n-1] = '1';
	--M;
	for (int i=0,j=1; i<k; ++i,++j) {
		if (M & (1LL<<i)) {
			s[j][n-1] = '1';
		}
	}
	puts("POSSIBLE");
	rep(i, 0, n)
		puts(s[i]);
}

int main() {
	ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		// freopen("data.in", "r", stdin);
		// freopen("data.out", "w", stdout);
	#endif

	int t;

	cin >> t;
	rep(tt, 1, t+1) {
		cin >> n >> M;
		printf("Case #%d: ", tt);
		solve();
	}

	#ifndef ONLINE_JUDGE
		// printf("time = %ldms.\n", clock());
	#endif

	return 0;
}
