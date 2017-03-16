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
	
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	int T = 1;

	while (tc--) {
		int n;
		scanf("%d", &n);

		printf("Case #%d: ", T++);

		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}

		int d[10];
		for (int i = 0; i < 10; ++i)
			d[i] = 0;

		int cnt = 0;

		for (lint i = n; ; i += n) {
			lint num = i;
			while (num) {
				if (!d[num % 10]) {
					++cnt;
					d[num % 10] = 1;
				}
				num /= 10;
			}

			if (cnt == 10) {
				printf("%lld\n", i);
				break;
			}
		}
	}
	return 0;
}