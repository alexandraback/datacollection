#include<stdio.h>
#include<iostream>
#include<cmath>

int find_num(long long a)
{
	int count=1;
	
	a=a/10;
	
	while(a!=0)
	{
		count++;
		
		a=a/10;
	}
	
	//printf("Num=%d\n\n",count);
	
	return count;
}

long long count_no(long long a,long long b)
{
	long long i,quot,rem,temp,count=0;
	
	int num_of_digits;
	
	num_of_digits=find_num(a);
	
	if(num_of_digits<=1)
		return 0;
	else
	{
	
		for(i=a;i<=b;i++)
		{
			temp=i;
			
			quot=temp/10;
			
				rem=temp%10;
			
				temp=rem*pow(10,num_of_digits-1)+quot;
				
			while(temp!=i)
			{
				if(temp>i&&temp<=b)
				{
					count++;
				}
			
				quot=temp/10;
			
				rem=temp%10;
			
				temp=rem*pow(10,num_of_digits-1)+quot;
			
			}
		}
		
		return count;
	
	}
}

int main()
{
	long long t,i=1,ans,a,b;
	
	scanf("%lld",&t);
	
	while(i<=t)
	{
		scanf("%lld %lld",&a,&b);
	
		ans=count_no(a,b);
			
		printf("Case #%lld: %lld\n",i,ans);	
			
		i++;
	}
	
	return 0;
}
