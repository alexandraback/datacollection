#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>
#include <ctime>
#include <functional>
using namespace std;

char c[256];

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int cases;
	in >> cases;
	for (int i = 1; i <= cases; ++i) {
		int n;
		in >> n;
		int s;
		in >> s;
		int p;
		in >> p;
		vector<int> t(n);
		int b = 0;
		for (int j = 0; j < n; ++j) {
			in >> t[j];
			int dif = t[j] - p*3;
			if (t[j] == 0) {
				if (p == 0) {
					++b;
				}
			} else if (t[j] == 1) {
				if (p <= 1) {
					++b;
				}
			} else if (dif >= -2) {
				++b;
			} else if (s && dif >= -4) {
				++b;
				--s;
			} else {

			}
		}
		out << "Case #" << i << ": " << b << endl;
	}
}