#include<stdio.h>
int main()
{
	FILE *fp=freopen("input.txt","r",stdin);
	FILE *fp2=freopen("output.txt","w",stdout);
	int i,j,k,n,x,a[1005],max,min,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		min=999999999;
		scanf("%d",&x);
		for(j=0,max=0;j<x;j++)
		{
			scanf("%d",&a[j]);
			if(a[j]>max)
				max=a[j];
		}
		for(j=1;j<=max;j++)
		{
			sum=0;
			for(k=0;k<x;k++)
				if(a[k]%j==0)
					sum+=a[k]/j-1;
				else
					sum+=a[k]/j;
			if(sum+j<min)
				min=sum+j;
		}
		printf("Case #%d: %d\n",i+1,min);
	}
	scanf(" ");
}

