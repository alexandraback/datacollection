#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

ofstream fout ("Bsmall.out");
ifstream fin ("Bsmall.in");

int T;
double c,f,x;

int main() {
	fin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fin >> c >> f >> x;
		double ans = x / 2;
		double cur = 0;
		for (int numFarms = 1; ; numFarms++) {
			cur += c / (2.0 + f*(numFarms-1));
			double t = cur + x / (2.0 + f*numFarms);
			if (t < ans) ans = t;
			else break;
		}
		fout << "Case #" << tc << ": ";
		fout << fixed << setprecision(7) << ans << '\n';
	}
    return 0;
}