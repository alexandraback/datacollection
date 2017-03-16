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

		string name;
		int n, l;
		is >> name;
		is >> n;
		l = name.length();

		int c = 0;
		int t = 0;
		int last = -1;
		for (int i=0; i<name.length(); i++) {
			if (name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i] != 'o' && name[i] != 'u') {
				++c;
			}
			else {
				c = 0;
			}
			if (c >= n) {
				t += (i-(last+1)-n+2)*(l-i);
				last = i-n+1;
			}
		}
		OUT(t);
		OUT(endl);

	}

	// wrap it up
	is.close();
	os.close();
	return 0;
}
