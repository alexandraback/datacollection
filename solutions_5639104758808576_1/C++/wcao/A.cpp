#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int T, N;
string mem;
inline bool good(int n) {
	for(int i = 0 ; i < (int)mem.size() ; i++) {
		if (mem[i] == '0') {
			continue;
		}	else {
			if (n >= i) {
				n += ((int)(mem[i] - '0'));
			}	else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		cin >> N;
		cin >> mem;
		int lo = 0, hi = 1000;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (good(mid)) {
				hi = mid;
			}	else {
				lo = mid + 1;
			}
		}
		printf("Case #%d: %d\n", t, hi);
	}	
	return 0;
}
