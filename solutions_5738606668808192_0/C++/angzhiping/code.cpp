#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	cout << "Case #1:" << endl;
	
	// For this case, denoting the binary as d_{15}d_{14}...d_{0},
	// there are two admissible cases: when alternate digits in
	// d_{14}...d_{1} sums to either 2 or 5. The set of divisors
	// for which this property holds is 3 (base 2), 2 3 2 7 2 3 2 3 (base 10),
	// giving a total of 882 cases. But then we can brute force can't we
	const int N = 16;
	const int J = 50;
	
	string divisors = "3 2 3 2 7 2 3 2 3";
	
	int solution_count = 0;
	
	for(int mask = 0; mask < (1 << 14); mask++)
	{
		unsigned int odd_digits = (unsigned int) mask & (0x5555);
		unsigned int even_digits = (unsigned int) mask & (~0x5555);
		
		if((__builtin_popcount(odd_digits) == 2 && __builtin_popcount(even_digits) == 2) ||
		   (__builtin_popcount(odd_digits) == 5 && __builtin_popcount(even_digits) == 5))
		{
			putchar('1');
			
			for(int shift = 13; shift >= 0; shift--)
				putchar((mask & (1 << shift)) ? '1' : '0');
			
			printf("1 %s\n", divisors.c_str());
			
			solution_count++;
			
			if(solution_count == J)
				break;
		}
	}
	
	return 0;
}
