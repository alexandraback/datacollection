#include<stdio.h>
double p[1000001];
int main()
{
	freopen("D:\\gcj\\A-large.in","r",stdin);
	freopen("D:\\gcj\\A-large.out","w",stdout);
	int tests;
	scanf("%d",&tests);
	for(int test=0;test<tests;test++)
	{
		double bestexp=10000000;
		int A,B;
		scanf("%d %d",&A,&B);
		for(int i=0;i<A;i++){
			scanf("%lf",&p[i]);
		}
		double correctProb=1;
		for(int backSp=A;backSp>=0;backSp--)
		{
			
				if(correctProb*(B-(A-backSp))+(1-correctProb)*(2*B-(A-backSp)+1)+backSp+1<bestexp)
				{
					bestexp=correctProb*(B-(A-backSp))+(1-correctProb)*(2*B-(A-backSp)+1)+backSp+1;
				}
				if(backSp!=0)correctProb*=p[A-backSp];
				else
				{
					if(1+B+1<bestexp)
					  bestexp=B+2;
				}
		}
		//hit enter right now
		printf("Case #%d: %.7lf\n",test+1,bestexp);

	}
}