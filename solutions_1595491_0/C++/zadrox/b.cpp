#include<stdio.h>

int main()
{
	int t,n,s,p,count,ti;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d %d",&n,&s,&p);
		count=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&ti);
			int d=ti/3,r=ti%3;
			if(d>=p)
				count++;
			else if(r>0)
			{
				if(r==2)
				{
					if(d+1>=p)
						count++;
					else if(d+2>=p)
					{
						if(s)
						{
							s--;
							count++;
						}
					}
				}
				else
				{
					if(d+1>=p)
						count++;
				}
				
			}
			else
			{
				if(d>=1)
				{
					if(d+1 >= p)
					{
						if(s)
						{
							s--;
							count++;
						}
					}
				}				
			}
		}
		printf("Case #%d: %d\n",i+1,count);
	}
	return 0;
}