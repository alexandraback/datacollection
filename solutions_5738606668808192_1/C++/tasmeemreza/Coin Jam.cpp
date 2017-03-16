#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("sublime-in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, cs = 0;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int r = (n - 2) / 2;
		int now = 0;

		printf("Case #%d:\n", ++cs);
		for(int i = 1; i <= m; i++) {
			printf("1");
			for(int j = 0; j < r; j++) {
				printf("%d%d", bool(now & (1 << j)), bool(now & (1 << j)) );
			}
			printf("1 ");
			for(int j = 2; j <= 10; j++) printf("%d ", j + 1);
			printf("\n");
			now += 1;
		}
	}
	return 0;
}