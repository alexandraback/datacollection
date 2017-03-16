#include "Math.h"

bool IsPrime(int num)
{
	if(num <= 1) return false;
	if(num == 2) return true;
	if(num % 2 == 0) return false;
	int max = sqrt(num) + 1;
	for(int i = 3; i <= max; i+=2)
	{
		if(num % i == 0) return false;
	}
	return true;
}