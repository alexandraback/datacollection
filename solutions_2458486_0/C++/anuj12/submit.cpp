#include<stdio.h>
#include<string.h>


int main()
{
int t,i,j,k,n,temp,opened[401],chest[401][401],p,q,r,keys[401],start[401],out[401],n1,open[401],s;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
		
	memset(keys,0,sizeof(keys));
	memset(start,0,sizeof(start));
	memset(opened,0,sizeof(opened));
	scanf("%d%d",&k,&n);
	for(j=1;j<=k;j++)
	{
		scanf("%d",&temp);
		start[temp]++;
	}
	for(j=1;j<=n;j++)
	{
		scanf("%d%d",open+j,&n1);
		for(p=0;p<n1;p++)
				scanf("%d",&chest[j][p]);
		chest[j][p]=0;
	}
	q=0;
	for(j=1;j<=n;j++)
	{
		q=0;
		memset(opened,0,sizeof(opened));
		for(s=1;s<401;s++)
			keys[s]=start[s];
		
		for(r=j;r<=n;r++)
		{
			if((!opened[r]) && keys[open[r]])
			{
				opened[r]=1;
				keys[open[r]]--;		
				p=0;		
				while(chest[r][p])
				{
					keys[chest[r][p]]++;
					p++;
				}
				out[q++]=r;
				r=0;								// again start from chest 1
				if(q==n)
					break;
			}
		}
		
		if(q==n)
			break;
	}
	if(q==n)
	{
			
		printf("Case #%d: ",i);
		for(j=0;j<n;j++)
			printf("%d ",out[j]);
		printf("\n");
	}
	else
		printf("Case #%d: IMPOSSIBLE\n",i);
}
 return 0;
}
				
				
			
			
			
			
			
			

			
			


