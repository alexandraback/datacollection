//compiler: MSVC 2010 (C++ obviously)
//one template to rule them all

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <queue>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj_d"

using namespace std;

int main() {
	//freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;

	for(int tn = 0; tn < t; tn++) {
		int x, r, c;
		in >> x >> r >> c;
		out << "Case #" << tn + 1 << ": ";

		bool three_five = (x == 5 && (r == 3 && c < 10 || c == 3 && r < 10));
		bool three_size = (x == 6 && (r == 3 || c == 3));
		bool six_threefour = (x == 6 && (r == 3 && c == 4 || r == 4 && c == 3));
		bool four_two = (x == 4 && (r == 2 || c == 2));
		if(x >= 7 || ((r*c)%x) != 0 || (x > r && x > c) || (x >= 2 * min(r, c) + 1) || three_five || three_size || six_threefour || four_two) {
			out << "RICHARD\n";
		} else {
			out << "GABRIEL\n";
		}

	}

	return 0;
}