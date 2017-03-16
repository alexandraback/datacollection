#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

#define int64 long long
#define pii pair< int, int >

ifstream fin("B-small-attempt1.in");
ofstream fout("B-small-attempt1.out");

#define cin fin
#define cout fout

int t, n, x, y, test = 1;
int h, len;
double mem[30][30][30];
bool seen[30][30][30];

double solve( int left, int right, int rem ) {
	if( left >= h )
		return 1.;
	if( rem == 0 )
		return 0.;
	if( seen[left][right][rem] )
		return mem[left][right][rem];
	seen[left][right][rem] = true;
	double &res = mem[left][right][rem];
	res = 0.;
	if( left < len && right < len ) {
		res = (solve(left + 1, right, rem - 1) + solve( left, right + 1, rem - 1 )) / 2.;
	} else if( left < len ) {
		res = solve( left + 1, right, rem - 1 );
	} else {
		res = solve( left, right + 1, rem - 1 );
	}
	return res;
}

int main() {
	for( cin >> t; t--; ) {
		cin >> n >> x >> y;
		int width = 0;
		int cur = 0;
		for( int i = 1; cur + i <= n; i += 4, width++ )
			cur += i;
		//cout << cur << ' ' << width << endl;
		cout << "Case #" << test++ << ": ";
		int loc = (abs( x ) + abs( y )) / 2;
		if( loc < width ) {
			cout << "1.0" << endl;
		} else if( loc == width && x != 0 ) {
			memset( seen, false, sizeof seen );
			h = abs( y ) + 1;
			len = width * 2;
			cout.precision( 8 );
			cout.setf( ios::fixed | ios::showpoint );
			cout << solve( 0, 0, n - cur ) << endl;
		} else {
			cout << "0.0" << endl;
		}
	}
	return 0;
}