#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;

int work(int A, int B, int K) {
	int ret = 0;
	for(int x = 0; x < A; x++) {
		for(int y = 0; y < B; y++) {
			if((x & y) < K) {
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	int T, A, B, K;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d%d%d", &A, &B, &K);
		printf("Case #%d: %d\n", t, work(A, B, K));
	}
	return 0;
}
