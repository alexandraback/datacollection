#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_b"
typedef unsigned int uint;
const ldb pi = acos(-1.0);
const int inf = (int) 1e9;
const int K = 2013;
const int N = (int) 2e6 + 1;
int t, x, y;

/*map< uint, bool > mans;

bool can(int x, int y) {
	if (y == 0)
		return (x == 0);
	if (x < 0)
		return can(-x, y);
	uint index = (uint) x * K + y;
	if (mans.count(index))
		return mans[index];
	if (can(x - y, y - 1))
		return mans[index] = true;
	else if (can(x + y, y - 1))
		return mans[index] = true;
	else
		return mans[index] = false;
}

int ans(int x) {
	int i = 0;
	while (!can(x, i))
		++i;
	return i;
}*/

int simple_ans(int n) {
	int k = 0;
	while (((k + 1) * (k + 2)) / 2 < n)
		++k;
	int sum = (k * (k + 1)) / 2;
	if (n == sum)
		return k;
	if (k % 2 == 1) {
		if ((n - sum) % 2 == 1)
			return k + 2;
		else
			return k + 1;
	} else {
		if ((n - sum) % 2 == 1)
			return k + 1;
		else
			return k + 3;
	}
}

bool super(int k, int y) {
	if (k % 2 == 0)
		return (k == y) || ((y >= k) && super(k + 3, y));
	else
		return ((y >= k) && ((y - k) % 4 < 2));
}

bool can(int x, int y) {
	int k = simple_ans(abs(x));
	return super(k, y);
}

void go(int x, int y, int k, string dir) {
	if ((x == 0) && (y == 0))
		return;
	//eprintf("%d %d %d\n", x, y, k);
	if (x < 0) {
		swap(dir[2], dir[3]);
		x *= -1;
		go(x, y, k, dir);
		return;
	}
	if (y < 0) {
		swap(dir[0], dir[1]);
		y *= -1;
		go(x, y, k, dir);
		return;
	}
	if (can(x + y - k, k - 1)) {
		if (x >= k) {
			go(x - k, y, k - 1, dir);
			printf("%c", dir[3]);
			return;
		}
		if (y >= k) {
			go(x, y - k, k - 1, dir);
			printf("%c", dir[1]);
			return;
		}
	}
	assert(can(x + y, k));
	if (x > y) {
		go(x - k, y, k - 1, dir);
		printf("%c", dir[3]);
		return;
	} else {
		go(x, y - k, k - 1, dir);
		printf("%c", dir[1]);
		return;
	}
}

int main() {
	//assert(freopen(taskname".in", "r", stdin));
	//assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d", &x, &y);
		int k = simple_ans(abs(x) + abs(y));
		printf("Case #%d: ", it + 1);
		eprintf("%d %d %d\n", x, y, k);
		go(x, y, k, "SNWE");
		printf("\n");
	}
	//for (int i = 0; i < N; ++i)
	//	printf("%d ", ans[i]);
	return 0;
}