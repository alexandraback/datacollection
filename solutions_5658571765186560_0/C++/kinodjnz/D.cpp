#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

bool solve(int X, int R, int C)
{
	if (X == 1)
		return true;
	else if (X == 2)
		return (R*C % 2 == 0);
	else if (X == 3) {
		if (R <= 2 && C <= 2)
			return false;
		if (R == 1 || C == 1)
			return false;
		return (R*C % 3 == 0);
	} else if (X == 4) {
		if (R <= 3 && C <= 3)
			return false;
		if (R <= 2 || C <= 2)
			return false;
		return (R*C % 4 == 0);
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int X, R, C;
		cin >> X >> R >> C;
		bool ans = solve(X, R, C);
		cout << "Case #" << t+1 << ": " << (ans ? "GABRIEL" : "RICHARD") << endl;
	}
}
