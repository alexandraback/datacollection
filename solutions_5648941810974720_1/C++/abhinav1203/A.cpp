#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
int cnt[256], cnt2[10];
char str[2005];
int main()
{
	int T, test, i, len;
	scanf("%d", &T);
	for (test=1; test<=T; test++) {
		scanf("%s", str);
		len = strlen(str);
		memset(cnt, 0, sizeof(int)*256);
		for (i=0; i<len; i++) {
			cnt[str[i]]++;
		}
		cnt2[0] = cnt['Z'];
		cnt2[2] = cnt['W'];
		cnt2[3] = cnt['H']-cnt['G'];
		cnt2[6] = cnt['X'];
		cnt2[7] = cnt['S']-cnt['X'];
		cnt2[8] = cnt['G'];
		cnt2[5] = cnt['V']-cnt2[7];
		cnt2[4] = cnt['F']-cnt2[5];
		cnt2[1] = cnt['O']-cnt2[0]-cnt2[2]-cnt2[4];
		cnt2[9] = cnt['I']-cnt2[5]-cnt2[6]-cnt2[8];
		// cnt2[1] = cnt['O']-cnt['W']+cnt['H']-cnt['G'];
		// cnt2[2] = cnt['W'];
		// cnt2[3] = cnt['H'] - cnt['G'];
		// cnt2[4] = cnt['R'] - cnt['Z'] + cnt['H'] - cnt['G'];
		// cnt2[5] = cnt['V'] - cnt['S'] + cnt['X'];
		// cnt2[6] = cnt['X'];
		// cnt2[7] = cnt['S'] - cnt['X'];
		// cnt2[8] = cnt['G'];
		// cnt2[9] = cnt['I'] - cnt['V'] + 2*cnt['X'] - cnt['G'];
		printf("Case #%d: ", test);
		for (i=0; i<=9; i++) {
			while (cnt2[i]--) {
				printf("%d",i);
			}
		}
		printf("\n");

	}
    return 0;
}