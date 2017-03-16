#include <cstdio>
using namespace std;

int k, c, s;

void work()
{
	if (k == 1)
	{
		printf(" 1");
		return;
	}
	long long temp = 0;
	long long total = 1;
	int cnt = 0;
	for (int i = 0; i < c; i++)
	{
		total *= k;
	}
	while (cnt < k)
	{
		long long index = 0;
		long long pow = 1;
		for (int i = 0; i < c; i++)
		{
			if (index + pow * temp < total)
				index += pow * temp;
			pow *= k;
			if (temp < k - 1)
				temp++;
			cnt++;
		}
		printf(" %lld", index + 1);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d:", case_num);

		scanf("%d%d%d", &k, &c, &s);
		if (c * s < k)
		{
			puts(" IMPOSSIBLE");
			continue;
		}

		work();
		puts("");
	}
	return 0;
}
