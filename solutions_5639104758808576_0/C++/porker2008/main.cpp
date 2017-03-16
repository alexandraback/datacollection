#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin.sync_with_stdio(false);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int smax;
		string s;
		cin >> smax >> s;
		long long ans = 0, total = 0;
		for (int i = 0; i <= smax; i++) {
			if (total < i) {
				ans += i - total;
				total = i;
			}
			total += s[i] - '0';
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
}