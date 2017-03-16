#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	int p;
	for(p=0;p<t;p++)
	{
		int s;
		int n;
		scanf("%d",&s);
		scanf("%d",&n);
		int a[n+1];
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int j;
		int swap;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[j] <  a[i])
				{
					swap=a[j];
					a[j]=a[i];
					a[i]=swap;
				}
			}
		}
	int ans=0;
	i=0;
	int min[n];
	j=0;
	while(1)
	{
		if(s==1)
		{
			if(a[0] >=1)
			{
				ans=n;
				break;
			}
		}
		if(i==n)
		{
			break;
		}
		if(s > a[i])
		{
			s=s+a[i];
			i++;
		}
		else
		{
			min[j]=ans+n-i;
			j++;
			s=s+s-1;
			ans++;
		//	printf("chu\n");
		}
	}

int ans1=ans;
for(i=0;i<j;i++)
{
	if(min[i] < ans1)
	{
		ans1=min[i];
	}
}


printf("Case #%d: %d\n",p+1,ans1);


//		for(i=0;i<n;i++)
//		{
//			printf("%d ",a[i]);
//		}



	}
	return 0;
}

