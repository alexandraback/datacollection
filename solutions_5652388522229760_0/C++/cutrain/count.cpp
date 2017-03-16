#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n, x;
int tmp;
int T;
int tot;
int ans;

int main()
{
	scanf("%d", &T);
	for (int testcase = 1;testcase <= T;++ testcase)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			printf("Case #%d: INSOMNIA\n", testcase);
			continue;
		}
		ans = 0;
		tot = 0;
		x = n;
		do
		{
			tmp = x;
			while (tmp)
			{
				tot |= 1 << (tmp % 10);
				tmp /= 10;
			}
			if (tot != 0x3ff)
				x += n;
		}while (tot != 0x3ff);
		printf("Case #%d: %d\n", testcase, x);
	}
	return 0;
}
