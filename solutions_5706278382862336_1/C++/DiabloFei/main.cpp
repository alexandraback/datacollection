#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int cnt;

bool chenck(long long a,long long b)
{
	if (a==b)
	{
		return true;
	}
	if (b%2 != 0)
	{
		return false;
	}

	while (a<b&&(b%2 ==0))
	{
		b /=2;
	}
	if (a<b)
	{
		return false;
	}
	else
	{
		if (a>b&&b%(a-b) !=0)
		{
			if (b %2 !=0)
			{
				return false;
			}
			else return chenck(a-b,b);
		}
		else if (a ==b)
		{
			return true;
		}
		else if (a>b&&b%(a-b)==0)
		{
		   return	chenck(1,b/(a-b));
		}

	}
}
void Do(long long a,long long b)
{
	bool flag;
	while (a<b&&(b%2 ==0))
	{
		b /=2;
		cnt++;
	}
	if (a<b)
	{
		flag=false;
	}
	else if (a==b)
	{
		flag =true;
	}
	else if (a>b&&b%(a-b) !=0)
	{
		flag=chenck(a-b,b);
	}
	
	else if (a>b&&b%(a-b)==0)
	{
		flag=chenck(1,b/(a-b));
	}
	if (flag ==true)
	{
		printf("%d\n",cnt);
	}
	else
	{
		printf("impossible\n");
	}
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i,T,TC;

	scanf("%d",&TC);

	for (T =1;T<=TC;T++)
	{
		printf("Case #%d: ", T);
		long long a,b;
		scanf("%lld/%lld",&a,&b);

		if (b%2 != 0)
		{
			printf("impossible\n");
			continue;
		}
	    cnt =0;
		Do(a,b);

		
	}

}