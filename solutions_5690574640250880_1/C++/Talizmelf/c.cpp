#include <iostream>
#include <vector>
using namespace std;

#define FORi(m) for( int i = 0; i < (m); ++i )
#define FOR(i, M) for( int i = 0; i < (M); ++i )
#define FOR1(i, M) for( int i = 1; i <= (M); ++i )
#define DEBUGGING 1
#define CERRL() if (DEBUGGING) { std::cerr << '\n'; }
#define EXAM(var) if (DEBUGGING) { std::cerr << #var << ": " << (var) << '\n'; }
#define EXAMARR(var, size) if (DEBUGGING) { std::cerr << #var << ": "; for(int __i__ = 0; __i__ < (size); ++__i__) std::cerr << (var)[__i__] << " "; std::cerr << '\n'; }


class Solver {
	private:
	static const char EMPTY = '.';
	static const char MINE = '*';
	static const char CLICK = 'c';
	vector<vector<char>> board;
	int w;
	int h;
	
	void fill(char c, int sw, int sh, int fw, int fh, int n = -1) {
		for (int i = sw; i < fw; ++i) {
			for (int j = sh; j < fh; ++j) {
				board[i][j] = c;
				if (n > 0) if (--n == 0) return;
			}
		}
	}
	
	/* rem must be less or equal than 2w+2h-8? */
	bool fill_empties(int rem) {
		if (rem == 1 || rem == 3) return false;
		if (rem > 2*w-4) {
			if (rem == 2*w-3) {
				fill(EMPTY, 2, 0, w-1, 2);
				rem -= 2*w-6;
			}
			else {
				fill(EMPTY, 2, 0, w, 2);
				rem -= 2*w-4;
			}
		}
		else {
			if (rem&1) {
				fill(EMPTY, 2, 0, 1+rem/2, 2);
				rem = 3;
			}
			else {
				fill(EMPTY, 2, 0, 2+rem/2, 2);
				rem = 0;
			}
		}
		if (rem > 0) {
			if (h > 2) {
				if (rem > 2*h-4) {
					fill(EMPTY, 0, 2, 2, h);
					rem -= 2*h-4;
				}
				else {
					fill(EMPTY, 0, 2, 2, 2+rem/2);
					rem = (rem&1)?1:0;
				}
			}
		}
		if (rem > 0) {
			if (rem > (w-2)*(h-2)) return false;
			fill(EMPTY, 2, 2, w, h, rem);
		}
		return true;
	}
	public:
	bool solve(int M) {
		if (M == 0) {
			fill(EMPTY, 0, 0, w, h);
			board[0][0] = CLICK;
			return true;
		}
		if (w == 1 || h == 1) {
			fill(EMPTY, 0, 0, w, h);
			fill(MINE, 0, 0, w, h, M);
			board[w-1][h-1] = CLICK;
			return true;
		}
		if (M <= (w-2)*(h-2)) {
			fill(EMPTY, 0, 0, w, h);
			fill(MINE, 0, 0, w-2, h-2, M);
			board[w-1][h-1] = CLICK;
			return true;
		}
		int rem = w*h - M;
		if (rem == 1 || rem == 4) {
			fill(MINE, 0, 0, w, h);
			if (rem == 4) fill(EMPTY, 0, 0, 2, 2);
			board[0][0] = CLICK;
			return true;
		}
		if (rem < 4) return false;
		
		fill(MINE, 0, 0, w, h);
		fill(EMPTY, 0, 0, 2, 2);
		if (fill_empties(rem-4)) {
			board[0][0] = CLICK;
			return true;
		}
		return false;
	}
	
	Solver(int C, int R) {
		if (C < R) {
			w = R;
			h = C;
		}
		else {
			w = C;
			h = R;
		}
		board = vector<vector<char>>(w, vector<char>(h));
	}
	
	void print() {
		for(int i = 0; i < w; ++i) {
			for (int j = 0; j < h; ++j) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}
	
	void print_transposed() {
		for(int j = 0; j < h; ++j) {
			for (int i = 0; i < w; ++i) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}
};


void solve(int T) {
	FOR1(t, T) {
		int R, C, M;
		cin >> R >> C >> M;
		Solver sol(C, R);
		
		cout << "Case #" << t << ":" << endl;
		if (sol.solve(M)) {
			if (C < R) sol.print();
			else sol.print_transposed();
		}
		else {
			cout << "Impossible" << endl;
		}
	}
}


int main() {
	int T;
	cin >> T;
	solve(T);
}

