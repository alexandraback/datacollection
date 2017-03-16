#include<iostream>

using namespace std;

int main() {
	int Ncase;
	
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		long long r, t, c = 0;
		cin >> r >> t;
		
		long long head = 1, tail = t, ans = 0;
		while (head <= tail) {
			long long mid = (head + tail) / 2;
			long long a = r, b = r + mid * 2 - 1;
			long long c = t / (a + b);
			
			if (c >= mid) {
				ans = mid;
				head = mid + 1;
			} else {
				tail = mid - 1;
			}
		}
		
		cout << "Case #" << T << ": " << ans << endl;
	}
	
	return 0;
}
