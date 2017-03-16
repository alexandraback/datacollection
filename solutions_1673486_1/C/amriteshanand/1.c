#include<stdio.h>
#include<string.h>
#include<stdlib.h>
solve()
{
	int a,b,i,j;
	float ans=0,k,max=100000000,temp,temp1;
	float p[1000009];
	float w[1000009];
	scanf("%d%d",&a,&b);
	for(i=0;i<a;i++)
		{scanf("%f",&p[i]);w[i]=1-p[i];}
	for(i=0;i<=a;i++)
	{
		k=1;
		for(j=0;j<i;j++)
			k*=p[j];
		temp=k*((b+1-a)+2*(a-i));temp1=(1-k)*(b+1+(b+1-a)+2*(a-i));
		temp+=temp1;
		if(max>temp)max=temp;
	}
	if(b+2<max)max=b+2;
	printf("%f\n",max);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
