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
	int T;
	int X, R, C;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &X, &R, &C);
		bool ans;
		switch (X) {
			case 1:
				ans = false;
				break;
			case 2:
				ans = (R % 2 != 0) && (C % 2 != 0);
				break;
			case 3:
				if (R == 1 || C == 1) {
					ans = true;
				} else {
					ans = (R % 3 != 0) && (C % 3 != 0);
				}
				break;
			case 4:
				if (R > C) {
					swap(R, C);
				}
				if (R < 3) {
					ans = true;
				} else {
					ans = (R % 4 != 0) && (C % 4 != 0);
				}
				break;
			default:
				if (R > C) {
					swap(R, C);
				}
				if (R < X - 1) {
					ans = true;
				} else {
					ans = (R % X != 0) && (C % X != 0);
				}
		}
		printf("Case #%d: %s\n", t, ans ? "RICHARD" : "GABRIEL");
	}
	return 0;
}


