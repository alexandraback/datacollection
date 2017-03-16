#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[30];
int p[3000000];
int ans1, ans2, n, tmp;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cs;
	scanf("%d", &cs);
	for (int test = 1; test <= cs; ++ test) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i <= 20 * 100000; ++i)
		p[i] = -1;
		ans1 = ans2 = -1;
		for (int i = 0; i < (1 << n); ++i) {
			tmp = 0;
			for (int j = 0; j < n; ++j)
			if ((i&(1 << j)) != 0) tmp += a[j];

			if (p[tmp] != -1) {
				ans1 = i;
				ans2 = p[tmp];
				break;
			} else p[tmp] = i;
		}
		printf("Case #%d:\n", test);
		if (ans1 == -1) printf("Impossible\n");
		else {
			for (int j = 0; j < n ; ++j) 
			if ((ans1&(1 << j)) != 0) printf("%d ", a[j]);
			printf("\n");
			for (int j = 0; j < n ; ++j) 
			if ((ans2&(1 << j)) != 0) printf("%d ", a[j]);
			printf("\n");
		}
	}
	return 0;
}