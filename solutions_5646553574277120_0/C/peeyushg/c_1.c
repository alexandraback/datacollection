#include<stdio.h>
int main()
{
	int t,t1,i,j,c,d,v,cnt;
	int a[40],ans[200],ans2[200];
	
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	
	
	scanf("%d",&t);
	for(t1=1;t1<=t;t1++)
	{
		for(i=1;i<200;i++)
		ans[i] = 0;
		
		scanf("%d%d%d",&c,&d,&v);
		
		for(i=1;i<=d;i++)
		{
			scanf("%d",&a[i]);	
		}
		
		for(i=1;i<=d;i++)
		{
			ans[a[i]]=1;
			for(j=i+1;j<=d;j++)
			{
				ans[a[i]+a[j]] = 1;		
			}		
		}
		
		//	for(i=1;i<=v;i++)
		//	printf("%d ",ans[i]);
		
		cnt = 0;
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=30;j++)
			{
				ans2[j] = 0;
			}
			
			if(ans[i] == 0) 
			{
			//	printf("he %d\n",i);
				cnt++;	
				
				ans[i] = 1;
				
				for(j=1;j<=v;j++)
				{
					if(j != i)
					{
						if(ans[j] == 1)
						{
							ans2[j+i] = 1;	
						}
					}
				}
			}
			
			for(j=1;j<=30;j++)
			{
				if(ans2[j] == 1) ans[j] = 1;
			}
				
		}
		
		printf("Case #%d: %d\n",t1,cnt);
	}
	
return 0;
}
