#include <iostream>
#include <vector>
using namespace std;

#define FORi(m) for( int i = 0; i < (m); ++i )
#define FOR(i, M) for( int i = 0; i < (M); ++i )
#define FOR1(i, M) for( int i = 1; i <= (M); ++i )
#define DEBUGGING 1
#define CERRL() if (DEBUGGING) { std::cerr << '\n'; }
#define EXAM(var) if (DEBUGGING) { std::cerr << #var << ": " << (var) << '\n'; }
#define EXAMARR(var) if (DEBUGGING) { std::cerr << #var << ": "; for (const auto& _var_: var) std::cerr << _var_ << " "; std::cerr << '\n'; }


int solve(int R, int C, int W) {
	int res = 0;
	res = C / W;
	res *= R;
	res += W - 1;
	if (C % W != 0) res++;
	return res;
}

int main() {
	int T;
	cin >> T;
	FOR1(t, T) {
		int R, C, W;
		cin >> R >> C >> W;
		cout << "Case #" << t << ": " << solve(R, C, W) << endl;
	}
}


