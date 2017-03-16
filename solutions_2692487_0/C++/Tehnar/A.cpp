#include <cstdio>
#include <algorithm>

using namespace std;

int n, t;
long long a[200], x;


long long foo(int pos, long long b)
{                                                  

	while (pos < n)
	{ 
		while (pos < n && a[pos] < b)
		{                                                                                      
			b += a[pos];
			pos++;
	    }
		if (pos == n)
		{
			return 0;
		}
		if (b == 1)
		{              
			return n;
		}	
		long long k = 0;
		while(b <= a[pos])
		{
			b += b - 1;
			k++;
		}
	
		//printf("%I64d %I64d %d\n", k, b, pos);
		return min(foo(pos, b) + k, 1ll * n - pos); 
	}
	return 0;
		
}
int main()
{
	freopen("1.in" , "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{

		scanf("%I64d%d", &x, &n);
		for (int i = 0; i < n; i++)
			scanf("%I64d", &a[i]);
		sort(a, a + n);
		                                    
		printf("Case #%d: %I64d\n", q + 1, foo(0, x));
		
		//printf("Case #%d: %I64d\n", q + 1, ans);
					 
	}
}
