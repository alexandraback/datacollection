// Recycled Numbers.cpp
//

#include <cstdio>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
	int numTests = 0;
	cin >> numTests;
	for( int j = 0; j < numTests; ++j )
	{
		int A,B;
		cin >> A >> B;

		int numOfDigits = 1;
		int tmpNum = B;
		while( tmpNum/10 != 0 ) 
		{
			tmpNum /= 10;
			++numOfDigits;
		}

		set< pair<int,int> >recycledPairs;
		for( int i = A; i < B+1; ++i )
		{
			int nextNum = i;
			for( int k = 1; k < numOfDigits; ++k )
			{
				int divisor = int(pow(10.0, numOfDigits - 1));
				nextNum = ((nextNum % divisor) * 10) + (nextNum / divisor);

				if((nextNum <= B) && (nextNum > A) && (nextNum != i) )
				{
					if( nextNum > i )
						recycledPairs.insert(make_pair(i,nextNum));
					else
						recycledPairs.insert(make_pair(nextNum,i));
				}
			}
		}

		printf("Case #%d: %u", j+1, recycledPairs.size() );
		/*
		cout << endl;
		for( set< pair<int,int> >::iterator it = recycledPairs.begin(); it != recycledPairs.end(); ++it )
		{
			cout << (*it).first << "\t" << (*it).second << endl;
		}
		*/

		if( j < (numTests-1) )
			putchar('\n');
	}

	return 0;
}
