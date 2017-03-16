
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

bool isLuck( long long a )
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
	ofstream cout("x.txt");

	typedef map< long long, int > mp;
	mp m;
	int idx = 0;
	for ( long long i = 1; i <= 10000001; ++i )
		if ( isLuck(i) && isLuck(i*i) )
			m[i*i] = ++idx;

	int t;
	cin >> t;

	for ( int q = 0; q < t; ++q )
	{
		long long a, b;
		cin >> a >> b;

		mp::iterator it1 = m.lower_bound(a);
		mp::iterator it2 = --m.upper_bound(b);

		int n;
		if ( it1 == m.end() || it2 == m.end() )
			n = 0;
		else
			n = it2->second - it1->second + 1;
		cout << "Case #" << q+1 << ": " << n << "\n";
	}

	return 0;
}


