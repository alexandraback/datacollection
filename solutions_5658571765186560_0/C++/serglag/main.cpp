#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <numeric>
#include <fstream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);

	ifstream in("d:\\input.txt");
	ofstream out("d:\\output.txt");

	int t;
	in >> t;

	for (int c = 1; c <= t; ++c) {
		int X, R, C;
		in >> X >> R >> C;

		bool ans;
		if (X == 1){
			ans = false;
		}
		else if (X == 2) {
			ans = (R * C) % X != 0;
		}
		else if (X == 3) {
			ans = (R*C) % X != 0;
			ans = ans || (C == 1);
			ans = ans || (R == 1);
		}
		else {
			ans = (R*C) % X != 0;
			ans = ans || (C <= 2);
			ans = ans || (R <= 2);
		}

		out << "Case #" << c << ": " << (ans ? "RICHARD" : "GABRIEL") << "\n";
	}

	return 0;
}