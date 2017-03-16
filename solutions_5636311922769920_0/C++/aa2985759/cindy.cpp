#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, s;
int main()
{
	int t, i, j, tt = 0;

	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &n, &m, &s);
		printf("Case #%d: ", ++tt);
		for (i = 1; i <= s; i++)
			printf(" %d", i);
		printf("\n");
	}
	return 0;
}

