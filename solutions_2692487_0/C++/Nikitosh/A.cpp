#include<cstdio>
#include<algorithm> 

using namespace std;

int T, k, n, a[1000], ANS = 1000000000, l, sz = 0;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int j = 0; j < T; j++)
	{
		ANS = 1000000000;
		sz = 0;
		scanf("%d%d", &k, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (k == 1)
		{
			printf("Case #%d: %d\n", j + 1, n);
			continue;
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{   	
			//printf("%d %d\n", a[i], k);
			if (a[i] < k)
			{
				k += a[i];
				continue;
			}                  
			//printf("ololo = %d\n", sz + n - i);
			ANS = min(ANS, sz + n - i);
			l = a[i] - k;       
			//printf("%d\n", sz);
			while (k <= a[i])
			{
				k += k - 1;
				sz++;
			}
			k += a[i];
			//printf("%d %d\n", sz, k);
		}
		//printf("ANS = %d\n", ANS);
		ANS = min(ANS, sz);
		//printf("ANS = %d\n", ANS);
		printf("Case #%d: %d\n", j + 1, ANS);
	}
	return 0;
}
