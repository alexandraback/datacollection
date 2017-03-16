#include<stdio.h>
#define LL long long
int main()
{	
	int T,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
	LL r,t;
	scanf("%lld %lld",&r,&t);
	LL n=1,prev=0;
	LL prod=2*n*n+n*(2*r-1);
	while(prod<=t)
		{
			prev=n;
			n*=2;
			prod=2*n*n+n*(2*r-1);
	}
	n/=2;
	prod=2*n*n+n*(2*r-1);
	while(prod<=t)
		{
			prev=n;
			n++;
			prod=2*n*n+n*(2*r-1);
	}
	n--;
	printf("Case #%d: %lld\n",i,n);
	}
}
