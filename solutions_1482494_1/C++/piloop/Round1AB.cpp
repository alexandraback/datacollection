#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

ifstream fin( "B-large.in" );
ofstream fout( "B-large.out" );

#define cin fin
#define cout fout

int t, n;
int arr[2000][2];
int mark[2000];

int main() {
	cin >> t;
	for( int T = 0; T < t; T++ ) {
		cerr << T << endl;
		memset( mark, 0, sizeof mark );
		cin >> n;
		for( int i = 0; i < n; i++ ) {
			cin >> arr[i][0] >> arr[i][1];
		}
		int cur = 0;
		int res = 0;
		while( cur != 2 * n ) {
			int id1 = -1, id2 = -1;
			for( int i = 0; i < n; i++ ) {
				if( mark[i] != 2 && arr[i][1] <= cur ) {
					id1 = i;
				} 
				if( mark[i] == 0 && arr[i][0] <= cur  && (id2 == -1 || (arr[id2][1] < arr[i][1])) ) {
					id2 = i;
				}
			}
			if( id1 != -1 ) {
				cur += 2 - mark[id1];
				mark[id1] = 2;
			} else if(id2 != -1) {
				cur += 1;
				mark[id2] = 1;
			} else {
				break;
			}
			res++;
		}
		cout << "Case #" << T + 1 << ": ";
		if( cur != 2 * n )
			cout << "Too Bad" << endl;
		else
			cout << res << endl;
	}
	return 0;
}
