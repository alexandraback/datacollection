#include <stdio.h>

int CL[50][50];
int main()
{
	int T,i,R,C,W,j;
	scanf("%d",&T);

	for(i = 1; i <= 10; ++i)
	{
		CL[1][i] = i;
		CL[i][i] = i;
	}

	for(i = 1; i <= 10; ++i)
	{
		for(j = i+1; j <= (2*i) && j <= 10; ++j)
			CL[i][j] = i+1;

		for(j = (2*i)+1; j <= 10; ++j)
			CL[i][j] = 1+CL[i][j-i];
	}


	for(i = 1; i <= T; ++i)
	{
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &W);

		printf("Case #%d: %d\n",i, CL[W][C]);
	}

	return 0;
}