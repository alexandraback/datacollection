#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int cnt[12];
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++)
	{
		int n;
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		printf("Case #%d: ", ii);
		if (n == 0)
		{
			puts("INSOMNIA");
			continue;
		}
		int cur = n;
		do
		{
			int tmp = cur;
			while (tmp)
				cnt[tmp % 10]++, tmp /= 10;
			int tot = 0;
			for (int i = 0; i<10; i++)if (cnt[i])
				tot++;
			if (tot == 10)
			{
				printf("%d\n", cur);
				break;
			}
			cur += n;
		} while (true);
	}
}
