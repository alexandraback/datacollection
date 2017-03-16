#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h> 
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

int T, t;

set<string> seen;

int main() {
	fin >> T;

	for (int t = 1; t <= T; t++) {
		int K = 2;
		int C = 3;
		int S = 2;
		fin >> K >> C >> S;
		cout << K << " " << C << " " << S << endl;

		int req = ceil((double)K / C);

		if (req > S) {
			cout << "Case " << "#" << t << ": IMPOSSIBLE" << endl;
			fout << "Case " << "#" << t << ": IMPOSSIBLE" << endl;
			continue;
		}
		cout << "Case " << "#" << t << ": ";
		fout << "Case " << "#" << t << ": ";

		//working in base K with digits of length C

		cpp_int next = 0;//0 to K
		bool done = false;

		while (!done) {
			cpp_int tile_no = 1;
			cpp_int p = 1;
			for (int i = 1; i <= C; i++) {
				cout << (done ? 0 : next);

				if (done)
					continue;

				tile_no += next*p;

				p *= K;
				next++;
				if (next >= K) {
					done = true;				
				}

			}
			cout << "(" << tile_no << ") ";
			fout << tile_no << " ";
		}
		cout << endl;
		fout << endl;
	}
}

