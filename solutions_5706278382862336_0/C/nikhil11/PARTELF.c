#include<stdio.h>
#include<math.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,P,Q,k,i,A,count;
	float a;
	char c;
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
		count=1;
		scanf("%d%c%d",&P,&c,&Q);
		a=log2(Q);
		A=a;
		//printf("%d %f\n",A,a);
		if(A!=a)
		{
			printf("Case #%d: impossible\n",k);
			continue;
		}
		while(P*2<Q)
		{
			Q/=2;
			count++;	
		}
		printf("Case #%d: %d\n",k,count);
	}
	return 0;
}

