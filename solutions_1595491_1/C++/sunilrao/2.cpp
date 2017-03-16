#include<iostream>
#include<stdio.h>

using namespace std;

int find_g(int n,int s,int p,int t[200])
{
	int i,count=0,val,num;
	
	for(i=0;i<n;i++)
	{
		if(t[i]<p)
		{
			continue;
		}
	
		val=t[i]/3;
	
		if(t[i]%3==0)
		{
			if(val>=p)
				count++;
			else
			{
				if((val-p)>=-1&&(val-p)<=1&&(--s)>=0)
				{
					count++;
				}
			}		
		}
		else
		{
			num=((t[i]-(val*3))<(((val+1)*3)-t[i]))?val:val+1;
			
			if(num>=p)
				count++;
			else if((t[i]-num*2)>=p)
				count++;			
			else
			{
				if((p-num<=1))//||(p-(t[i]-num*2)<=1))
				{
					if((--s)>=0)
					{
						count++;
					}
				}	
			}	
		}
	}
	
	return count;
}

int main()
{
	int i=0,j,t[200],n,s,p,ans,test;
	
	scanf("%d",&test);
	
	while(i<test)
	{
		scanf("%d %d %d",&n,&s,&p);
		
		for(j=0;j<n;j++)
		{
			scanf("%d",&t[j]);
		}	
		
		ans=find_g(n,s,p,t);
			
		printf("Case #%d: %d\n",i+1,ans);	
	
		i++;
	}
	
	return 0;
}
