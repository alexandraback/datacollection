#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define DIR "D:\\codejam\\"

#define REP(i, n) for(int i=0; i<(n); i++)

using namespace std;

map<int, bool> mem;

int main() {
	ifstream is(DIR"B-large (1).in");
	ofstream os(DIR"bsmall_out2.txt");

	int t, n;
	is >> t;
	REP(i, t) {
		is >> n;
		mem.clear();
		REP(j, 2 * n - 1) {
			REP(k, n) {
				int tmp;
				is >> tmp;
				mem[tmp] = !mem[tmp];
			}
		}
		os << "Case #" << (i + 1) << ": ";
		for (const auto &p : mem) {
			if (p.second) {
				os << p.first << " ";
			}
		}
		os << endl;
	}

	return 0;
}