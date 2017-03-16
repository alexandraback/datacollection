#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int ms;
		cin >> ms;
		int s = 0;
		int add = 0;
		for (int i = 0; i <= ms; ++i) {
			char c;
			cin >> c;
			int cnt = (c - '0');
			int extra = 0;
			if (cnt != 0 && i > s) {
				extra = i - s;
				add += extra;
			}
			s += cnt + extra;
		}
		cout << "Case #" << test << ": " << add << endl;
	}
}
