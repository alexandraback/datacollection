#include <stdio.h>

using namespace std;

#define MAX 99999

int main()
{
	int cases;
	int c=1;
	int typed,total;
	int i;
	double expected,wrong,tmp;
	int strokes[2]; /* 0-correct, 1-wrong] */

	double vals[MAX];

	for(scanf("%d",&cases);cases>0;cases--,c++)
	{
		scanf("%d%d",&typed,&total);
		expected = 2+total; 
		for(i=0;i<typed;i++)
		{
			scanf("%lf",&(vals[i]));
		}
	
		wrong = 0;
		for(i=1;i<=typed;i++)
		{
			strokes[0] = (typed-i)*2 + ((total-typed)+1);
			strokes[1] = strokes[0]+total+1;
			wrong += ((1-wrong)*(1-vals[i-1]));
			tmp = wrong*strokes[1] + (1-wrong)*strokes[0];
			if(tmp<expected)
				expected = tmp;
		}

		printf("Case #%d: %.6lf\n",c,expected);
	}

	return 0;
}
