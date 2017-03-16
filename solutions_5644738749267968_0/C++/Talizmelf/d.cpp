#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FORi(m) for( int i = 0; i < (m); ++i )
#define FOR(i, M) for( int i = 0; i < (M); ++i )
#define FOR1(i, M) for( int i = 1; i <= (M); ++i )
#define DEBUGGING 0
#define CERRL() if (DEBUGGING) { std::cerr << '\n'; }
#define EXAM(var) if (DEBUGGING) { std::cerr << #var << ": " << (var) << '\n'; }
#define EXAMARR(var, size) if (DEBUGGING) { std::cerr << #var << ": "; for(int __i__ = 0; __i__ < (size); ++__i__) std::cerr << (var)[__i__] << " "; std::cerr << '\n'; }


//int Deceitful_War(const vector<double>& a, const vector<double>& b) {
//	auto it = upper_bound(a.begin(), a.end(), b[0]);
//	return a.end()-it;
//}

int War(const vector<double>& a, const vector<double>& b) {
	auto ita = a.begin();
	auto itb = b.begin();
	int count = 0;
	for (; itb != b.end(); ++ita, ++itb) {
		if (*ita > *itb) {
			auto it = upper_bound(itb + 1, b.end(), *ita);
			count += it-itb;
			if (it == b.end()) break;
			itb = it;
		}
	}
	return count;
}


vector<double> read(int N) {
	vector<double> a(N);
	FORi(N) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	return a;
}

void solve(int T) {
	FOR1(t, T) {
		int N;
		cin >> N;
		vector<double> naomi = read(N);
		vector<double> ken = read(N);
		EXAMARR(naomi, naomi.size());
		EXAMARR(ken, ken.size());
		
		cout << "Case #" << t << ": ";
		cout << N - War(ken, naomi) << " " << War(naomi, ken);
		cout << endl;
	}
}



int main() {
	int T;
	cin >> T;
	solve(T);
}


