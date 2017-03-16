#include<stdio.h>

int main()
{
	int t,a,b,count,p[]={1,10,100,1000,10000,100000,1000000},nd;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		count=0;
		int t=a;
		nd=0;
		while(t)
		{
			nd++;
			t/=10;
		}
		int rot;
		for(int j=a;j<=b;j++)
		{
			rot=(j%10) * p[nd-1] + j/10;
			while(rot != j)
			{
				if(rot >= a && rot <= b && rot > j)
					count++;
				rot=(rot%10) * p[nd-1] + rot/10;
			}
		}
		printf("Case #%d: %d\n",i+1,count);
	}
	return 0;
}