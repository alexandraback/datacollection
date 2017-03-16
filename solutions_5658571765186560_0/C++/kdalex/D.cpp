#include <iostream>

using namespace std;


bool solve() {
	int X, R, C;
	cin >> X >> R >> C;

	if((R * C) % X != 0)
		return false;
	if(X >= 7)
		return false;
	if(X == 1)
		return true;
	if(X == 2)
		return ((R * C) % 2 == 0);
	if(X == 3) {
		if(min(R, C) < 2)
			return false;
		return true;
	}
	// X==4
	if(min(R,C)<=2)
		return false;
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
