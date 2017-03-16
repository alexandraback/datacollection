#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cassert>

#define SHOW(...) {;}
#define REACH_HERE {;}
#define PRINT(s, ...) {;}
#define PRINTLN(s, ...) {;}

// #undef HHHDEBUG
#ifdef HHHDEBUG
#include "template.h"
#endif

using namespace std;

template<typename T>
using Grid = vector<vector<T>>;

const double E = 1e-8;
const double PI = acos(-1);

struct Ans {
	int diff;
	string a;
	string b;
};

void sol() {
	string a, b;
	cin >> a >> b;
	int l = a.length();
	vector<int> aa(l);
	vector<bool> xa(l);
	vector<int> ab(l);
	vector<bool> xb(l);
	for (int i = 0; i < l; i++) {
		if (a[i] == '?') {
			xa[i] = true;
		}
		else
			aa[i] = a[i] - '0';
		if (b[i] == '?')
			xb[i] = true;
		else
			ab[i] = b[i] - '0';
	}

	Ans ans = {10000000, "", ""};
	int p[3] = {1, 10, 100};
	for (int a1 = 0; a1 < 10; a1++) {
		int ia = 0;
		int ib = 0;
		if (l > 0) {
			if (xa[0]) {
				aa[0] = a1;
			}
			ia += p[l - 1] * aa[0];
		}
		for (int a2 = 0; a2 < 10; a2++) {
			if (l > 1) {
				if (xa[1]) {
					aa[1] = a2;
				}
				ia += p[l - 2] * aa[1];
			}
			for (int a3 = 0; a3 < 10; a3++) {
				if (l > 2) {
					if (xa[2]) {
						aa[2] = a3;
					}
					ia += p[l - 3] * aa[2];
				}
				for (int b1 = 0; b1 < 10; b1++) {
					if (l > 0) {
						if (xb[0]) {
							ab[0] = b1;
						}
						ib += p[l - 1] * ab[0];
					}
					for (int b2 = 0; b2 < 10; b2++) {
						if (l > 1) {
							if (xb[1]) {
								ab[1] = b2;
							}
							ib += p[l - 2] * ab[1];
						}
						for (int b3 = 0; b3 < 10; b3++) {
							if (l > 2) {
								if (xb[2]) {
									ab[2] = b3;
								}
								ib += p[l - 3] * ab[2];
							}

							string sa;
							string sb;
							for (int i = 0; i < l; i++) {
								sa += aa[i] + '0';
								sb += ab[i] + '0';
							}
							SHOW(sa, sb, ia, ib)
							if (abs(ia - ib) < ans.diff) {
								ans.diff = abs(ia - ib);
								ans.a = sa;
								ans.b = sb;
							}

							if (abs(ia - ib) == ans.diff) {
								if (sa < ans.a || (sa == ans.a && sb < ans.b)) {
									ans.diff = abs(ia - ib);
									ans.a = sa;
									ans.b = sb;		
								}
							}

							if (l > 2) {
								ib -= p[l - 3] * ab[2];
							}
						}
						if (l > 1) {
							ib -= p[l - 2] * ab[1];
						}
					}
					if (l > 0) {
						ib -= p[l - 1] * ab[0];
					}
				}
				if (l > 2) {
					ia -= p[l - 3] * aa[2];
				}
			}
			if (l > 1) {
				ia -= p[l - 2] * aa[1];
			}
		}
		if (l > 0) {
			ia -= p[l - 1] * aa[0];
		}
	}

	cout << ans.a << " " << ans.b << endl;
}


int main() {
    ios::sync_with_stdio(false);

    int nc;
    cin >> nc;
    for (int i = 1; i <= nc; i++) {
    	printf("Case #%d: ", i);
    	sol();
    }

}





