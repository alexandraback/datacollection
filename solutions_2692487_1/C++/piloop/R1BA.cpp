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
#include <algorithm>

using namespace std;

#define int64 long long
#define pii pair< int, int >

ifstream fin("A-large.in");
ofstream fout("A-large.out");

#define cin fin
#define cout fout

int t, n, a, arr[200], test = 1;

int main() {
	for( cin >> t; t--; ) {
		cin >> a >> n;
		for( int i = 0; i < n; i++ ) {
			cin >> arr[i];
		}
		sort( arr, arr + n );
		int mn = n;
		if( a != 1 ) {
			for( int i = 0; i <= n; i++ ) {
				int sz = a;
				int moves = i;
				for( int j = 0; j < n - i && moves < n; j++ ) {
					while( arr[j] >= sz && moves < n ) {
						sz += sz - 1;
						moves++;
					}
					sz += arr[j];
				}
				mn = min( mn, moves );
			}
		}
		cout << "Case #" << test++ << ": " << mn << endl;
	}
	return 0;
}