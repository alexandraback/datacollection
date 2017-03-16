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

	if ((n - 1) / m + 1 > s) {
		printf(" IMPOSSIBLE\n");
		return;
	}
	int cnt = 0;
	nm = 0;
	for (i = 0; i < n; i++)
	{
		nm *= n;
		nm += i;
		cnt++;
		if (cnt == m || i == n-1)
		{
			printf(" %lld", nm+1);
			nm = 0;
			cnt = 0;
		}
	}
	printf("\n");
}
int main()
{
	int t;
	int tv = 1;


//	freopen("D-small-attempt1.in", "rt", stdin);
//	freopen("D-small-attempt2.out", "wt", stdout);
	freopen("D-large.in", "rt", stdin);
	freopen("D-large.out", "wt", stdout);

	scanf("%d", &t);
	while (t--)
	{
		printf("Case #%d:", tv);
		process();
		tv++;
	}
}