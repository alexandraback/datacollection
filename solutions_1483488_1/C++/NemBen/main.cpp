#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>

void rotate(unsigned int& r, const int g) {
	unsigned int d = (r%10)*g;
	r = (r/10) + d;
}

void try_rotations(unsigned int n, int& count, const unsigned int g, const int l, const unsigned int a, const unsigned int b) {
	unsigned int r = n;
	std::vector<unsigned int> vals;
	for (int i = 0; i < l; ++i) {
		rotate(r,g);
		if (n < r && r < b) {
			vals.push_back(r);
		}
	}

	if (vals.size() != 0) {
		if (vals.size() > 2) {
			std::sort(vals.begin(),vals.end());
			++count;
			for (unsigned int i = 1; i < vals.size(); ++i) {
				if (vals[i] != vals[i-1]) {
					++count;
				}
			}
		}
		else if (vals.size() == 2 && vals[0] != vals[1]) {
			count += 2;
		} else {
			++count;
		}
	}
}

void solve(std::string infile, std::string outfile) {
	std::ifstream in(infile);
	std::ofstream out(outfile);

	int cnt; in >> cnt;
	for (int c = 1; c <= cnt; ++c) {
		unsigned int a, b;
		in >> a >> b;

		int l = (int)floor(log((float)b)/log(10.0f));
		unsigned int g = 1;
		for (int i = 0; i < l; ++i) { g *= 10; }

		++b;

		int count = 0;
		for (unsigned int n = a; n < b; ++n) {
			try_rotations(n,count,g,l,a,b);
		}

		out << "Case #" << c << ": " << count << std::endl;
	}

	out.close();
	in.close();
}

int main() {
	solve("large.in","large.out");

	return 0;
}