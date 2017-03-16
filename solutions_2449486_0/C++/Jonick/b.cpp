#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

void solveTest()
{
	int n,m;
	cin >> n >> m;
	vector< vector<int> > a( n, vector<int>(m) );
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			cin >> a[i][j];
		}
	}
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			bool hor = true;
			for( int k = 0; k < n; k++ ) {
				if( a[k][j] > a[i][j] ) {
					hor = false;
					break;
				}
			}
			bool ver = true;
			for( int k = 0; k < m; k++ ) {
				if( a[i][k] > a[i][j] ) {
					ver = false;
					break;
				}
			}
			if( !hor && !ver ) {
				cout << "NO" << endl;
				return;
			}
		}

	}
	cout << "YES" << endl;
}

void run()
{
	int tn;
	cin >> tn;
	for( int i = 0; i < tn; i++ ) {
		cout << "Case #" << (i+1) << ": ";
		solveTest();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	run();
	return 0;
}