#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int q;
	scanf("%d", &q);

	for(int test = 1; test <= q; ++test)
	{
		int a, b, n;
		scanf("%d%d%d", &a, &b, &n);
		
		int wyn =0;

		for(int i = 0; i < a; ++ i)
			for(int j = 0; j < b; ++ j)
			{
				int x = i & j;
				if(x < n) 
					++ wyn;
			}

		printf("Case #%d: %d\n", test, wyn);
	}

	return 0;
}
