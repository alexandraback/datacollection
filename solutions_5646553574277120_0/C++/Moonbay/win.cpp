/*
 * vc/win.cpp
 * Created on: 2014-10-25
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
#define LL long long
int base[100];
int tol[35];
int c, d, v;
void update() {
	memset(tol, 0, sizeof(tol));
	tol[0] = 1;
	for (int i = 0; i < d; i++) {
		for (int j = v; j >= 1; j--) {
			if (j - base[i] >= 0 && tol[j - base[i]]) {
				tol[j] = 1;
			}
		}
	}
}
int check() {
	for (int i = 1; i <= v; i++) {
		if (tol[i] == 0)
			return i;
	}
	return 0;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int j = 1; j <= T; j++) {
		printf("Case #%d: ", j);
		cin >> c >> d >> v;
		memset(tol, 0, sizeof(tol));
		for (int i = 0; i < d; i++) {
			cin >> base[i];
		}
		int ans = 0;
		update();
		while (1) {
			int s = check();
			if (s == 0)
				break;
			base[d] = s;
			d++;
			sort(base, base + d);
			update();
			ans++;
		}
		cout << ans << endl;

	}
	return 0;
}
