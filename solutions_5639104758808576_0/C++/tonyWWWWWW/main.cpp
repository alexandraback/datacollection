#include <iostream>

using namespace std;

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.txt", "w", stdout);
	int T = 0;
	cin >> T;
	int t = 0;
	while (t < T) {
		if (t != 0) cout << endl;
		int S = 0;
		cin >> S;
		char *s = new char[S + 1];
		cin >> s;
		int ans = 0;
		int stand = 0;
		for (int i = 0; i < S + 1; i++) {
			if (stand < i) {
				ans += (i - stand);
				stand = i;
			}
			stand += s[i] - '0';
		}
		cout << "Case #" << t + 1 << ": " << ans;
		t++;
	}
}