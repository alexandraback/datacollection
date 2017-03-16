#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int A,B,K;
	int T,t;
	scanf("%d",&T);
	int i,j;
	int Ans;
	for(t=1;t<=T;t++)
	{
		Ans=0;
		scanf("%d %d %d",&A,&B,&K);
		for(i=0;i<A;i++) for(j=0;j<B;j++) if((i&j)<K) Ans++;
		printf("Case #%d: ",t);
		printf("%d\n",Ans);
	}
}