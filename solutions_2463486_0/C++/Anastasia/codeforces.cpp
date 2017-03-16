
#include <iostream>
#include <fstream>
#include <sstream>
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

bool isLuck( int a )
{
	stringstream s;
	s << a;
	string n = s.str();

	for ( int i = 0; i < n.size()/2; ++i )
		if ( n[i] != n[n.size()-i-1] )
			return false;

	return true;
}
int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");

	int t;
	cin >> t;

	for ( int q = 0; q < t; ++q )
	{
		int a, b;
		cin >> b >> a;

		int x = 0;
		for ( int i = b; i <= a; ++i )
			if ( isLuck(i) )
			{
				int w = sqrt(i);
				if ( w*w == i && isLuck(w) )
					++x;
			}

		cout << "Case #" << q+1 << ": " << x << "\n";
	}

	return 0;
}


