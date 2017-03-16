#include <cstdio>

int t,a,b,k;

int main()
{
	scanf("%d", &t);
	for(int test = 1; test <= t; ++test)
	{
		scanf("%d%d%d", &a, &b, &k);
		int res = 0;

		for(int i = 0; i < a; ++i)
			for(int j = 0; j < b; ++j)
				if((i&j) < k) res++;
		
		printf("Case #%d: %d\n", test, res);
	}
}
