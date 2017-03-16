
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <cstring>
using namespace std;

string s[4];

void check( int i, int j, int& x, int& o, bool& finished )
{
	switch( s[i][j] )
	{
	case '.':
		finished = false;
		break;
	case 'X':
		++x;
		break;
	case 'O':
		++o;
		break;
	case 'T':
		++x;
		++o;
		break;
	}
}

bool iswon( int x1, int x2, int o1, int o2, std::ofstream& cout )
{
	if ( x1 == 4 || x2 == 4 )
	{
		cout << "X won\n";
		return true;
	}
	if ( o1 == 4 || o2 == 4 )
	{
		cout << "O won\n";
		return true;
	}

	return false;

}

int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");

	int t;
	cin >> t;

	for ( int i = 0; i < t; ++i )
	{
		cin >> s[0] >> s[1] >> s[2] >> s[3];

		cout << "Case #" << i+1 << ": ";

		bool won = false;
		bool finished = true;
		int x1=0, x2 = 0, o1 = 0, o2 = 0;

		for ( int j = 0; j < 4; ++j )
		{
			check( j, j, x1, o1, finished );
			check( 4-j-1, j, x2, o2, finished );
		}

		if ( iswon( x1, x2, o1, o2, cout) )
			continue;

		for ( int j = 0; j < 4; ++j )
		{
			x1=0, x2 = 0, o1 = 0, o2 = 0;
			for ( int k = 0; k < 4; ++k )
			{
				check( j, k, x1, o1, finished );
				check( k, j, x2, o2, finished );
			}
			if ( iswon( x1, x2, o1, o2, cout) )
			{
				won = true;
				break;
			}
		}

		if ( !won )
		{
			if ( finished )
				cout << "Draw\n";
			else
				cout << "Game has not completed\n";
		}
	}

	return 0;
}


