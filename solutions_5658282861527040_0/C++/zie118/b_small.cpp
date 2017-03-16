#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


#define PB push_back
#define MP make_pair

#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORE(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define CLR(s, x) memset(s, x, sizeof(s))

#define inf (1<<29)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int vis[10005];
int sum[10005];
int main()
{
	int T; scanf("%d", &T);
	int cc=0;
	int A, B, K;
	while (T--) {
		scanf ("%d %d %d", &A, &B, &K);
		CLR(vis, 0);
		CLR(sum, 0);
		FOR(i,0,A) FOR(j,0,B) {
			vis[i&j]++;
		}
		int ans = 0;
		FOR(i,0,K) sum[i] = sum[i-1] + vis[i];
		ans = sum[K-1];
		printf ("Case #%d: %d\n", ++cc, ans);
	}
	return 0;
}
