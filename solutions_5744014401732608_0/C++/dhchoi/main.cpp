#include <iostream>
#include <string>
#include <sstream>

using namespace std;

long long iMaxCnt[51];
int t, b;
void makePath( int** arrPath, int iStartIdx )
{
	for( int i = iStartIdx + 1; i <= b; i++ )
	{
		arrPath[iStartIdx][i]	= 1;
		makePath( arrPath, i );
	}
}

void main() {
	
	long long m;
	string str;
	cin >> t;  // read t. cin knows that t is an int, so it reads it as such.	
	
	iMaxCnt[2]	= 1;
	for( int i = 3; i <= 50; i++ )
	{
		iMaxCnt[i]	= 0;
		for(int j = 2; j < i; j++ )
		{
			iMaxCnt[i]	+= iMaxCnt[j];
		}
		iMaxCnt[i]++;
	}
	for (int i = 1; i <= t; ++i) {
		cin >> b;
		cin >> m;
		int iOrigM	= m;
		if( iMaxCnt[b] < m )
		{
			
			cout << "Case #" << i << ": IMPOSSIBLE" << endl;
			continue;
		}

		int** arrPath	= new int*[b + 1];
		for( int j = 1; j <= b; j++ )
		{
			arrPath[j]	= new int[b + 1];
			for( int k = 1; k <= b; k++ )
			{
				arrPath[j][k] = 0;
			}
		}

		for( int j = b - 1; j >= 2; j-- )
		{			
			if( m >= iMaxCnt[j] )
			{
				arrPath[1][b - j + 1] = 1;
				m	-= iMaxCnt[j];
				makePath( arrPath, b - j + 1 );
			}
		}

		if( m == 1 )
		{
			arrPath[1][b]	= 1;
			m--;
		}

		if( m > 0 )
		{
			cout << "Case #" << i << ": FAILED" << endl;
			continue;
		}
				
		cout << "Case #" << i << ": POSSIBLE" << endl;
			
		for( int j = 1; j <= b; j++ )
		{
			for( int k = 1; k <= b; k++ )
			{
				cout << arrPath[j][k];
			}
			cout << endl;
		}


	}

	int a;
	cin >> a;


}