
#include "stdio.h"

typedef unsigned long long ANSWER_T;
#define MAX_ANSWER  100

// in solver, leftmost position is 0 insted of 1

ANSWER_T FindPos(int p, int k, int c)
{
	// return one of the position where all of p, p+1, ... P+c-1 in base is L then L.
	ANSWER_T rv = 0;
	for (int i = 0; i < c; i++)
	{
		rv *= k;
		if (p < k)
			rv += p;
		p++;
	}
	return rv;
}

int Solve(ANSWER_T* ans, int k, int c, int s)
{
	//first, check if find. 
	if (k > c*s)
		return 0;
	int rv = ((k + c - 1) / c);
	for (int i = 0; i < rv; i++)
		ans[i] = FindPos(i*c, k, c);
	return rv;
}



int main(int argc, char* argv[])
{

	int num;
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
	{
		int K, C, S;
		ANSWER_T answers_set[MAX_ANSWER];
		int num_answer_set;
		scanf("%d %d %d", &K, &C, &S);
		if (S > MAX_ANSWER)
		{
			// input error
			return -1;
		}
		num_answer_set = Solve(answers_set, K, C, S);
		if (num_answer_set > 0)
		{
			printf("Case #%d:", i);
			for (int i = 0; i < num_answer_set; i++)
				printf(" %llu", answers_set[i]+1);
			printf("%\n");
		}
		else
		{
			printf("Case #%d: IMPOSSIBLE\n", i);
		}
	}

	return 0;
}

