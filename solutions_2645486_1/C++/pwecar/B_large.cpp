#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>

#define Fill(x,y) memset(x, y, sizeof(x))
#define Cpy(x,y) memcpy(x, y, sizeof(x))
#define fi first
#define se second
#define pb push_back
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define SQR(x) ((x)*(x))
#define mkp make_pair

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair <LL, LL> PL;
typedef pair <int, int> PI;
typedef pair <DB, DB> PD;
typedef pair <PI, PI> PIII;
typedef pair <PD, DB> LINE;

int Read()
 {
	char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
	bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return neg ? -ret : ret;
 }
 
const int MAXN = 10005;

LL ans;
int E, R, N, v[MAXN], b[MAXN];

void init()
 {
	scanf("%d%d%d", &E, &R, &N);
	fo (i, 1, N) v[i] = Read();
 }
 
void work()
 {
	int current = E, last = 0; ans = 0;
	for (int i = 1; i <= N; )
	 {
		//int limit_bound = current - R;
		//ans += (LL) max(limit_bound, 0) * (LL) v[i];
		// get first behind
		int j = i + 1; last = i;
		while (j <= N && v[i] > v[j]) j ++;
		if (j > N)
		 {
			ans += (LL) current * (LL) v[i];
			current = min(R, E);
			i ++; continue;
		 }
		b[j] = E;
		fd (k, j - 1, i) b[k] = max(0, b[k + 1] - R);
		if (!b[i])
		 {
			ans += (LL) current * (LL) v[i];
			i++;
			current = min(R, E);
		 } else
		if (b[i] <= current)
		 {
			ans += (LL) (current - b[i]) * (LL) v[i];
			current = E, i = j;
		 } else current = E - (b[i] - current), i = j;
	 }
	cout << ans << endl;
 }
 
int main()
 {
	freopen("B.in", "r", stdin), freopen("B2.out", "w", stdout);
	int cases = Read(); fo (cas, 1, cases)
	 {
		init();
		printf("Case #%d: ", cas);
		work();
	 }
	return 0;
 }
