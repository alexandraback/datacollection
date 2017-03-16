#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
long long int n, m, s;
void process()
{
	scanf("%lld %lld %lld", &n, &m, &s);
	long long int i, j;
	long long int nm = 1;
	for (i = 0; i < n; i++)
	{
		nm = 0;
		for (j = 0; j < m; j++)
		{
			nm *= n;
			nm += i;
		}
		printf("%lld ", nm + 1);
	}
	printf("\n");
}
int main()
{
	int t;
	int tv = 1;


	freopen("D-small-attempt1.in", "rt", stdin);
	freopen("D-small-attempt1.out", "wt", stdout);
//	freopen("B-large.in", "rt", stdin);
//	freopen("B-large.out", "wt", stdout);

	scanf("%d", &t);
	while (t--)
	{
		printf("Case #%d: ", tv);
		process();
		tv++;
	}
}