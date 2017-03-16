#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lli long long int

int de[200];

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	int tc, c, d;
	lli v, ans, temp;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++)
	{
		scanf("%d%d%lld", &c, &d, &v);
		for (int i =0 ; i < d; i++)
			scanf("%d", &de[i]);
			
		sort(de, de + d);
		lli n = 1;
		lli sm = 0;
		int used = -1;
		ans = 0;
		while (n <= v)
		{
			if (sm < n)
			{
				if (used < d)
				{
					while(sm < n && used < d )
					{
						if (de[used + 1] <= n)
						{
							// cout << " n =" << n << "   "  << used << endl;
							used++;
							sm += de[used] * c;
							// cout << "sum =" << sm;
						}
						else	
							break;
					}
					// while(de[used + 1] <= n)
					// {
						// used++;
						// sm += de[used] * c;
						// if (sum > n || used == d)
							// break;
					// }
				}
				if (sm >= n)
					n = sm + 1;
				else if (used <= d)
				{
					ans ++;
					sm += n * c;
					n = sm + 1;
				}
			}
		}
		
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}