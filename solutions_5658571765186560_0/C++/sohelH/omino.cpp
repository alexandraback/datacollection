#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int x, r, c;
		cin >> x >> r >> c;
		if (c > r) swap(c, r);
		bool yes = true;
		if (x >= 7)	yes = false;
		if (x > r) yes = false;
		if (x > 2*c) yes = false;
		if (r*c % x != 0) yes = false;

		if (c == 1) { // x = 1 or 2
			if (r % x != 0) yes = false;
		}

		if (c == 2) { // x == 1, 2, 3, or 4
			// x = 1, 2, 3 => possible
			if (x == 4) yes = false;
		}

		if (c == 3) { // x = 1, 2, 3, 4, 5 or 6
			if (x == 6) yes = false;
		}
		string res;
		if (yes) res = "GABRIEL";
		else res = "RICHARD";
		cout << "Case #" << cases << ": " << res << endl;

	}
	return 0;
}
