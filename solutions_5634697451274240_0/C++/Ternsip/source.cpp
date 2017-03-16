#include <iostream>
#include <string>

using namespace std;

int main() {
	
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		string str;
		cin >> str;
		int ans = 0;
		int last = str[str.length() - 1];
		for (int i = str.length() - 1; i >= 0; --i) {
			if (str[i] != last) {
				ans++;
			}
			if (i == 0) {
				ans += (str[i] == '-') ^ (ans % 2);
			}
			last = str[i];
		}
		printf("Case #%d: %d\n", test, ans);
	}
	
    return 0;
}