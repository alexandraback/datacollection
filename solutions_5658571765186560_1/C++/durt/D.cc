#include <iostream>
using namespace std;

int X, R, C;

// will Gabriel be able to cover the board?
bool solve() {
	if (X >= 7 || (R*C)%X || C < X) return false;
	switch (X) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			if (R < 2) return false;
			break;
		case 4:
			if (R <= 2) return false;
			break;
		case 5:
			if (R <= 2 || (R == 3 && C < 6)) return false;
			break;
		case 6:
			if (R <= 3) return false;
			break;
	}
	return true;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> X >> R >> C;
		if (R > C)
			swap(R, C);
		string res = (solve()) ? "GABRIEL" : "RICHARD";
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
