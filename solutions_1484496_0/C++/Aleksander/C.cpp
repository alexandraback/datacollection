#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

int g[25], num[5];
bool f[25], f1[25], f2[25];
int n;

void printAns () {
	int i;

	bool printed = false;
	for (i = 0;i < n;i++) {
		if (f1[i]) {
			if (printed)
				printf(" ");
			else
				printed = true;
			printf("%d", g[i]);
		}
	}

	printf("\n");
	printed = false;
	for (i = 0;i < n;i++) {
		if (f2[i]) {
			if (printed)
				printf(" ");
			else
				printed = true;
			printf("%d", g[i]);
		}
	}
}

bool getNum2 (int cnt = 0) {
	if (cnt == n) {
		if (num[0] == 0 || num[1] == 0 || num[0] != num[1])
			return false;

		printAns();
		return true;
	}

	if (getNum2(cnt + 1))
		return true;
	if (!f[cnt]) {
		f2[cnt] = true;
		num[1] += g[cnt];
		if (getNum2(cnt + 1))
			return true;
		num[1] -= g[cnt];
		f2[cnt] = false;
	}

	return false;
}

bool getNum1 (int cnt = 0) {
	if (cnt == n) {
		num[1] = 0;
		if (getNum2())
			return true;
		return false;
	}

	if (getNum1(cnt + 1))
		return true;
	f[cnt] = true; f1[cnt] = true;
	num[0] += g[cnt];
	if (getNum1(cnt + 1))
		return true;
	num[0] -= g[cnt];
	f[cnt] = false; f1[cnt] = false;

	return false;
}

void solve () {
	int i;

	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%d", &g[i]);
	}

	printf("\n");

	memset(f, false, sizeof(f));
	memset(f1, false, sizeof(f1));
	memset(f2, false, sizeof(f2));

	num[0] = 0;
	if (!getNum1())
		printf("Impossible");
}

int main () {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test, t;

	scanf("%d\n", &test);
	for (t = 0;t < test;t++) {
		if (t)
			printf("\n");
		printf("Case #%d: ", t + 1);
		solve();
	}
	return 0;
}