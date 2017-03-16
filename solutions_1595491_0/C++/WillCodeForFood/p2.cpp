#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	int c = 0;
	cin >> T;
	while(T--) {
		int N,S,P;
		cin >> N >> S >> P;
		vector<int> t(N);
		for(int i = 0; i < N; ++i) cin >> t[i];
		int ret = 0;
		for(int idx = 0; idx < N; ++idx) {
		bool found1 = false;;
		bool found2 = false;
		for(int i = 0; i<= 10; ++i)
		for(int j = i; j<= i+2; ++j)
		for(int k = j; k<= i+2; ++k) {
			if (i+j+k != t[idx]) continue;
			if (k-i == 2 && k>=P) found1 = true;
			if (k-i <= 1 && k>=P) found2 = true;
		}
		if (found2) ++ret;
		else if (found1 && S) {++ret;--S;}
		}
		cout << "Case #" << ++c << ": " << ret << "\n";
	}
	return 0;
}
