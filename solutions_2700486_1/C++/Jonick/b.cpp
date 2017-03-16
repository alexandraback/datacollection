#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

double a[2000][2000];

void initCnk()
{
	a[0][0] = 1.0;
	for( int i = 1; i < 2000; i++ ) {
		a[0][i] = a[0][i-1] / 2.0;
	}
	for( int j = 1; j < 2000; j++ ) {
		for( int i = 1; i < 2000; i++ ) {
			a[i][j] = 0.5 * a[i-1][j-1] + 0.5 * a[i][j-1];
		}
	}
}

double cnk( int k, int n ) {
	return a[k][n];
}

void solveTest()
{
	int N, X, Y;
	cin >> N >> X >> Y;
	int cur = 0;
	int n = N;
	while( true ) {
		int next = cur * 2 + 1;
		if( next >= n ) {
			if( abs(X) + abs(Y) > cur ) {
				cout << "0.0" << endl;
				return;
			} else if( abs(X) + abs(Y) < cur ) {
				cout << "1.0" << endl;
				return;
			} 
			if( X == 0 ) {
				if( next != n ) {
					cout << "0.0" << endl;
				} else {
					cout << "1.0" << endl;
				}
				return;
			}
			if( next == n ) {
				cout << "1.0" << endl;
				return;
			}
			double sum = 0.0;
			double sum2 = 0.0;
			for( int i = 0; i <= cur; i++ ) {
				if( n - i >= 0 && n - i <= cur ) {
					sum2 += cnk(i,n);
					if( i > Y ) {
						sum += cnk(i,n);
					}
				}
			}
			cout << setprecision(10) << sum / sum2 << endl;
			break;
		}
		n -= next;
		cur += 2;
	}
}

void run()
{
	int tn;
	cin >> tn;
	initCnk();
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