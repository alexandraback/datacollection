#include <cstdio>

int count(int a)
{
	int r = 0;
	bool was[10] = {0};
	for (int b = a;; b += a)
	{
		for (int c = b; c > 0; c /= 10)
		{
			bool & w = was[c % 10];
			if (w != true)
			{
				w = true;
				++r;
				if (r == 10)
					return b;
			}
		}
	}
}

int main()
{
	/*int max = 0;
	for (int i=1; i<1000000; ++i)
	{
		int c = count(i);
		if (c > max)
		{
			max = c;
			printf("%d: %d\n", i, c);
		}
	}*/
	int T;
	int N;
	scanf("%d", &T);

	for (int i=0; i<T; ++i)
	{
		scanf("%d", &N);
		printf("Case #%d: ", i+1);
		if (N == 0)
			printf("INSOMNIA\n");
		else
			printf("%d\n", count(N));
	}
	return 0;
}
