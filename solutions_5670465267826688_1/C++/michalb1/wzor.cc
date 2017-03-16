#include <iostream>
#include <string>
using namespace std;

int val[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};

int sign[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};


int main() {
	int p, t, i, j;
	long long l, x;
	string s;
	cin >> t;
	for (p = 1; p <= t; ++p) {
		cin >> l >> x;
		cin >> s;
		int tempVal = 0;
		int tempSign = 1;
		int firstSign;
		int firstVal;
		bool isI = false;
		bool isK = false;
		for (j = 1; j <= min(12LL, x); ++j) {
		    for (i = 0; i < s.size(); ++i) {
			    int mulVal = s[i] - 'i' + 1;
			    tempSign = tempSign * sign[tempVal][mulVal];
			    tempVal = val[tempVal][mulVal];
		        if (tempVal == 1 && tempSign == 1)
		            isI = true;
		        if (isI && tempVal == 3 && tempSign == 1)
		            isK = true;
			}
			if (j == 1) {
			    firstSign = tempSign;
			    firstVal = tempVal;
			}
		}
		if (isI && isK && ((x % 4 == 2 && firstVal > 0) || (x % 2 == 1 && firstVal == 0 && firstSign == -1)))
			std::cout << "Case #" << p << ": YES" << std::endl;
		else
			std::cout << "Case #" << p << ": NO" << std::endl;
	}
	return 0;
}

