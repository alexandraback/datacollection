#include <iostream>
#include <cstdio>
using namespace std;

#define FORi(m) for( int i = 0; i < (m); ++i )
#define FOR(i, M) for( int i = 0; i < (M); ++i )
#define FOR1(i, M) for( int i = 1; i <= (M); ++i )
#define DEBUGGING 1
#define CERRL() if (DEBUGGING) { std::cerr << '\n'; }
#define EXAM(var) if (DEBUGGING) { std::cerr << #var << ": " << (var) << '\n'; }
#define EXAMARR(var, size) if (DEBUGGING) { std::cerr << #var << ": "; for(int __i__ = 0; __i__ < (size); ++__i__) std::cerr << (var)[__i__] << " "; std::cerr << '\n'; }



double solve() {
	double C, F, X;
	cin >> C >> F >> X;
	
	double best = X / 2;
	
	for (int nf = 1; ; ++nf) {
		double time = 0;
		double prod = 2;
		for (int f = 1; f <= nf; ++f) {
			time += C / prod;
			prod += F;
		}
		time += X / prod;
		if (time < best) best = time;
		else return best;
	}
}

void solve(int T) {
	FOR1(t, T) {
		cout << "Case #" << t << ": ";
		printf("%.7f", solve());
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	solve(T);
}


