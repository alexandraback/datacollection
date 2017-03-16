#include <iostream>

using namespace std;


bool solve() {
	int X, R, C;
	cin >> X >> R >> C;

	if((R * C) % X != 0)
		// Does not split into ominos
		return false;
	if(X >= 7)
		// holes
		return false;
	if(X == 1)
		// Ok
		return true;
	if(X == 2)
		// Domino
		return ((R * C) % 2 == 0);
	if(X == 3) {
		if(min(R, C) < 2)
			return false;
		// Otherwise: split in 2x3N block and remaining Mx3N
		return true;
	}
	// X==4
	if(X==4) {
		if(min(R,C)<=2)
			return false;
		// min(R, C) >= 3 => 4MxN->Ok, 4N+2x4M+2->Ok
		return true;
	}
	if(X==5) {
		if(min(R,C)<=2)
			return false;
		if(min(R,C)>3)
			return true;
		// 3x10+ = solvable
		// 3x5  = insolvable
		if(min(R,C)==3 && max(R,C)==5)
			return false;
		return true;
	}
	if(X==6) {
		// 6x6 - coverable
		if(min(R,C)>=6)
			return true;
		// 1x6 bar
		if(max(R,C)<6)
			return false;
		/*
		 * ------------------
		 *   ====
		 *     =
		 *     =
		 * ------------------
		 */
		if(min(R,C)<=3)
			return false;
		//6x4=> ok => 3kx4 ok, 6kx5 ok
		return true;
		//Now only 6x1 6x2 6x3 6x4 6x5
	}
	return true;

}

void run(int t) {
	cout << "Case #" << t << ": " << (solve() ? "GABRIEL" : "RICHARD") << endl;
}

int main() {
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	for(int i = 0; i < T; ++i)
		run(i+1);

	return 0;
}
