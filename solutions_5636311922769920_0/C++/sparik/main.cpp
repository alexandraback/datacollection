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

lint kp[100];

int main() {

	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int tc;
	scanf("%d", &tc);

	int T = 1;

	while (tc--) {

		printf("Case #%d:", T++);

		lint k, c, s;
		scanf("%lld %lld %lld", &k, &c, &s);

		if (k == 1) {
			printf(" 1\n");
			continue;
		}

		kp[0] = 1;

		for (int i = 1; i <= c; ++i) {
			kp[i] = kp[i - 1] * k;
		}

		lint cur = 1;

		while (1) {
			printf(" %lld", cur);
			cur += kp[c - 1];
			if (cur > kp[c]) {
				break;
			}
		}
		printf("\n");
	}
	return 0;
}