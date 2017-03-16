#include <iostream>
#include <string>
using namespace std;

int val[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};

int sign[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};


int main() {
	int p, t, i;
	long long l, x;
	string s, str;
	cin >> t;
	for (p = 1; p <= t; ++p) {
		cin >> l >> x;
		cin >> s;
		str = "";
		for (i = 1; i <= x; ++i)
		    str += s;
		int tempVal = 0;
		int tempSign = 1;
		bool isI = false;
		bool isK = false;
		for (i = 0; i < str.size(); ++i) {
			int mulVal = str[i] - 'i' + 1;
			tempSign = tempSign * sign[tempVal][mulVal];
			tempVal = val[tempVal][mulVal];
		    if (tempVal == 1 && tempSign == 1)
		        isI = true;
		    if (isI && tempVal == 3 && tempSign == 1)
		        isK = true;
		}
		if (isI && isK && tempVal == 0 && tempSign == -1)
			std::cout << "Case #" << p << ": YES" << std::endl;
		else
			std::cout << "Case #" << p << ": NO" << std::endl;
	}
	return 0;
}
