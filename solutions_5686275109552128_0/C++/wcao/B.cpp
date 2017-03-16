#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 1005;
int T, N, P[MAXN];

inline int calc(int s) {
	int ret = s;
	for(int i = 0 ; i < N ; i++) {
		ret += ((int)((P[i] - 1)/s));
	}
	return ret;
}

int main() {
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		cin >> N;
		for(int i = 0 ; i < N ; i++) {
			cin >> P[i];
		}
		int ans = calc(1);
		for(int s = 2 ; s <= 1000 ; s++) {
			ans = min(ans, calc(s));
		}
		printf("Case #%d: %d\n", t, ans);
	}	
	return 0;
}
