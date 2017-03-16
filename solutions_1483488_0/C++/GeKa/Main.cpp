#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 210000
int mas[MAX];

int main()
{	
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{		
		memset(mas, 0, sizeof(int) * MAX);
		int a, b;
		scanf("%d%d", &a, &b);
		int n = 1;
		int aa = a;
		while (aa > 0)
		{
			n *= 10;
			aa /= 10;
		}

		for (int i = a; i <= b; i++)
		{
			int mn = i;
			int q = i;
			for (int j = 0; j < 10; j++)
			{
				q = (q + n * (q % 10)) / 10;
				mn = min(mn, q);
			}
			mas[mn]++;
		}
		long long res = 0;
		for (int i = 0; i < MAX; i++)
			if (mas[i] > 0)
			{
				res += mas[i] * (mas[i] - 1) / 2;
			}
		printf("Case #%d: %lld\n", t+1, res);
	}

	return 0;
}