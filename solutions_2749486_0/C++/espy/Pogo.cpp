#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <deque>

using namespace std;

int n, m, res, k, x, y;

int main () {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int _c;
	scanf ("%d", &_c);
	for (int c = 1; c <= _c; c++) {
		scanf ("%d%d", &x, &y);
		printf ("Case #%d: ", c);
		for (int i = 0; i < x; i++) printf ("WE");
		for (int i = 0; i > x; i--) printf ("EW");
		for (int i = 0; i < y; i++) printf ("SN");
		for (int i = 0; i > y; i--) printf ("NS");
		printf ("\n");
	}
	return 0;
}