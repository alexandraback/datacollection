// iruC curi.yun@gmail.com
#include <iostream>
#include <fstream>
#include <math.h>

// No sanity checking on parameters or input files...

// Numbers are always >= 1
inline bool palindrome( long num )
{
	long numCopy = num;
	long reversed = 0;

	while( numCopy > 0 )
	{
		reversed = (reversed*10) + (numCopy % 10);
		numCopy = numCopy / 10;
	}
	return (reversed == num);
}


long fairAndSquare( long A, long B )
{
	long searchMin = (long)sqrt(A);
	long searchMax = (long)sqrt(B);
	long count = 0;

	for( long num = searchMin; num <= searchMax; ++num )
	{
		if( palindrome(num) )
		{
			long squareNum = num*num;
			if( squareNum >= A && squareNum <= B && palindrome(squareNum) )
			{
				++count;
			}
		}
	}
	return count;
}

int main( int argc, char** argv )
{
	char dummy[10];
	int testCases;
	long A, B;
	std::ifstream inFile(argv[1], std::ifstream::in);

	inFile >> testCases;
	inFile.getline(dummy, sizeof(dummy));

	for( int i = 0; i < testCases; ++i )
	{
		inFile >> A >> B;
		inFile.getline(dummy, sizeof(dummy));

		std::cout << "Case #" << (i+1) << ": ";
		std::cout << fairAndSquare(A, B) << std::endl;
	}

	inFile.close();
}
