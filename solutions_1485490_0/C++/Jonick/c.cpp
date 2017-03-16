#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

void solveTest()
{
	int n, m;
	cin >> n >> m;
	vector<int> a1(n);
	vector<long long> b1(n);
	vector<int> a2(m);
	vector<long long> b2(m);
	for( int i = 0; i < n; i++ ) {
		cin >> b1[i] >> a1[i];
	}
	vector< vector< map<long long, long long> > > a( n + 1, vector< map<long long, long long> >(m + 1));
	for( int i = 0; i < m; i++ ) {
		cin >> b2[i] >> a2[i];
	}
	a[0][0][0] = 0;
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			for( map<long long, long long>::iterator it = a[i][j].begin(); it != a[i][j].end(); it++ ) {
				long long value = (*it).first;
				long long av1 = b1[i];
				long long av2 = b2[j];
				if( value > 0 ) {
					av1 = value;
				} else if( value < 0 ) {
					av2 = -value;
				}
				if( a1[i] == a2[j] ) {
					if( av1 < av2 ) {
						a[i+1][j][av1-av2] = std::max(a[i+1][j][av1-av2], a[i][j][value] + av1);
					} else if( av1 == av2 ) {
						a[i+1][j+1][0] = std::max(a[i+1][j+1][0], a[i][j][value] + av1);
					} else {
						a[i][j+1][av1-av2] = std::max(a[i][j+1][av1-av2], a[i][j][value] + av2);
					}
				} else {
					if( value >0 ) {
						a[i+1][j][0] = std::max( a[i][j][value], a[i+1][j][0] );
						a[i][j+1][value] = std::max( a[i][j][value], a[i][j+1][value] );
					} else if( value < 0 ) {
						a[i+1][j][value] = std::max( a[i][j][value], a[i+1][j][value] );
						a[i][j+1][0] = std::max( a[i][j][value], a[i][j+1][0] );
					} else {
						a[i+1][j][0] = std::max( a[i][j][value], a[i+1][j][0] );
						a[i][j+1][0] = std::max( a[i][j][value], a[i][j+1][0] );
					}
				}
			}
		}
	}
	long long res = 0;
	for( int i = 0; i <= n; i++ ) {
		for( int j = 0; j <= m; j++ ) {
			for( map<long long, long long>::iterator it = a[i][j].begin(); it != a[i][j].end(); it++ ) {
				res = std::max( res, (*it).second );
			}
		}
	}
	cout << res << endl;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tn;
	cin >> tn;
	for( int i = 0; i < tn; i++ ) {
		cout << "Case #" << (i+1) << ": ";
		solveTest();
	}
	return 0;
}
