#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <sstream>
#include <ctime>
#include <functional>
#define pi 3.14159265358979323846264338327950288
#define pb push_back
#define mp make_pair
#define LL long long
#define LD long double
#define INF 1000000000
#define INFll 1000000000000000000ll
#define Vi vector<int>
#define VI Vi::iterator
#define Mi map<int, int>
#define MI Mi::iterator
#define Si set<int>
#define SI Si::iterator
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define mid (l + r) / 2
#define Left k * 2, l, mid
#define Right k * 2 + 1, mid + 1, r
#define N 111
using namespace std;
int sum[N], s[N], len[N];
double f[N][N][N];
int c[N][N];
int n, i, j,tot;
int x, y;
int main(){
	for (i = 1;; i++){
		len[i] = 2 * i - 1;
		sum[i] = sum[i - 1] + len[i] * 2 - 1;
		if (sum[i] > 20) break;
	}
	tot = i;
	f[0][0] = 1;
	for (i = 1; i <= tot; i++)
		for (j = 0; j <= i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	for (i = 1; i <= tot; i++)
		for (j = 1; j <= sum[i]; j++)
			for (k = 1; k <= len[i]; k++)
				if (sum[i] + k <= j) f[i][j][k] = 1.0;
				else{
					int tmp = 0;
					for (l = k; l <= len[i]; l++)
						tmp += c[j][l];
					f[i][j][k] = tmp / pow(2, j);
				}
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		scanf("%d%d%d", &n, &x, &y);
		int level = (abs(x) + abs(y)) / 2 + 1;
		if (sum[level] <= n) {puts("1.0");continue;}
		if (sum[level - 1] >= n) {puts("0.0");continue;}
		n -= sum[level - 1];
		printf("%.6lf\n", f[level][n][y + 1]);
	}
}