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
const int maxl = 36;
// map<string,int> tb;
LL st = (1LL<<31) + 1;
LL ed = (1LL<<32) - 1;
char s[maxl];
int fact[9] = {
	3, 2, 5, 2, 7, 2, 3, 2, 11
};
int n, J;

void solve() {
	s[0] = s[31] = '1';
	
	rep(j, 0, J) {
		rep(i, 0, 15) {
			if (j & (1<<i))
				s[(i<<1)+1] = s[(i<<1)+2] = '1';
			else
				s[(i<<1)+1] = s[(i<<1)+2] = '0';
		}
		printf("%s", s);
		rep(i, 0, 9)
			printf(" %d", fact[i]);
		putchar('\n');
		// tb[string(s)] = 1;
	}
	
	#ifdef LOCAL_DEBUG
	// printf("sz = %d\n", SZ(tb));
	#endif
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef LOCAL_DEBUG
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
	
	int t = 1;
	
	scanf("%d", &t);
	rep(tt, 1, t+1) {
		scanf("%d%d", &n,&J);
		printf("Case #%d:\n", tt);
		solve();
	}
	
	#ifdef LOCAL_DEBUG
		// printf("time = %ldms.\n", clock());
	#endif
	
	return 0;
}
