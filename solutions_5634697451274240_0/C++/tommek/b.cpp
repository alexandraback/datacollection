#include <bits/stdc++.h>

using namespace std;

const int MX = 1005;
int n; 
char a[MX];

void f(int x)
{	
	for (int i = 0; i <= x/2; ++ i)
	{
		swap(a[i], a[x-i]);
	}
	
	for (int i = 0; i <= x; ++ i)
	{
		if (a[i] == '+')
		{
			a[i] = '-';		
		}
		else
		{
			a[i] = '+';	
		}
	}
}

int main()
{
	int ttte; scanf("%d", &ttte); for (int ttt = 1; ttt <= ttte; ++ ttt)
	{	
		printf("Case #%d: ", ttt);

		scanf("%s", a);
		n = strlen(a);
		
		int res = 0;
		for (int i = n-1; i >= 0; -- i)
		{
//			puts(a);
			if (a[i] == '-')
			{
				for (int j = 0; j <= i; ++ j)
				{
					if (a[j] == '-')
					{
						if (j != 0)		
						{
							f(j-1);
							++ res;
						}
						break;
					}
				}
				f(i);
				res ++;
			}
		}
		
		printf("%d\n", res);
	}
}
