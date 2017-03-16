#include <cstdio>
#include <cstring>

int n1, n2, n3, m;
// int max = 0;
// int a[3];

int calc(int a, int b)
{
	if (a < b)
		return a;
	int tmp = 1;
	for (int i = 1; i < b; ++i)
	{
		tmp *= a - i + 1;
		tmp /= i;
	}

	return tmp;
}

int main(){
	int T;
	scanf("%d", &T);

	for (int ttt = 1; ttt <= T; ++ ttt)
	{
		printf("Case #%d: ", ttt);

		// fprintf(stderr, "Case #%d: ", ttt);

		scanf("%d %d %d %d\n", &n1, &n2, &n3, &m);
		// int tmp = calc(n3, m);
		int tmp = m;
		// fprintf(stderr, "%d\n", tmp);
		if (n3 < tmp)
			tmp = n3;
		
		// fprintf(stderr, "%d\n", tmp);

		printf("%d\n", n1 * n2 * tmp);

		int t1 = 1, t2 = 1, t3 = 1;
		for (int i = 1; i <= n1; ++i)
		{

			for (int j = 1; j <= n2; ++j)
			{
				t2 = t1;
				for (int l = 0; l < tmp; ++l)
				{
					printf("%d %d %d\n", i, j, t2);
					++ t2;
					if (t2 > n3)
					{
						t2 = 1;
					}
				}
				++ t1;
				if (t1 > n3)
				{
					t1 = 1;
				}
					
			}
			t3 ++;
			t1 = t3;
		}
	}

	return 0;
}