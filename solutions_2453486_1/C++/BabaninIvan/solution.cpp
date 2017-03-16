#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

char a[10][10];

int solve() {
	bool f = false;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			scanf(" %c ", &a[i][j]);
			if (a[i][j] == '.')
				f = true;
		}
	int x, o, t;
	x = o = t = 0;
	
	for (int i = 0; i < 4; ++i) {
		x = o = t = 0;
		for (int j = 0; j < 4; ++j) {
			if (a[i][j] == 'X')
				++x;
			if (a[i][j] == 'O')
				++o;
			if (a[i][j] == 'T')
				++t;
		}
		if (x + t == 4) 
			return 1;
		if (o + t == 4)
			return 2;
	}

	for (int i = 0; i < 4; ++i) {
		x = o = t = 0;
		for (int j = 0; j < 4; ++j) {
			if (a[j][i] == 'X')
				++x;
			if (a[j][i] == 'O')
				++o;
			if (a[j][i] == 'T')
				++t;
		}
		if (x + t == 4) 
			return 1;
		if (o + t == 4)
			return 2;
	}

	x = o = t = 0;
	for (int i = 0; i < 4; ++i) {
		if (a[i][i] == 'X')
			++x;
		if (a[i][i] == 'O')
			++o;
		if (a[i][i] == 'T')
			++t;
	}
	if (x + t == 4) 
		return 1;
	if (o + t == 4)
		return 2;
	
	x = o = t = 0;
	for (int i = 0; i < 4; ++i) {
		if (a[3 - i][i] == 'X')
			++x;
		if (a[3 - i][i] == 'O')
			++o;
		if (a[3 - i][i] == 'T')
			++t;
	}
	if (x + t == 4) 
		return 1;
	if (o + t == 4)
		return 2;

	if (!f)
		return 3;
	return 4;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		int x = solve();
		if (x == 1)
			printf("Case #%d: X won\n", i);
		if (x == 2)
			printf("Case #%d: O won\n", i);
		if (x == 3)
			printf("Case #%d: Draw\n", i);
		if (x == 4)
			printf("Case #%d: Game has not completed\n", i);
	}
	return 0;
}