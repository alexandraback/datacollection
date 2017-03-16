#include "main.h"

using namespace std;

void Core::init() {}

void Core::solve() {
	int N;
	CGET(N);
	map<int, int> m;
	fori(i, N * 2 - 1) {
		fori(j, N) {
			int a;
			CGET(a);
			++m[a];
		}
	}
	int count = N;
	fore(i, m) {
		if (i->second % 2 == 1) {
			cout << i->first;
			if (count-- > 1) {
				cout << " ";
			}
		}
	}
}