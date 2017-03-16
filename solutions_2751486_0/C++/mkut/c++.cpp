#include <iostream>
#include <vector>
using namespace std;

bool isVowels(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u';
}

long long sigma(long long n) {
	return n < 0 ? 0 : n * (n + 1) / 2;
}

int main() {
	int T; cin >> T;
	for (int caseNo = 1; caseNo <= T; caseNo++) {
		string str; cin >> str;
		int n; cin >> n;
		int m = str.length();

		long long ans = sigma(m - n + 1);
		long long accum = 0, accum2 = 0;
		for (int i = 0; i < m; i++) {
			if (isVowels(str[i])) {
				accum = 0;
			} else {
				accum++;
			}
			if (i >= n - 1) {
				if (accum >= n) {
					ans -= sigma(accum2);
					accum2 = 0;
				} else {
					accum2++;
				}
			}
		}
		ans -= sigma(accum2);

		cout << "Case #" << caseNo << ": " << ans << endl;
	}
	return 0;
}
