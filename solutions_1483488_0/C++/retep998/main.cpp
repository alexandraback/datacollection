#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>
#include <ctime>
#include <functional>
#include <set>
using namespace std;

char c[256];

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int cases;
	in >> cases;
	for (int i = 1; i <= cases; ++i) {
		int a, b;
		in >> a >> b;
		int s = to_string((long long)a).size();
		int n = 0;
		int m = 1;
		for (int j = 1; j < s; ++j) {
			m *= 10;
		}
		for (int j = a; j <= b; ++j) {
			int t = j;
			set<int> used;
			for (int k = 1; k < s; ++k) {
				int tt = t%10;
				t /= 10;
				t += tt*m;
				if (t > j && t <= b) {
					if (!used.count(t)) {
						++n;
						used.insert(t);
					}
				}
			}
		}
		out << "Case #" << i << ": " << n << endl;
	}
}