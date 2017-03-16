#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, x, y) for(int i = x; i < y; ++ i)
#define pb push_back
#define mk make_pair

const int N = 1005;
int f[N];
int tail[N];
bool b[N];

void solve() {
	int n;
	scanf("%d", &n);
	FOR(i,0,n)
	{
		scanf("%d", f + i);
		--f[i];
	}
	int circle = 0, sum = 0;
	memset(tail, 0, sizeof(tail));
	FOR(i,0,n)
	{
		memset(b, 0, sizeof(b));
		int j = i, c = 0;
		for (j = i; !b[j]; j = f[j])
			b[j] = true, ++c;
		if (j == i)
			circle = max(circle, c);
		if (f[f[j]] == j)
			tail[j] = max(tail[j], c - 2);
	}
	FOR(j,0,n)
		if (f[f[j]] == j)
			sum += tail[j] + 1;
	printf("%d\n", max(sum, circle));
}

int main() {
#ifdef LOCAL
	freopen("in","r",stdin);
#endif
	int T, Case = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++Case);
		solve();
	}
	return 0;
}
