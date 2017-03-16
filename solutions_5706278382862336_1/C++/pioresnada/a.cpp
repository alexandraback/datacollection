#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

bool pos(long p, long q) {
	if (p == q) return true;
	if (p > q) return pos(p-q, q);
	if (q % 2) return false;
	return pos(p, q / 2);
}

void fu() {
	long p, q, e = 0;
	char c;
	scanf("%ld%c%ld", &p, &c, &q);
	//printf("%d %d\n", p, q);
	while(1) {
		if (p == q) {
			cout << e << endl;
			return;
		}
		if (p > q) {
			if (pos(p-q, q)) cout << e << endl;
			else cout << "impossible" << endl;
			return;
		}
		if (q % 2) {
			cout << "impossible" << endl;
			return;
		}
		q /= 2;
		++e;
	}
	/*cout << "impossible" << endl;*/
}
int main() {
	//freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("out", "w", stdout);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		fu();
	}
	//cout << LLONG_MAX << endl;
}
