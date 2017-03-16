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
LL st = (1<<15) + 1;
LL ed = (1<<16) - 1;
char s[maxl];
LL fact[13];
int n, J;

inline LL getValue(int base) {
	LL ret = 0;
	int i = 0;
	
	while (s[i]) {
		ret = ret * base + s[i]-'0';
		++i;
	}
	return ret;
}

bool judge() {
	LL tmp, j;
	bool flag;
	
	rep(i, 2, 11) {
		tmp = getValue(i);
		flag = false;
		LL bound = sqrt(tmp + .5);
		for (j=2; j<=bound; ++j) {
			if (tmp%j == 0) {
				fact[i] = j;
				flag = true;
				break;
			}
		}
		if (!flag)	return false;
	}
	
	return true;
}

inline void lltos(LL val) {
	int l = 0;
	
	while (val) {
		s[l++] = (val & 1) + '0';
		val >>= 1;
	}
	s[l] = '\0';
	reverse(s, s+l);
}

void solve() {
	int cnt = 0;
	
	for (LL i=st; i<=ed; i+=2) {
		lltos(i);
		if (judge()) {
			printf("%s", s);
			rep(i, 2, 11)
				printf(" %d", (int)fact[i]);
			putchar('\n');
			if (++cnt == J)
				break;
		}
	}
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
		printf("time = %ldms.\n", clock());
	#endif
	
	return 0;
}
