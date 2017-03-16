#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int next() {int x; cin >> x; return x;}

int main() {

	int tests = next();
	for (int test = 1; test <= tests; test++) {
		
		int r = next();
		int c = next();
		int w = next();
		int answer = c % w ? c / w * r + w : c / w * r + w - 1;

		printf("Case #%d: %d\n", test, answer);
	}
}