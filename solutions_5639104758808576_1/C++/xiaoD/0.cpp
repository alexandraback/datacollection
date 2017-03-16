#include <iostream>
using namespace std;

int main(void) {
	int T, s_max;
	char c;
	cin >> T;
	for( int i = 1; i <= T; ++ i ) {
		int ans = 0, cur = 0;
		cin >> s_max;
		cin >> c;
		cur += c - '0';
		for( int j = 1; j <= s_max; ++ j) {
			cin >> c;
			int tmp = c - '0';
			if( cur >= j ) {
				cur += tmp;
			}
			else {
				ans += j - cur;
				cur = j + tmp;
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
}
