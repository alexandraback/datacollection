#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;





int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);


	int nCase;
	int t;
	int i, j, k;
	long long p, q;
	long long ans;
	scanf("%d", &nCase);
	for (t = 1; t <= nCase; ++ t)
	{		
		scanf("%I64d/%I64d", &p, &q);
		
		ans = 0;
		while (q != 1 && q % 2 == 0)
		{
			if (p < q)
			{
				ans++;
			}
			q /= 2;
		}
		if (q != 1 && p % q != 0)
		{
			ans = -1;
		}
		
		printf("Case #%d: ", t);
		if (ans == -1)
		{
			printf("impossible");
		}
		else
		{
			printf("%I64d", ans);
		}
		if (t < nCase)
		{
			printf("\n");
		}
	}

	//system("pause");
	return 0;
}

