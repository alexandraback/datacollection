#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num) {
		string cakes;
		cin >> cakes;
		int N = cakes.length();

		vector<int> plus(N + 1);
		vector<int> minus(N + 1);
		plus[0] = 0;
		minus[0] = 0;
		for (int i = 1; i <= N; ++i) {
			if (cakes[i - 1] == '+') {
				plus[i] = min(plus[i - 1], minus[i - 1] + 1);
				minus[i] = min(plus[i - 1] + 1, minus[i - 1] + 2);
			} else {
				minus[i] = min(minus[i - 1], plus[i - 1] + 1);
				plus[i] = min(minus[i - 1] + 1, plus[i - 1] + 2);
			}
		}

		cerr << "0" << cakes << endl;
		for (int i = 0; i <= N; ++i)
			cerr << plus[i];
		cerr << endl;
		for (int i = 0; i <= N; ++i)
			cerr << minus[i];
		cerr << endl;
		int total = min(plus[N], minus[N] + 1);
		cout << "Case #" << case_num << ": " << total << endl;
	}
	return 0;
}
