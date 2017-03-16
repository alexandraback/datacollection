#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <iterator>
#include <functional>
#include <limits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <complex>
using namespace std;
#define LT(i) ((i) << 1)
#define RT(i) (((i) << 1) | 1)
#define MID(i) ((l[i] + r[i]) >> 1)
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
typedef pair<int, int> PII;
template<class T> void string_reader(string s, vector<T>& vec){
	istringstream sin(s);
	copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
const int N   = 10;
const int INF = 10000000;
pair<int, int> p[N];
int dp[1 << N][1 << N];
bool chk[1 << N][1 << N];
int countbit(int x)
{
	int res = 0;
	for(int i = 0;i < N;i++) res += (x & (1 << i)) != 0;
	return res;
}
int DP(int a, int b, int n)
{
	if(a == 0 && b == 0) {
		return dp[a][b] = 0;
	} else if(chk[a][b]) {
		return dp[a][b];
	}
	chk[a][b] = true;
	for(int i = 0;i < n;i++) {
		int bit = (1 << i);
		if((a & bit) && (b & bit)) {
			int pa = a ^ bit;
			int pb = b ^ bit;
			int cnt = countbit(pa) + countbit(pb);
			if(cnt >= p[i].second) {
				checkmin(dp[a][b], DP(pa, pb, n) + 1);
			}
			cnt = countbit(a) + countbit(pb);
			if(cnt >= p[i].second) {
				checkmin(dp[a][b], DP(a, pb, n) + 1);
			}
		}
		if((a & bit) && (b & bit) == 0) {
			int pa = a ^ bit;
			int pb = b;
			int cnt = countbit(pa) + countbit(pb);
			if(cnt >= p[i].first) {
				checkmin(dp[a][b], DP(pa, pb, n) + 1);
			}
		}
	}
	return dp[a][b];
}
int main()
{
	int t, n;
	scanf("%d", &t);
	REP(cas, 0, t)
	{
		scanf("%d", &n);
		REP(i, 0, n)
		{
			scanf("%d %d", &p[i].first, &p[i].second);
		}
		sort(p, p + n);
		memset(chk, 0, sizeof(chk));
		REP(i, 0, (1 << n)) fill(dp[i], dp[i] + (1 << n), INF);
		int res = DP((1 << n) - 1, (1 << n) - 1, n);
		if(res == INF)
			printf("Case #%d: Too Bad\n", cas + 1);
		else
			printf("Case #%d: %d\n", cas + 1, res);
	}
	return 0;
}
