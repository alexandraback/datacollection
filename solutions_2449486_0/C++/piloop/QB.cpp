#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

#define cin fin
#define cout fout

int t, test = 1, n, m;
int arr[110][110];
bool mark[110][110];

int main() {
	for( cin >> t; t--; ) {
		cin >> n >> m;
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < m; j++ ) {
				mark[i][j] = false;
				cin >> arr[i][j];
			}
		}
		for( int i = 1; i <= 100; i++ ) {
			for( int j = 0; j < n; j++ ) {
				int good = 0;
				for( int k = 0; k < m; k++ ) {
					if( mark[j][k] || arr[j][k] == i )
						good++;
				}
				if( good == m ) {
					for( int k = 0; k < m; k++ ) {
						mark[j][k] = true;
					}
				}
			}

			for( int j = 0; j < m; j++ ) {
				int good = 0;
				for( int k = 0; k < n; k++ ) {
					if( mark[k][j] || arr[k][j] == i )
						good++;
				}
				if( good == n ) {
					for( int k = 0; k < n; k++ ) {
						mark[k][j] = true;
					}
				}
			}
		}
		bool good = true;
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < m; j++ ) {
				if( !mark[i][j] )
					good = false;
			}
		}
		cout << "Case #" << test++ << ": " << (good ? "YES" : "NO") << endl;
	}
	return 0;
}