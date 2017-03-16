#include <cstdio>
#include <sstream>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;
int T, A, B, K;
int solve(){
	if (A < K || B < K) {
		return A*B;
	}
	int cnt = K*K + K*(A-K) + K*(B-K);
	for (int i = K; i < A; i++) {
		for (int j = K; j < B; j++) {
			if ((i & j) < K) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main(int argc, const char *argv[])
{
	cin >> T;
	for (int te = 1; te <= T; te++) {
		cin >> A >> B >> K;
		int ret = solve();
		printf("Case #%d: %d\n", te, ret);
	}
	return 0;
}
