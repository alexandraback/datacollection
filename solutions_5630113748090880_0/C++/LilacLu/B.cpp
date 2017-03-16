#include <iostream>
#include <cstdio>
#include <cstring>

#define SMALL
//#define LARGE

using namespace std;

int T, n, x;
int cnt[2501];

int main()
{
#ifdef SMALL
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
#endif
#ifdef LARGE
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
#endif
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i < 2 * n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &x), ++cnt[x];
		printf("Case #%d:", Case);
		for (int i = 1; i <= 2500; ++i)
			if (cnt[i] & 1)
				printf(" %d", i);
		printf("\n");
	}
	return 0;
}
