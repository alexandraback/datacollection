#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000],b[1000];
int main()
{
	
	//	freopen("111.txt","r",stdin);freopen("111.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	//freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);

	int tt,ii,i,j,n,r,sum,tp,min,t;
	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d%d",&r,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if (r==1) 
		{
				printf("Case #%d: %d\n",ii,n);
				continue;
		}
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
			b[i]=100000000;
		b[0]=0;
		sum=r;
		for(i=1;i<=n;i++)
			if (a[i]<sum)  {sum=sum+a[i];b[i]=0;}
			else
				break;
		tp=i;
		for(i=tp;i<=n;i++)
		{
			if (sum>a[i])
			{
				sum=sum+a[i];
				b[i]=b[i-1];
				continue;
			}
			t=0;
		//	tk=sum;
		//	if (b[i-1]+1<b[i])  b[i]=b[i-1]+1;
			while(1)
			{
				t++;
				sum=sum+sum-1;
				if (sum>a[i])  break;
			}
			sum=sum+a[i];
			b[i]=b[i-1]+t;
		//	sum=tk;
		}
		min=n;
		for(i=1;i<=n;i++)
			if (b[i]+n-i<min)  min=b[i]+n-i;
		printf("Case #%d: %d\n",ii,min);
		int kgt=0;
	}
	return 0;
}