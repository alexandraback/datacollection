#include <fstream>
#include <vector>

using namespace std;

ifstream fin("D-large.in");
ofstream fout("out.txt");

int main() {
	int tests;
	fin >> tests;

	for(int test = 0; test < tests; ++test) {
		long long k, c, s;
		fin >> k >> c >> s;
		if (s * c < k) {
			fout << "Case #" << test + 1 << ": IMPOSSIBLE" << endl;
		} else {
			vector<long long> pows;
			pows.resize(c + 1);
			pows[0] = 0;
			pows[1] = 1;
			for (int i = 2; i < pows.size(); ++i) {
				pows[i] = pows[i - 1] * k; 
			}

			vector<long long> pos;
			long long cur = 0;
			while (cur != k) {
				long long cur_pos = 0;
				for (int i = 0; i < c - 1; ++i) {
					if (cur != k) {
						++cur;
					}
					cur_pos += (cur - 1) * pows[c - i];
				}
				
				if (cur != k) {
				    ++cur;
				}
				pos.push_back(cur_pos + cur);
			}

			fout << "Case #" << test + 1 << ": ";
			for (int i = 0; i < pos.size(); ++i) {
				fout << pos[i] << " ";
			}
			fout << endl;
		}
	}

	return 0;
}
