/*
 * Author    : ben
 */
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
typedef long long LL;

int main() {
	int T, N;
	char str[2000];
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int ans = 0, stand = 0;
		scanf("%d %s", &N, str);
		for (int i = 0; i <= N; i++) {
			if (str[i] == '0') {
				continue;
			}
			if (stand < i) {
				ans += i - stand;
				stand = i;
			}
			stand += str[i] - '0';
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}


