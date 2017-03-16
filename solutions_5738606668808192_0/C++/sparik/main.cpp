#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker,"/STACK:256000000")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;

#define INF 1000000000
#define lint long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eps 0.0000001

int main() {

	//freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	printf("Case #1:\n");
	int cnt = 0;
	for (int mask = (1 << 15) + 1; mask < (1 << 16); ++mask) {
		if (mask % 2 == 0) continue;

		vector <int> vec;
		int ok = 1;
		lint num10 = 0;
		for (int base = 2; base <= 10; ++base) {
			lint num = 0;
			lint b = 1;
			for (int j = 0; j < 16; ++j) {
				if (mask&(1 << j)) {
					num += b;
				}
				b = (b * 1ll * base);
			}

			if (base == 10) num10 = num;

			if (num % 11 != 0 && num % 13 != 0 && num % 17 != 0 && num % 3 != 0) {
				ok = 0;
				break;
			}

			if (num % 3 == 0) {
				vec.push_back(3);
			}
			else if (num % 11 == 0) {
				vec.push_back(11);
			}
			else if (num % 13 == 0) {
				vec.push_back(13);
			}
			else {
				vec.push_back(17);
			}

		}

		if (ok) {
			++cnt;

			printf("%lld", num10);
			for (int i = 0; i < vec.size(); ++i) {
				printf(" %d", vec[i]);
			}

			printf("\n");
			if (cnt == 50) break;
		}
	}
	return 0;
}