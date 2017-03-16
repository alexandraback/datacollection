
#include<iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(true);


	int t;
	cin >> t;

	for (int l = 1; l <= t; l++) {

		long long k, c, s;
		cin >> k >> c >> s;

		int requiredNumber = k / c;
		if (k%c != 0)requiredNumber++;

		if (requiredNumber > s) {
			cout << "Case #" << l << ": IMPOSSIBLE" << endl;
			continue;
		}




		cout << "Case #" << l << ": ";

		for (long long n = 1; n <= k; n++ ) {

			long long place = n;

			for (int m = 1; m < c; m++) {

				place = (place - 1)*k + 1;

				if (n < k) {
					place += n;
					n++;
				}

			}

			cout << place << " ";
		}

		cout << endl;

	}
	return 0;
}

