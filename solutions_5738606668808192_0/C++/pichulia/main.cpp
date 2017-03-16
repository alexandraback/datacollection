#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
void process()
{
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < (1 << (n/2-2)) && m; i++)
	{
		m--;
		printf("11");
		int ii = i;
		for (j = 0; j < n/2 - 2; j++)
		{
			if (ii % 2)printf("00");
			else printf("11");
			ii /= 2;
		}
		printf("11");
		for (j = 2; j <= 10; j++) printf(" %d", j + 1);
		printf("\n");
	}
}
int main()
{
	int t;
	int tv = 1;


	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
//	freopen("D-large.in", "rt", stdin);
//	freopen("D-large.out", "wt", stdout);

	scanf("%d", &t);
	while (t--)
	{
		printf("Case #%d:\n", tv);
		process();
		tv++;
	}
}