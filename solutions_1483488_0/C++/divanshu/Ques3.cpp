#include <iostream>
#include <cstdio>

using namespace std;

int main() {

	int t, T, a, b, i, j, k, l, n, flag, pair, m;
	char x[20], y[20];

	cin >> T;

	for ( t = 1; t <= T; t++ ) {

		pair = 0;

		cout << "Case #" << t << ": ";

		cin >> a >> b;

		for ( i = a; i <= b; i ++ ) {

			for ( k = i; k <= b; k++ ) {

					n = sprintf(y, "%d", k);
					sprintf(x, "%d", i);

					for ( j = 0; j < n; j++ ) {

						if ( y[j] == x[0] ) {

							l = j+1;
							m = 1;
							flag = 1;

							while ( m != n ) {

								if ( l == n ) {
									l = 0;
								}
								if ( y[l] != x[m] ) {
									flag = 0;
									break;
								}
								l++;
								m++;

							}

							if ( flag ) {
								if ( j != 0 )
									pair++;
								break;
							}

						}

					}

			}

		}

		cout << pair << endl;

	}
	
	return 0;
}
