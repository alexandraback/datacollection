#include <cstring>
#include <string>

#include <fstream>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <bitset>
#include <utility>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define FOR(i, n) for (int i=0; i<n; i++)
#define RFOR(i, n) for (int i=n-1; i>=0; i--)
#define ITER(i, t, c) for (t::iterator i=c.begin(); i!=c.end(); i++)
#define SPLIT(i, buf) split<vector<int> >(buf)[i]

#define DEBUG
#ifdef DEBUG
#define DMSG(msg) cout << endl << "***DEBUG: " << msg << endl;
#else
#define DMSG(msg)
#endif // DEBUG

#define OUT(msg) cout << msg; os << msg;

int main(int argc, char **argv) {
	// Setup input and output files
	if (argc != 2) {
		cout << "Input file!" << endl;
		return 1;
	}
	string filename(argv[1]);
	ifstream is(filename);
	ofstream os(filename.replace(filename.end()-2, filename.end(), "out"));

	// Loop over test cases
	int T;
	is >> T;
	FOR (t, T) {
		os << "Case #" << t+1 << ": ";
		cout << "Case #" << t+1 << ": ";

		int x, y;
		is >> x >> y;

		int pos = 0;
		if (x>0) {
			for (int i=0; i<x; i++) {
				OUT("WE");
			}
		}
		else if (x<0) {
			for (int i=0; i>x; i--) {
				OUT("EW");
			}
		}
		pos += x*2-1;
		if (y>0) {
			for (int i=0; i<y; i++) {
				OUT("SN");
			}
		}
		else if (y<0) {
			for (int i=0; i>y; i--) {
				OUT("NS");
			}
		}
		OUT(endl);
	}

	// wrap it up
	is.close();
	os.close();
	return 0;
}
