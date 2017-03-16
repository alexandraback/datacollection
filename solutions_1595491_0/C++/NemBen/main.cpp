#include <fstream>
#include <iostream>
#include <vector>
#include <string>


void solve(std::string infile, std::string outfile) {
	std::ifstream in(infile);
	std::ofstream out(outfile);

	int cnt; in >> cnt;
	for (int c = 1; c <= cnt; ++c) {
		int n, s, p;
		in >> n >> s >> p;

		int count = 0;
		if (p == 0) {
			for (int i = 0; i < n; ++i) {
				int t; in >> t;
			}
			count = n;
		} 
		else if (p == 1) {
			for (int i = 0; i < n; ++i) {
				int t; in >> t;
				if (t > 0) {
					++count;
				}
			}
		} else {	
			int low_no_s = 3*p-3;
			int low_s = 3*p-5;
			
			for (int i = 0; i < n; ++i) {
				int t; in >> t;
				if (t > low_no_s) {
					++count;
				}
				else if (t > low_s && s > 0) {
					++count;
					--s;
				}
			}
		}

		out << "Case #" << c << ": " << count << std::endl;
	}

	out.close();
	in.close();
}

int main() {
	solve("small2.in","small2.out");

	return 0;
}