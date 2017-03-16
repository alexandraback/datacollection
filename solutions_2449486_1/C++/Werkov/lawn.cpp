#include <iostream>
#include <vector>

using namespace std;


typedef vector<int> line_t;
typedef vector<line_t> lawn_t;
typedef vector<bool> brow_t;
typedef vector<brow_t> cut_t;

static void cut(int t) {
	int N, M;
	cin >> N; cin >> M;

	// init
	lawn_t lawn(N);
	for(lawn_t::iterator it = lawn.begin(); it != lawn.end(); ++it) it->resize(M);

	cut_t cut(N);
	for(cut_t::iterator it = cut.begin(); it != cut.end(); ++it) it->resize(M);

	line_t rmax(N);
	line_t cmax(M);

	// load
	int min_l = 100;
	int max_l = 1;
	for(int r = 0; r < N; ++r) {
		for(int c = 0; c < M; ++c) {
			cin >> lawn[r][c];
			min_l = min(min_l, lawn[r][c]);
			max_l = max(max_l, lawn[r][c]);
			rmax[r] = max(rmax[r], lawn[r][c]);
			cmax[c] = max(cmax[c], lawn[r][c]);
		}
	}

	// fill
	for(int l = min_l; l <= max_l; ++l) {
		//rows
		for(int r = 0; r < N; ++r) {
			if(rmax[r] <= l) {
				for(int c = 0; c < M; ++c) {
					if(lawn[r][c] < l) continue; // do not overwrite
					cut[r][c] = true;
				}
			}	
		}
		// cols
		for(int c = 0; c < M; ++c) {
			if(cmax[c] <= l) {
				for(int r = 0; r < N; ++r) {
					if(lawn[r][c] < l) continue; // do not overwrite
					cut[r][c] = true;
				}
			}	
		}

		/*for(cut_t::iterator it = cut.begin(); it != cut.end(); ++it) {
			for(brow_t::iterator rit = it->begin(); rit != it->end(); ++rit) {
				cout << *rit << " ";
			}
			cout << endl;
		}*/

	}
	// check
	bool result = true;
	for(int r = 0; r < N; ++r) {
		for(int c = 0; c < M; ++c) {
			result &= cut[r][c];
		}
	}

	cout << "Case #" << (t+1) << ": " << (result ? "YES" : "NO") << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;

	for(int t = 0; t < T; ++t) {
		cut(t);
	}
}
