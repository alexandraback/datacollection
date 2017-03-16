#include <iostream>
#include <tr1/unordered_set>
using namespace std;

int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int main() {
	int test_count;
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		int a, b;
		cin >> a >> b;
		int digits = 0;
		int aa = a;
		while (aa > 0) {
			digits += 1;
			aa /= 10;
		}

		int count = 0;
		tr1::unordered_set<int> mm;
		for (int n = a; n < b; ++n) {
			mm.clear();
			for (int k = 1; k < digits; ++k) {
				int m = n / p10[k] + (n % p10[k]) * p10[digits - k];
				if (m > n && m <= b) {
					mm.insert(m);
				}
			}
			count += mm.size();
		}

		cout << "Case #" << test << ": " << count << endl;
	}
}
