#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>

#define LL long long
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PII pair<int, int>
#define PID pair<int, double>

using namespace std;

const int maxn = 100010;
int T, n, m;
double p[maxn], ans;

int main(){
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++){
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; i++) scanf("%lf", p + i);
		ans = n + 2;
		double fac = 1;
		for (int i = 1; i <= m; i++){
			fac *= p[i];
			ans = min(ans, m - i + fac * (n - i + 1) + (1 - fac) * (n - i + 1 + n + 1));
		}
		printf("Case #%d: %.8lf\n", ca, ans);
	}
}
