#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char f[64*64];

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
		fo << "Case #" << t << ":\n";
		int R, C, M;
		fi >> R >> C >> M;
		memset (f, '*', (C+1)*R);
		f[(C+1)*R] = '\0';
		for (int j = 0; j < R; ++j) {
			f[(C+1)*j+C] = '\n';
		}
		int P = R*C - M; // 1 <= P <= R*C
		if (P == 1) {
		} else if (R == 1) {
			for (int i = 0; i < P; ++i) {
				f[i] = '.';
			}
		} else if (C == 1) {
			for (int i = 0; i < P; ++i) {
				f[(C+1)*i] = '.';
			}
		} else if (R == 2) {
			if (P < 4 || P%2 != 0) {
				fo << "Impossible\n";
				continue;
			}
			for (int i = 0; 2*i < P; ++i) {
				f[i] = '.';
				f[(C+1)+i] = '.';
			}
		} else if (C == 2) {
			if (P < 4 || P%2 != 0) {
				fo << "Impossible\n";
				continue;
			}
			for (int i = 0; 2*i < P; ++i) {
				f[(C+1)*i] = '.';
				f[(C+1)*i+1] = '.';
			}
		} else {
			if (P < 4 || P == 5 || P == 7) {
				fo << "Impossible\n";
				continue;
			}
			if (P <= 2*C+1) {
			   	if (P%2 == 0) {
					for (int i = 0; 2*i < P; ++i) {
						f[i] = '.';
						f[(C+1)+i] = '.';
					}
				} else {
					for (int i = 0; 2*i < P-3; ++i) {
						f[i] = '.';
						f[(C+1)+i] = '.';
					}
					f[(C+1)*2+0] = '.';
					f[(C+1)*2+1] = '.';
					f[(C+1)*2+2] = '.';
				}
			} else {
				int k = P/C;
				int m = P%C;
				for (int j = 0; j < k; ++j) {
					for (int i = 0; i < C; ++i) {
					   f[(C+1)*j+i] = '.';
				   	}
			 	}
				for (int i = 0; i < m; ++i) {
					f[(C+1)*k+i] = '.';
				}
				if (m == 1) {
					f[(C+1)*k+1] = '.';
					f[(C+1)*k-2] = '*';
				}
			}
		}
		f[0] = 'c';
		fo << f;
	}
}

/* vim: set ts=4 sw=4 noet: */
