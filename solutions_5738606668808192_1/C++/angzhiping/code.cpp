#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	cout << "Case #1:" << endl;
	
	// For this case, denoting the binary as d_{31}d_{30}...d_{0}
	// A class of solutions, which generates 11025 of them, is
	// such that alternate digits of d_{30}...d_{1} sum to 2.
	// The divisors which satisfy the above property are
	// 3 (base 2) 2 3 2 7 2 3 2 3 (base 10)
	const int N = 32;
	const int J = 500;
	
	string divisors = "3 2 3 2 7 2 3 2 3";
	
	int solution_count = 0;
	
	// Permuting placements of the 1
	string odd_digits  = "000000000000011";
	string even_digits = "000000000000011";
	
	do
	{
		
		do
		{
			putchar('1');
			
			for(int i = 0; i < 15; i++)
			{
				putchar(even_digits[i]);
				putchar(odd_digits[i]);
			}
			
			printf("1 %s\n", divisors.c_str());
			
			solution_count++;
			
			if(solution_count == J)
				goto END;
				
		} while(next_permutation(even_digits.begin(), even_digits.end()));
		
	} while(next_permutation(odd_digits.begin(), odd_digits.end()));
	
	END:;
	
	return 0;
}
