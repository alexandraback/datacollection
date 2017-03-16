#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests;
	long long n;
	cin >> tests;
	size_t sz = 0;
	long long a[1000001];
	long long b[1000001];
	for (long long j = 2; j <= 1000000; ++j) {
		string str = to_string(j);
		for (int i = 0; i < str.length() / 2; ++i) {
			char ch = str[i];
			str[i] = str[str.length() - 1 - i];
			str[str.length() - 1 - i] = ch;
		}
		long long y = stoll(str);
		if ((y < j) && (str[0] != '0')) {
			a[j] = y;
		} else {
			a[j] = j - 1;
		}
	}
	for (int t = 1; t <= tests; ++t) {
		cin >> n;
		b[1] = 1;
		for (long long i = 2; i <= n; ++i) {
			b[i] = min(b[i - 1], b[a[i]]) + 1;
		}
		// sort(a, a + d);
		cout << "Case #" << t << ": " << b[n] << endl;
	}
	return 0;
}