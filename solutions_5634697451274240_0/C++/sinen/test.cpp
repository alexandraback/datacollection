#include <bits/stdc++.h>
using namespace std;

string s;

void rotate(int x) {
	//rotate 0 to x
	for(int i = 0; i < x / 2; i++) swap(s[i], s[x - i - 1]);
	for(int i = 0; i < x; i++) 
		if(s[i] == '-') s[i] = '+';
		else s[i] = '-';
}

int back() {
	int ret = s.length() - 1;
	while(ret >= 0 && s[ret] == '+') ret--;
	return ret;
}

int front() {
	int ret = 0;
	while(ret < s.length() && s[ret] == '+') ret++;
	return ret - 1;
}

int main() {
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> s;
		int now = back();
		long long ans = 0;
		while(now >= 0) {
			//check front
			int cur = front();
//			cout << s << " " << cur << " " << now << "\n";
			if(cur < 0) {
				rotate(now + 1);
				now = back();
			} else {
				rotate(cur + 1);
			}
			ans++;
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}