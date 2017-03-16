
#include "stdio.h"
#include <string>

#define MAX_NUM 2500

class Solver
{
	int N;
	int count[MAX_NUM];
public:
	Solver()
		:N(0)
	{
		for (int i = 0; i < MAX_NUM; i++)
			count[i] = 0;
	}
	int ReadProblem()
	{
		scanf("%d", &N);
		for (int l = 0; l < 2*N-1; l++)
		{
			for (int c = 0; c < N; c++)
			{
				int num;
				scanf("%d", &num);
				if ((num < 1) || (num >= MAX_NUM))
					return -1;
				count[num-1] ++;
			}
		}
	}
	int SolveAndPrint()
	{
		int count_to_check = 0;
		for (int i = 0; i <= MAX_NUM; i++)
		{
			if (count[i] % 2 == 1)
			{
				printf(" %d", i + 1);
				count_to_check++;
			}
		}
		if (count_to_check != N)
		{
			printf(" ERROR!(output num= %d)\n", count_to_check);
			return -1;
		}
		printf("\n");
		return 0;
	}
};


int main(int argc, char* argv[])
{

	int num;
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
	{
		Solver solver;
		solver.ReadProblem();
		printf("Case #%d:", i);
		solver.SolveAndPrint();
	}

	return 0;
}

