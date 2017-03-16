
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <vector>

int GetNumberOfDigits(int num)
{
	int digits = 1;
	while (num >= 10)
	{
		num /= 10;
		digits += 1;
	}
	return digits;
}

int CycleNumber(int num, int numberOfDigits)
{
	int lastDigit = num % 10;
	for (int i = 0; i < numberOfDigits-1; i++)
	{
		lastDigit *= 10;
	}
	return (num/10 + lastDigit);
}

int GetRecycledCount(int A, int B)
{
	int count = 0;

	for (int i = A; i < B+1; i++)
	{
		int numDigits = GetNumberOfDigits(i);

		int num = i;

		do
		{		
			num = CycleNumber(num, numDigits);
			if (num > i && num <= B)
			{
				count++;	
			}
		}		
		while (num != i);
	}

	return count;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Please provide an input file\n");
		return 1;
	}
	std::fstream fin;
	fin.open(argv[1]);

	int testCases = 0;
	fin >> testCases;

	for (int i = 0; i < testCases; i++)
	{
		int A, B;
		fin >> A >> B;
		printf("Case #%d: %d\n", i+1, GetRecycledCount(A,B));
	}

	fin.close();
	return 0;
}



