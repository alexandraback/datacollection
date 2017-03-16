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

ifstream fin("B-large.in");
ofstream fout("B-large.out");

#define cin fin
#define cout fout

int t, n, x, y, test = 1;
int h, len, mrem;
double mem[1500][1500];
bool seen[1500][1500];

double solve( int left, int right ) {
	int rem = mrem - left - right;
	if( left >= h )
		return 1.;
	if( rem == 0 )
		return 0.;
	if( seen[left][right] )
		return mem[left][right];
	seen[left][right] = true;
	double &res = mem[left][right];
	res = 0.;
	if( left < len && right < len ) {
		res = (solve(left + 1, right) + solve( left, right + 1 )) / 2.;
	} else if( left < len ) {
		res = solve( left + 1, right );
	} else {
		res = solve( left, right + 1 );
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
			mrem = n - cur;
			cout.precision( 8 );
			cout.setf( ios::fixed | ios::showpoint );
			cout << solve( 0, 0 ) << endl;
		} else {
			cout << "0.0" << endl;
		}
	}
	return 0;
}