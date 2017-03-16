#include <cstdio>
#include <algorithm>
using namespace std;
int t, n, tab[110];
long long a;
int wynik, op;
int main()
{
	scanf("%d", &t);
	for (int q = 1; q <= t; q++)
	{
		scanf("%lld %d", &a, &n);
		wynik=n;
		op=0;
		for (int i = 0; i < n; i++)
			scanf("%d", &tab[i]);
		if (a!=1)
		{
			sort(tab, tab+n);
			for (int i = 0; i < n; i++)
			{
				if (a>tab[i])
					a+=tab[i];
				else
				{
					a=a+a-1;
					op++;
					i--;
				}
				wynik=min(wynik, op+n-i-1);
			}
		}
		printf("Case #%d: %d\n", q, wynik);
	}
	return 0;
}
