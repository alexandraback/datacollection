#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const int inf = 1e9;
const double eps = 1e-9;
const int size = 1000;

set <int> digits;

bool erase_digits (set <int> &a, int n) {
	while (n > 0) {
		a.erase(n % 10);
		n /= 10;
	}
	return a.empty();
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	int n;

	cin >> t;
	for (int it = 0; it < t; it++){
		cin >> n;
		if (n == 0) {
			cout << "Case #" << it + 1 << ": ";
			cout << "INSOMNIA" << endl;
			continue;
		}
		digits.clear();
		for (int i = 0; i < 10; i++)
			digits.insert(i);
		for (int i = 0; i < 1000; i++) {
			if (i > 99) {
				cout << "Uau!" << endl;
				return 0;
			}
			if (erase_digits(digits, n * i)) {
				cout << "Case #" << it + 1 << ": ";
				cout << n * i << endl;
				break;
			}
		}
	}

	return 0;
}