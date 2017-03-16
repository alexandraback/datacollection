#include <iostream>

using namespace std;

const int N = 110;

int use[N];

int test_num;
long long k, c, s;

int cnt = 0;
int find(void) {
	for(int i = 0;i < k;i++) {
		if(use[i] == 0) {
			cnt++;
			use[i] = 1;
			return i;
		}
	}
	return 0;
}
int main() {
	cin >> test_num;
	for(int Case = 1;Case <= test_num;Case++) {
		cin >> k >> c >> s;
		cout << "Case #" << Case << ": ";
		if(c * s < k) {
			cout << "IMPOSSIBLE" << "\n";
		}else {
			for(int i = 0;i < k;i++) {
				use[i] = 0;
			}
			cnt = 0;
			for(int i = 0;i < s;i++) {
				long long ans = 0ll;
				for(int j = 0;j < c;j++) {
					ans = ans * k + find();
				}
				ans++;
				cout << ans << " ";
				if(cnt == k) {
					break;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}