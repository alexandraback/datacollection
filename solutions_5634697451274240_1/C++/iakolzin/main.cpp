#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string s;
		cin >> s;
		s.push_back('+');
		int ans = 0;
		for (int i = 1; i < s.length(); i++)
			if (s[i] != s[i - 1])
				ans++;
		cout << "Case #" << t << ": " << ans << endl;
	}
}