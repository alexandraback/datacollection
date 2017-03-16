#include <bits/stdc++.h>
using namespace std;
#if defined(ILIKEGENTOO)
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')
#else
#define E($...) ;
#endif
#define all(x) begin(x), end(x)

bool can(int x, int r, int c) {
	if (r < c)
		swap(r, c);
	assert(r >= c);

	// non-integer number of ominoes
	if (r * c % x)
		return false;

	// can't place line
	if (r < x)
		return false;

	// can't place corner
	int minc = (x + 1) / 2;
	if (c < minc)
		return false;

	// simple
	if (x <= 3)
		return true;

	// manually-solved
	if (x == 4)
		return c > 2;

	// can't place ominoe with holes
	if (x >= 7)
		return false;

	// x \in {5, 6}

	// no holes, free rows/cols on at least three of four sides
	if (c >= minc + 1)
		return true;

	assert(c == minc && minc == 3);

	// manually-solved
	if (x == 5) {
		// can't place stairs for r == 5
		return r >= 10;
	} else if (x == 6) {
		// can't place Ъ for any r
		return false;
	}

	assert(!"you shouldn't be here");
	abort();
}

void solve() {
	int x, r, c;
	cin >> x >> r >> c;
	if (can(x, r, c))
		cout << "GABRIEL";
	else
		cout << "RICHARD";
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}

