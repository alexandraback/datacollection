#include<stdio.h>
#define MAX 100000000000000
int main()
{
	long long int t,a,b,arr[1000],i,c[20],j,flag,num,k,max,count,m=1,start,end,flag1;
	i=1;
	k=0;
	while(i*i<=MAX)
	{
		flag=1;
		j=0;
		num=i;
		while(num != 0)
		{
			c[j++]=num%10;
			num=num/10;
		}
		start=0;
		end=j-1;
		while(start <= end)
		{
			if(c[start] != c[end])
				flag=0;
			start++;
			end--;
		}
		if(flag == 1)
		{
			num=i*i;
			j=0;
			flag1=0;
			while(num != 0)
			{
				c[j++]=num%10;
				num=num/10;
			}
			start=0;
			end=j-1;
			while(start<=end)
			{
				if(c[start] != c[end])
					flag1=1;
				start++;
				end--;
			}
			if(!flag1)
			{
				arr[k++]=i*i;
				//printf("%lld %lld\n",i,i*i);
			}
		}
		i++;
	}
	//printf("%lld\n",k);
	max=k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		count=0;
		for(i=0;i<max;i++)
		{
			if(arr[i]>=a && arr[i]<=b)
				count++;
			if(arr[i]>b)
				break;
		}
		printf("Case #%lld: %lld\n",m,count);
		m++;
	}
	return 0;
}
