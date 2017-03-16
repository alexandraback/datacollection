#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	int times[2800];
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &t);
	for (int cas=1; cas<=t; cas++)
	{
		int i, j, n;
		scanf("%d", &n);
		memset(times, 0, sizeof(times));
		for (i=0; i<2*n-1; i++)
		{
			for (j=0; j<n; j++) {
				int a;
				scanf("%d", &a);
				times[a]++;
			}
		}
		int out=0;
		printf("Case #%d:", cas);
		for (i=1; i<2800 && out<n; i++)
		{
			if (times[i]%2) printf(" %d", i), out++;
		}
		printf("\n");
		if (out!=n) fprintf(stderr, "error out=%d, not %d\n", out, n);
	}
	return 0;
}
		
