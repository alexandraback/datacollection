#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main()
{
	int T;
	cin >> T;
	
	for( int o = 1; o <= T; o++ )
	{
		int x,y;
		
		cin >> x >> y;
		cout << "Case #" << o << ": ";
		
		for (int i = 0; i < fabs(y); i++)
		{
			if( y > 0 )
				cout << "SN";
			else
				cout << "NS";
		}

		for (int i = 0; i < fabs(x); i++)
		{
			if( x > 0 )
				cout << "WE";
			else
				cout << "EW";
		}
		
		cout << endl;
	}
	
	
	return 0;
}
