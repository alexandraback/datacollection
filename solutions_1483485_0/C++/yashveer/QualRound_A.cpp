#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <fstream>

#define ll long long
#define ull unsigned ll
#define FOR( i, a, b ) for( i = a; i <= b; i++ )
#define REP( i, n ) for( i = 0; i < n ; i++ )
#define pb push_back
#define VI vector<int>
#define VVI vector< vector<int> >
#define VS vector<string>
#define VVS vector< vector<string> >

using namespace std;

int main()
{
	int t, i, j;
	string s, s1;
	map< char, char > m;
	fstream fout( "Qual_A_small.out", ios::out );
	s = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	s1 = "our language is impossible to understand";
	REP( j, s.size() ) {
		m[s[j]] = s1[j];
	}
	s = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s1 = "there are twenty six factorial possibilities";
	REP( j, s.size() ) {
		m[s[j]] = s1[j];
	}
	s = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	s1 = "so it is okay if you want to just give up";
	REP( j, s.size() ) {
		m[s[j]] = s1[j];
	}
	m['q'] = 'z';
	m['z'] = 'q';
	getline( cin, s);
	stringstream( s ) >> t;
	FOR( i, 1, t ) {
		getline( cin ,s );
		REP( j, s.size() ) {
			s[j] = m[s[j] ];
		}
		fout << "Case #" << i << ": " << s << "\n";
	}
	return 0;
}
