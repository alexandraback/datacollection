#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

using namespace std;

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		int n;
		cin >> n;
		string p;
		cin >> p;
		cout << "Case #" << tc << ": ";
		int s = 0;
		int f = 0;
		forn(i, n + 1) {
			int x = p[i] - '0';
			if (!x) {
				continue;
			}
			if (s < i) {
				f += i - s;
				s = i;
			}
			s += x;
		}
		cout << f;
		cout << endl;
	}
	return 0;
}
