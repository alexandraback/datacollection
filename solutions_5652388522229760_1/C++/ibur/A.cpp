#include <bits/stdc++.h>

using namespace std;

const int full = 0x3ff;

int digmask(int num) {
	if(num == 0) {
		return 1;
	}
	int res = 0;
	while(num) {
		res = res | (1 << (num % 10));
		num /= 10;
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	for(int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": ";
		int N;
		cin >> N;
		if(N == 0) {
			cout << "INSOMNIA" << endl;
			continue;
		}
		int mask = 0;
		int j = 1;
		for(;;j++) {
			mask |= digmask(N * j);
			if(mask == full) break;
		}
		cout << (N * j) << endl;
	}
}

