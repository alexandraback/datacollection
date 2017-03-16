#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: infile outfile\n";
		return 1;
	}
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << argv[1] << ": " << strerror(errno) << endl;
		return 1;
	}
	ofstream fo(argv[2]);
	if (!fo) {
		cerr << argv[2] << ": " << strerror(errno) << endl;
		return 1;
	}

	int T;
	fi >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		fi >> N;
		vector<double> nv(N), kv(N);
		for (int j = 0; j < N; ++j) {
			fi >> nv[j];
		}
		for (int j = 0; j < N; ++j) {
			fi >> kv[j];
		}
		sort(nv.begin(), nv.end());
		sort(kv.begin(), kv.end());
		// War game
		int rw_score = 0;
		int k_last = N-1;
		for (int i = N-1; i >= 0; --i) {
			if (kv[k_last] < nv[i]) {
				++rw_score;
			} else {
				--k_last;
			}
		}
		// Deceitful War game
		int dw_score = 0;
		int k_first = 0;
		for (int i = 0; i < N; ++i) {
			if (kv[k_first] < nv[i]) {
				++k_first;
				++dw_score;
			}
		}
		fo << "Case #" << t << ": " << dw_score << " " << rw_score << endl;
	}
}

/* vim: set ts=4 sw=4 noet: */
