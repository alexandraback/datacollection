#include <iostream>

using namespace std;

int main() {

	int t, i, x, n, s, p;
	int zero, one, two;
	int a[150], max0[150], max1[150], max2[150], ans, poss;

	cin >> t;

	for ( x = 1; x <= t; x++ ) {

		ans = 0;
		poss = 0;
		zero = 0;
		one = 0;
		two = 0;

		cin >> n >> s >> p;
		for ( i = 0; i < n; i++ )
			cin >> a[i];

		cout << "Case #" << x << ": ";
		
		for ( i = 0; i < n; i++ ) {
			if ( a[i] % 3 == 0 ) {
				max0[zero] = a[i]/3;
				zero++;
			}
			else if ( a[i] % 3 == 1 ) {
				max1[one] = (a[i]/3) + 1;
				one++;
			}
			else {
				max2[two] = (a[i]/3) + 1;
				two++;
			}
		}

		for ( i = 0; i < zero; i++ ) {
			if ( max0[i] >= p )
				ans++;
			else if ( max0[i] == (p-1) && max0[i] != 0 )
				poss++;
		}
		for ( i = 0; i < one; i++ ) {
			if ( max1[i] >= p )
				ans++;
		}
		for ( i = 0; i < two; i++ ) {
			if ( max2[i] >= p )
				ans++;
			else if ( max2[i] == (p-1) )
				poss++;
		}

		if ( poss < s )
			ans = ans + poss;
		else
			ans = ans + s;

		cout << ans << endl;

	}

	return 0;
}
