#include <iostream>
#include <cstdio>

#define SMALL
//#define LARGE

using namespace std;

int T;
char inp[1005], ans[2005];

int main()
{
#ifdef SMALL
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
#endif
#ifdef LARGE
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
#endif
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%s", inp);
		char begin = inp[0];
		ans[1001] = inp[0];
		int f = 1001, e = 1001;
		for (int i = 1; inp[i]; ++i) {
			if (inp[i] >= begin)
				ans[--f] = begin = inp[i];
			else
				ans[++e] = inp[i];
		}
		printf("Case #%d:", Case);
		printf(" ");
		for (int i = f; i <= e; ++i)
			printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}
