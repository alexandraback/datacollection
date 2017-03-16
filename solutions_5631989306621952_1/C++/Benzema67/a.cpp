#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		string str, ans;
		cin >> str;
		ans = str[0];
		for (int i = 1; i < str.length(); i++) {
			if (str[i] >= ans[0]) {
				ans = str[i] + ans;
			}
			else {
				ans = ans + str[i];
			}
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
}