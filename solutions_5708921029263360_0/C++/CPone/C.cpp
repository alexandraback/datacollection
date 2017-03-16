#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <cstdint>
#include <cassert>

struct CodeJam {
	void conquer(std::istream &cin, std::ostream &cout) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int p[] {a, b, c, d};
		std::sort(p, p + 4);
		cout << p[0] * p[1] * p[2] << '\n';

		std::unordered_map<int, int> count;

		for (int j = 1; j <= a; ++j) {
			for (int k = 1; k <= b; ++k) {
				for (int i = 0; i < std::min(c, d); ++i) {
					int r = (j + k + i) % c + 1;
					assert(++count[(j << 16) + (k << 8)] <= d);
					assert(++count[(j << 16) + r] <= d);
					assert(++count[(k << 8) + r] <= d);
					
					cout << j << ' ' << k << ' ' << r << '\n';
				}
			}
		}
	}
private:
};

int main(int argc, char **argv) {
	std::ifstream ifstream;
	std::ofstream ofstream;
	if (argc > 1) {
		ifstream.open(argv[1]);
		std::string out(argv[1]);
		out.append(".out");
		ofstream.open(out.c_str());
		if (argc > 2) {
			ofstream.open(argv[2]);
		}
	}

	std::istream &cin(argc > 1 ? ifstream : std::cin);
	std::ostream &cout(argc > 1 ? ofstream : std::cout);

	int T;
	cin >> T;

	std::string line;
	std::getline(cin, line);

	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		CodeJam jam;
		jam.conquer(cin, cout);
		cout << std::endl;
	}
}
