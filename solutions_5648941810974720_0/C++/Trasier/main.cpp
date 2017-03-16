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

// #define DEBUG

const int maxn = 2005;
char s[maxn];
int C[26];
string dts[10] = {
	"ZERO", "ONE", "TWO", "THREE", 
	"FOUR", "FIVE", "SIX", "SEVEN", 
	"EIGHT", "NINE"
};
int cnt[10];

void solve() {
	int len = strlen(s);
	
	memset(C, 0, sizeof(C));
	rep(i, 0, len) C[s[i]-'A']++;
	
	memset(cnt, 0, sizeof(cnt));
	cnt[0] = C['Z'-'A'];
	cnt[6] = C['X'-'A'];
	cnt[8] = C['G'-'A'];
	cnt[3] = C['H'-'A'] - C['G'-'A'];
	cnt[7] = C['S'-'A'] - C['X'-'A'];
	
	cnt[2] = C['T'-'A'] - C['H'-'A'];
	cnt[4] = C['R'-'A'] - cnt[3] - cnt[0];
	cnt[1] = C['O'-'A'] - cnt[0] - cnt[2] - cnt[4];
	#ifdef DEBUG
	assert((C['N'-'A'] - cnt[1] - cnt[7])%2 == 0);
	#endif
	cnt[9] = (C['N'-'A'] - cnt[1] - cnt[7])/2;
	cnt[5] = C['I'-'A'] - cnt[6] - cnt[8] - cnt[9];
	
	rep(i, 0, 10) {
		#ifdef DEBUG
		assert(cnt[i] >= 0);
		#endif
		while (cnt[i]--)
			putchar(i + '0');
	}
	putchar('\n');
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
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
	
	#ifdef DEBUG
		printf("time = %ldms.\n", clock());
	#endif
	
	return 0;
}
 