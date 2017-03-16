#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i,T,TC;

	scanf("%d",&TC);

	for (T =1;T<=TC;T++)
	{
		printf("Case #%d: ", T);
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		int a,b,temp;
		int max_a;
		if (n>m)
		{
			temp=n;
			n=m;
			m=temp;
		}
		if (n%2 ==0)
		{
			max_a= n/2;
		}
		else
		{
			max_a = (n+1)/2;
		}
		bool flag =false;
		if (max_a ==1)
		{
			printf("%d\n",k);
			continue;
		}
	for (a=max_a;a>=2;a--)
	{
		for (b=1;b<=m-2;b++)
		{

			if ((a*2-1)*b+2*(a-1)*(a-1)>=k)
			{
				flag=true;
				break;
				
			}
			
		}
		if (flag ==true)break;	
	}

	printf("%d\n",2*(a+b-1));
	}

}