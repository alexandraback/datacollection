#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
//#include <map>
#include <functional>
#include <cmath>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define SQR(x) ((x)*(x))
#define mkp make_pair
#define pb push_back
#define Fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;
typedef pair <DB, DB> PD;
typedef pair <PI, PI> PIII;

int Read()
 {
	char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
	bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return neg ? -ret : ret;
 }
 
const int MAXN = 105;

char yes[5]="YES", no[5]="NO";

vector <PI> mark[105];
int ca[MAXN], cb[MAXN];
int N, M, a[MAXN][MAXN];

int main()
 {
	freopen("B.in", "r", stdin), freopen("B.out", "w", stdout);
	int cases; scanf("%d", &cases); fo (cas, 1, cases)
	 {
		scanf("%d%d", &N, &M);
		Fill(mark, 0);
		fo (i, 1, N) fo (j, 1, M) a[i][j] = Read(), mark[a[i][j]].pb(mkp(i, j));
		fo (i, 1, N)
		 {
			ca[i] = a[i][1];
			fo (j, 1, M) ca[i] = max(ca[i], a[i][j]);
		 }
		fo (j, 1, M)
		 {
			cb[j] = a[1][j];
			fo (i, 1, N) cb[j] = max(cb[j], a[i][j]);
		 }
		bool ans = 1;
		fo (i, 1, 100) if (mark[i].size())
		 {
			fo (j, 0, mark[i].size() - 1) if (ca[mark[i][j].fi] > i && cb[mark[i][j].se] > i)
			 { ans = 0; break; }
			if (!ans) break;
		 }
		printf("Case #%d: %s\n", cas, ans ? yes : no);
	 }
	return 0;
 }
