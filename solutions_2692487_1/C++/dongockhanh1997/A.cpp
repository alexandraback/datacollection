#include<cstdio>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;

const int N = 100+5;
map<long long, int> f[N];
int a[N], m, n;

int F(int p, long long s) {
	if(f[p].count(s)) return f[p][s];
	if(p == n) return 0;
	int &res = f[p][s];
	if(a[p] < s) return res = F(p+1, s+a[p]);
	return res = min(F(p+1, s) + 1, s != 1 ? F(p, 2*s-1) + 1 : INT_MAX);
}

int main() {
	int T; scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d",&m,&n);
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for(int i = 0; i <= n; ++i) f[i].clear();
		sort(a, a+n);
		printf("Case #%d: %d\n", t, F(0, m));
	}
	return 0;
}
