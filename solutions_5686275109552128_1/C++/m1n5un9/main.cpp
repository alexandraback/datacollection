#include <stdio.h>


//int MAX_SEED_NUM = 9; // for small input
int MAX_SEED_NUM = 1000; // for large input

int P[1001];

int getSplitTurns(int num, int seedNum)
{
	if(num < seedNum) return 0;
	if(seedNum == 1) return num - 1;
		
	return (num-1)/seedNum;
}
int main(void)
{
	int T, test_case;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		int D;
		scanf("%d",&D);
		for(int i=0; i < D;i++)
		{
			scanf("%d",&P[i]);
		}

		int minTurns = 10000000;

		for(int i=1;i <= MAX_SEED_NUM; i++)
		{
			int sumTurns = 0;
			for(int j = 0; j < D; j++)
			{
				sumTurns += getSplitTurns(P[j],i);
			}
			sumTurns += i;
			if(minTurns > sumTurns) minTurns = sumTurns;
		}


		// Print the answer to standard output(screen).
		printf("Case #%d: %d\n", test_case+1, minTurns);
	}

	return 0;//Your program should return 0 on normal termination.
}
