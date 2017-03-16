#include <iostream>
#include <string>
using namespace std;

int solve() {
	int s, cnt = 0, ans = 0;
	string line;
	cin >> s >> line;
	for (int i = 0; i <= s; i ++)
		if (line[i] != '0') {
			if (cnt < i) {
				ans += (i - cnt);
				cnt = i;
			}
			cnt += (line[i] - '0');
		}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
