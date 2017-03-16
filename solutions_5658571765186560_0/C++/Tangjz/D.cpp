#include <cstdio>
int t, x, r, c;
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		int flag = 0;//xianshou win
		scanf("%d%d%d", &x, &r, &c);
		if(x == 1)
		{
			if(r * c > 1)
				flag = 1;
		}
		else if(x == 2)
		{
			if(r * c % 2 == 0 && r * c > 2)
				flag = 1;
		}
		else if(x == 3)
		{
			if(r * c % 3 == 0 && r * c > 3)
				flag = 1;
		}
		else if(x == 4)
		{
			if(r * c % 4 == 0 && r * c > 8)
				flag = 1;
		}
		printf("Case #%d: %s\n", Case, !flag ? "RICHARD" : "GABRIEL");
	}
	return 0;
}
