#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <string>

using namespace std;

int main() {

	int t, T, a, b, i, j, k, n, pair, flag, m;
	char x[20], y[20], z[20], temp[20];

	cin >> T;

	list<string>::iterator it;

	for ( t = 1; t <= T; t++ ) {

		pair = 0;

		cout << "Case #" << t << ": ";

		cin >> a >> b;

		n = sprintf(z, "%d", b);

		for ( i = a; i <= b; i++ ) {

			//cout << i << " - ";
			sprintf(x, "%d", i);
		
			list<string> l;

			for ( j = 1; j < n; j++ ) {

				for ( k = 0; k < j; k++ ) {
					temp[k] = x[k];
				}
				for ( k = j; k < n; k++ ) {
					y[k-j] = x[k];
				}
				for ( k = n-j; k < n; k++ ) {
					y[k] = temp[k-n+j];
				}
				y[k] = '\0';
				flag = 1;

				if ( (strcmp (y, x) > 0) && (strcmp (y, z) <= 0) ) {

					string var;
					for ( m = 0; m <= n; m++ ) {
						var.push_back(y[m]);
					}

					for ( it = l.begin(); it != l.end(); it++ ) {
						if ( var == *it ) {
							flag = 0;
							break;
						}
					}

					if ( flag ) {
						l.push_back(var);
						pair++;
					}

				}

			}

			//cout << endl;

		}

		cout << pair << endl;

	}
	
	return 0;
}
