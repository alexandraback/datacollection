#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)
 

int main() {
	int t;
	double c, f, x;

	cin >> t;

	REP(tc,t) {
		double t = 0, total = 0, rate = 2;
		cin >> c >> f >> x;

		double best = 1e100;

		while (t < best) {
			double t_finish = t + (x-total)/rate;
			best = min(best, t_finish);
			double t_farm = c/rate;
			t += t_farm; rate += f;
		}

		cout << "Case #" << tc+1 << ": ";
		cout.setf(ios::fixed); cout.precision(7);
		cout << best << endl;
	}

	return 0;
} 