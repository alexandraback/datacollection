#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef long long int tint;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)

int main() {
	freopen("bsmall.in","r",stdin);
	freopen("bsmall.out","w",stdout);
	int T, x, y;
	cin >> T;
	forn(caso, T) {
		cout << "Case #" << caso + 1 << ": ";
		cin >> x >> y;
		if (x < 0) {
			int t = abs(x);
			forn(i, t) {
				cout << "EW";
			}
		}
		if (x > 0) {
			int t = abs(x);
			forn(i, t) {
				cout << "WE";
			}
		}
		if (y < 0) {
			int t = abs(y);
			forn(i, t) {
				cout << "NS";
			}
		}
		if (y > 0) {
			int t = abs(y);
			forn(i, t) {
				cout << "SN";
			}
		}
		cout << endl;
	}
}
