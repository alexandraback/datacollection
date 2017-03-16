#include <bits/stdc++.h>
using namespace std;

int main() {
	int TC, Smax;
	string s;
	cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		cin >> Smax >> s;
		int std=0, inv=0;
		for (int t=0; t<=Smax; t++) {
			if (t>std) {
				inv += t-std;
				std = t;
			}
			std += s[t]-'0';
		}
		cout << "Case #" << tc << ": " << inv << endl;
	}
}
