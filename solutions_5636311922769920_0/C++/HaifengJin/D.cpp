#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		long long temp = 1;
		for (int i = 0; i < c - 1; i++)
		{
			temp *= k;
		}
		case_num++;
		printf("Case #%d:", case_num);
		for (int i = 0; i < k; i++)
		{
			printf(" %lld", temp * i + 1);
		}
		puts("");
	}
	return 0;
}
