#include <iostream>

using namespace std;

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	for(int C = 1;C <= t;C++) {
		int S;
		string str;
		cin >> S >> str;
		int ans = 0, cnt = str[0] - '0';
		for(int i = 1;i < S+1;i++) {
			if(cnt < i) {
				ans += i - cnt;
				cnt = i;
			}
			cnt += str[i] - '0';
		}
		cout << "Case #" << C << ": " << ans << endl;
	}
	return 0;
}
