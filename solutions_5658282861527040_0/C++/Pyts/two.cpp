#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
	ifstream input ("input2.in");
	ofstream output ("answer2.txt");
	output << fixed;
	int t;
	input >> t;
	for( int k = 1; k <= t; ++k )
	{
		int A,B,K;
		input >> A >> B >> K;

		int num = A+B-1;
		for( int i = 1; i < B; ++i )
		{
			for( int j = 1; j < A; ++j )
			{
				if( (i & j) < K )
					++num;
			}
		}
		output << "Case #" << k << ": " << num << endl;
	}
	input.close();
	output.close();
}
