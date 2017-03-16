#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


ofstream out("out.txt");


int main() {
//	ifstream f("B-large.in");
	ifstream f("A-small-attempt0.in");
	int T;
	f >> T;

	for (int x = 0; x < T; x++) {

		long long r, t;
		f >> r >> t;

		long long total = 0;
		long long cur = r;
		long long used = 0;
		while (used <= t) {
			used += (cur+1) * (cur+1) - (cur) * (cur);
			cur += 2;
			total++;
//			cout << used << " " << t << endl;
		}

		out << "Case #" << x+1 << ": " << total-1 << endl;

	}



	return 0;
}
