#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

typedef long long tl; //type long
int _tc;

bool testCase() {
	std::string a;
	std::string b;
	cin >> a >> b;

	int sign = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '?'){
			if (b[i] == '?') {
				if (sign == 0)
					a[i] = (b[i] = '0');
				else if (sign == -1)
					a[i] = '9';
				else
					a[i] = '0';
			}	else {
				if (sign == 0)
					a[i] = b[i];
				else if (sign == -1)
					a[i] = '9';
				else
					a[i] = '0';
			}
		}
		if (b[i] == '?') {
			if (sign == 0)
				b[i] = a[i];
			else if (sign == -1)
				b[i] = '0';
			else
				b[i] = '9';
		}
		if (a[i] != '?' && b[i] != '?' && sign == 0 && a[i] != b[i]) {
			sign = (a[i] > b[i]) ? 1 : -1;
		}
	}

	cout << a << " " << b;
	return true;
}

int main(){
	int ntc;

	cin >> ntc;
	//cerr << "tests " << n << endl;
	for (int _tc = 0; _tc < ntc; ++_tc) {
		cout << "Case #" << (_tc + 1) << ": ";
		if (!testCase()) {
			cout << " IMPOSSIBLE";
		}
		cout << endl;
	}
	return 0;
}