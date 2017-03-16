#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

bool solve()
{
	int x, r, c;
	cin >> x >> r >> c;
	
	// Number of spaces fits
	if (x > r * c) return true;
	if (((r * c) % x) != 0) return true;
	
	// Auto-win with 7
	if (x >= 7) return true;
	
	// Auto-loss with 2 or less
	if (x <= 2) return false;
	
	// Win by loooong tile
	if (x > r && x > c) return true;
	
	// Win by rect tile
	for (int w=1; w<=x; w++) {
		int h = x + 1 - w;
		if ((w > r || h > c) && (h > r || w > c)) return true;
	}
	
	// With 3-ominos the conditions below don't work
	if (x == 3) return false;
	
	// Win by zig-zag 4-omino
	if (x == 4) {
		if (r <= 2 || c <= 2) return true;
		return false;
	}

	// 5-omino zig-zag only works on the 3x5
	if (x == 5) {
		if (r*c == 15) return true;
		return false;
	}
	
	// 6-omino zig-zag works on all Yx3 boards
	if (x == 6) {
		if (r == 3 || c == 3) return true;
		return false;
	}
	
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		bool canBlock = solve();
		if (canBlock) {
			cout << "RICHARD";
		} else {
			cout << "GABRIEL";
		}
		cout << endl;
	}
	return 0;
}