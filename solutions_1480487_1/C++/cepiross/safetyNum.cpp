#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>


int compare(const void *a, const void *b)
{
	double temp1 = *(double *)a;
	double temp2 = *(double *)b;

	return (int)(temp1 - temp2);
}
void GetJudge(int nContestants)
{
	int		iter, nCnt=0, nTemp, nTotal=0;
	int		nJudges[200];
	double	lfTarget, lfFraction[200];

	for(iter=0; iter<nContestants; iter++)
	{
		scanf("%d", &nJudges[iter]);
		nTotal += nJudges[iter];
	}

	nTemp = 2.0*nTotal;
	lfTarget = nTemp/(double)nContestants;
	for(iter=0; iter<nContestants; iter++)
	{
		if(lfTarget < nJudges[iter])
		{
			nCnt++;
			nTemp -= nJudges[iter];
		}
	}
	lfTarget = nTemp/(double)(nContestants-nCnt);

	for(iter=0; iter<nContestants; iter++)
	{
		lfFraction[iter] = (double)(lfTarget-nJudges[iter])*100.0/nTotal;

		//printf(" %.6lf", (double)(((lfFraction[iter]<0)? 0 : lfFraction[iter])/100.0 * nTotal + nJudges[iter]));
		printf(" %.6lf", (lfFraction[iter]<0)? 0 : lfFraction[iter]);
	}

	printf("\n");
}


int main(void)
{
    clock_t				start_time = clock();
	char				iter;
	int					nCounts, nContestants;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d\n", &nCounts);

	for(iter=0; iter<nCounts; iter++)
	{
		scanf("%d", &nContestants);

		printf("Case #%d:", iter+1);
		GetJudge(nContestants);
	}	

	fcloseall();
	fprintf(stderr, "Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);

	return 0;
}