#include "stdafx.h"

template<>
void Prepare<ProblemC>()
{
}

template<>
void Solve<ProblemC>(Int T)
{
	Int C, D, V;
	C = ReadNum(); // count limit

	D = ReadNum(); // 

	V = ReadNum(); // target

	vector<INT> nums(D);
	Int i;
	for ( i = 0; i < D; i++)
	{
		nums[i] = ReadNum();

	}
	Int sum = 0;
	Int need = 0;
	i = 0;
	while (sum < V)
	{
		if ((i < nums.size() && (sum + 1) < nums[i]) || (i >= nums.size()))
		{
			Int coin = sum + 1;
			nums.insert(nums.begin() + i, coin);
			sum += coin * C;
			need++;
		}
		else
		{
			sum += nums[i] * C;
		}
		i++;
	}
	Write(T, need);
}