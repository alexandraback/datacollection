#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("C-small-attempt0.out");

#define cin fin
#define cout fout

#define int64 long long
int t, test = 1;
int64 a, b;
int arr[20];
vector< int64 > v;

bool ispalin( int64 a ) {
	int n = 0;
	while( a ) {
		arr[n++] = a % 10;
		a /= 10;
	}
	for( int i = 0; i < n / 2; i++ )
		if( arr[i] != arr[n - 1 - i] )
			return false;
	return true;
}

int main() {
	for( int64 i = 1; i * i <= (int64)(1e14); i++ ) {
		if(ispalin( i ) && ispalin(i * i)) {
			//cout << i << ' ' << i * i << endl;
			v.push_back( i * i );
		}
	}
	for( cin >> t; t--; ) {
		cin >> a >> b;
		int res = 0;
		for( int i = 0; i < v.size(); i++ ) {
			if( v[i] >= a && v[i] <= b ) {
				res++;
			}
		}
		cout << "Case #" << test++ << ": " << res << endl;
	}
	return 0;
}