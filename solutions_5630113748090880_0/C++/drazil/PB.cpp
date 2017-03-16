#include <iostream>

using namespace std;

int main(void) {
	
	int tc;
	cin >> tc;
	
	for(int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		int cnt[3000] = {0};
		for (int i = 1; i < 2 * n; i++) {
			for (int j = 0; j < n; j++) {
				int val;
				cin >> val;
				cnt[val]++;
			}
		}
		cout << "Case #" << t << ":";
		for (int i = 0; i < 3000; i++) {
			if (cnt[i] % 2 == 1) cout << ' ' << i;
		}
		cout << endl;
	}
	
	return 0;
}
