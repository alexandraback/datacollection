
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

struct Cell
{
	Cell() : leaf(false) {}
	set<int> vals;
	bool leaf;
	int sum;
};

bool next( vector<char>& s )
{
	int m = 0;
	while(m < s.size() && s[m] == 2 )
	{
		s[m] = 0;
		m++;
	}

	if ( m+1 == s.size() )
		return false;

	s[m]++;
	return true;
}

void test( int _case, FILE* pf, ifstream& cin )
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for ( int i = 0; i < n; i++ )
		cin >> v[i];

	vector<char> s;
	s.resize( n, 0 );

	fprintf(pf, "Case #%d:\n", _case);

	while( next(s) )
	{
		int s1 = 0; int s2 = 0;
		for ( int i = 0; i < s.size(); i++ )
		{
			if ( s[i] == 1 )
				s1 += v[i];
			else
				if ( s[i] == 2 )
					s2 += v[i];
		}

		if ( s1 == s2 )
		{
			for ( int i = 0; i < s.size(); i++ )
			{
				if ( s[i] == 1 )
					fprintf(pf, "%d ", v[i]);
			}
			fprintf(pf, "\n");
			for ( int i = 0; i < s.size(); i++ )
			{
				if ( s[i] == 2 )
					fprintf(pf, "%d ", v[i]);
			}
			fprintf(pf, "\n");
			return;
		}
	}
		
	fprintf(pf, "Impossible\n");
}

int main()
{
	ifstream cin("a.in");
	FILE* pf = fopen( "out.txt", "w");
	
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ )
	{
		test(i+1, pf, cin);		
	}

	return 0;
}