#include<stdio.h>
int main()
{
	int t,a,b,arr[1000],i,c[5],j,flag,num,k,max,count,m=1;
	i=1;
	k=0;
	while(i*i<=1000)
	{
		flag=0;
		j=0;
		num=i;
		while(num != 0)
		{
			c[j++]=num%10;
			num=num/10;
		}
		if(j == 1)
			flag=1;
		else if(j==2 && (c[0] == c[1]))
			flag=1;
		if(flag == 1)
		{
			num=i*i;
			j=0;
			while(num != 0)
			{
				c[j++]=num%10;
				num=num/10;
			}
			if(j == 1)
				arr[k++]=i*i;
			else if(j==2 && (c[0] == c[1]))
				arr[k++]=i*i;
			else if(j == 3 && (c[0] == c[2]))
				arr[k++]=i*i;
		}
		i++;
	}
	max=k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		count=0;
		for(i=0;i<max;i++)
		{
			if(arr[i]>=a && arr[i]<=b)
				count++;
			if(arr[i]>b)
				break;
		}
		printf("Case #%d: %d\n",m,count);
		m++;
	}
	return 0;
}
