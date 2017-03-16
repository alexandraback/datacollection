#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	freopen("/home/ahmed_ossama/Desktop/Code jam/A-small-attempt0.in", "r", stdin);
	freopen("/home/ahmed_ossama/Desktop/Code jam/A.out", "w", stdout);
	int t;
	cin >> t;
	int id = 0;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < n + 1; i++) {
			ans += max(0, i - sum);
			sum += max(0, i - sum);
			sum += s[i] - '0';
		}
		cout << "Case #" << ++id << ": " << ans << endl;
	}


	return 0;
}

