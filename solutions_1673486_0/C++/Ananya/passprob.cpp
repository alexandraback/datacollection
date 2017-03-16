#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXL 100001

double correctProb[MAXL];
double cumCorrectProb[MAXL]; //Probability first error occurs at index i

int main ()
{
	int T, curl, pl, i;
	double s, cumcor, best;
	scanf("%d",&T);
	
	for ( int cnt = 1; cnt <= T; cnt++ )
	{
		cumCorrectProb[0] = 1;
		scanf("%d %d",&curl,&pl);
		
		for ( i = 1; i <= curl; i++ )
		{
			scanf("%lf",&correctProb[i]);
			cumCorrectProb[i] = cumCorrectProb[i-1]*correctProb[i];
		}
		
		best = pl+2;
		
		for ( i = 0; i <= curl; i++ )
		{
			s = cumCorrectProb[i] * (curl+pl-2*i+1);
			s += (1-cumCorrectProb[i]) * (curl+pl-2*i+1+pl+1);
			best = min(best,s);
		}
		
		printf("Case #%d: %lf\n",cnt,best);
	}
}
