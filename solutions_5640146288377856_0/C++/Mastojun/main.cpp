#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int T;

int R, C, W;

int solve() {
	if(C % W == 0) return C / W + W - 1 + C / W * (R - 1);
	return C / W + W + C / W * (R - 1);
}

int main() {

	scanf("%d", &T);

	for(int Case = 1; Case <= T; Case++) {
		
		scanf("%d %d %d", &R, &C, &W);
		printf("Case #%d: %d\n", Case, solve());
	}

	return 0;
}
