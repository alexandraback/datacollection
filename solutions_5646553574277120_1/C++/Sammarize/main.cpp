#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int next() {int x; cin >> x; return x;}
typedef long long lint;

int main() {

	int tests = next();
	for (int test = 1; test <= tests; test++) {

		int c = next(), d = next(), v = next();
		int x[d];
		for (int i = 0; i < d; i++) x[i] = next();
		sort(x, x + d);
		int answ = 0;
		lint mx = 0;
		for (int i = 0; mx < v;)
			if (i < d && x[i] <= mx + 1) mx += 1LL * c * x[i++];
			else {
				answ++;
				mx += (mx + 1) * c;
			}
		
		printf("Case #%d: %d\n", test, answ);
	}
}