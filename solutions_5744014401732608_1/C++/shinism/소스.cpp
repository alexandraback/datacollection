#pragma warning(disable:4996)
#include<fstream>
using namespace std;
long long n, m;
int net[60][60];
void solve();
void make_net(int v);
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T,i;

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}

void solve()
{
	int i,j;
	long long k;

	scanf("%lld %lld", &n, &m);
	k = 1;
	for (i = 1; i <=n-2; i++) {
		k *= 2;
	}
	if (k < m) {
		printf("IMPOSSIBLE\n");
		return ;
	}
	printf("POSSIBLE\n");
	int p = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) net[i][j] = 0;
	}

	for (i = n - 1; i >= 1; i--) {
		k /= 2; if (k == 0) k = 1;
		if (m >=k) {
			if (p == 0) make_net(i);
			net[0][n - i] = 1;
			m -= k;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d", net[i][j]);
		}
		printf("\n");
	}
}

void make_net(int v)
{
	int i, j;

	for (i = n - 1; i >= n - v; i--) {
		for (j = i + 1; j <= n - 1; j++) {
			net[i][j] = 1;
		}
	}
}