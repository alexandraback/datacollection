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
	int t, n, s, p, x, i, ans, j, a, b;
	fstream fout( "Qual_B_large.out", ios::out );
	fstream fin( "B-large.in", ios::in );
	fin >> t;
	FOR( i, 1, t ) {
		fin >> n;
		fin >> s;
		fin >> p;
		a = max( 3*p-2, p );
		b = max( 3*p-4, p );
		ans = 0;
		while( n ) {
			fin >> x;
			if( x >= a ) ans++;
			else if( x >= b && s > 0 ){
				ans++;
				s--;
			}
			n--;
		}
		fout << "Case #" << i << ": " << ans << "\n";
		cout << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}
