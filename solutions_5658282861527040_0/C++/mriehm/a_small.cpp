#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

unsigned int compare_bits[40];
unsigned int full_bits[40];
/*
unsigned int lessThan(unsigned int num1, unsigned int num2, unsigned int bought)
{
	unsigned long total = 0;
	unsigned long multiplier = 1;

	unsigned int max_overall = min(max_a, max_b);
	unsigned int max_max = max(max_a, max_b);

	unsigned int highest_bit = 0;
	for (unsigned int index = 31; index >= 0; --index)
	{
		if (compare_bits[index] & max_bought)
		{
			highest_bit = index;
			break;
		}
	}

	if (highest_bit == 0)
	{
		if (compare_bit[index] & max_bought[index])
		{
			if (compare_bits[index] & max_a)
			{
				if (compare_bits[index] & max_b)
				{
					return 4;
				}
				else
				{
					return 2;
				}
			}
			else if (compare_bits[index & max_b])
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}

	if (compare_bits[index] & max_a)
	{
		if (compare_bits[index] & max_b)
		{
			if (compare_bit[index] & max_bought[index])
			{
				if(index > 0)
				{
					total += full_bits[index - 1] * 2;
				}
			}
			else
			{
			}
		}
		else
		{
			if (compare_bit[index] & max_bought[index])
			{
			}
			else
			{
			}
		}
	}
	else if (compare_bits[index & max_b])
	{
		if (compare_bit[index] & max_bought[index])
		{
		}
		else
		{
		}
	}
	else
	{
		if (compare_bit[index] & max_bought[index])
		{
		}
		else
		{
		}
	}

	return total;
}
*/
int main(void)
{
	unsigned int number_of_tests;
	scanf("%u\n", &number_of_tests);

	for (unsigned int index = 0; index < 32; ++index)
	{
		compare_bits[index] = 1 << index;
	}

	full_bits[0] = 1;
	for (unsigned int index = 1; index < 32; ++index)
	{
		full_bits[index] = (full_bits[index - 1] << 1) + 1;
	}

	for (unsigned int test = 0; test < number_of_tests; ++test)
	{
		printf("Case #%u: ", test + 1);

		unsigned int max_a;
		unsigned int max_b;
		unsigned int max_bought;
		scanf("%u %u %u\n", &max_a, &max_b, &max_bought);
/*
		if (max_a == 0 || max_b == 0 || max_c == 0)
		{
			cout << "0" << endl;
			continue;
		}
*/
		unsigned int count = 0;

		for (unsigned int number = 0; number < max_a; ++number)
		{
			for (unsigned int number2 = 0; number2 < max_b; ++number2)
			{
				if ((number2 & number) < max_bought)
				{
					++count;
				}
			}
		}

		cout << count << endl;

	}
}
