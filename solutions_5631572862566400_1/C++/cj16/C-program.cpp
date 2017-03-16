#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		
		int N;
		cin >> N;
		vector<int> F(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> F[i];
		}
		int max_cyc = 0;
		
		vector<int> C(N + 1, 0);
		vector<int> S(N + 1, -1);
		for (int i = 1; i <= N; ++i) {
			C[i] = i;
			int str = 1;
			int k = F[i];
			while (C[k] != i) {
				C[k] = i;
				++str;
				k = F[k];
			}
			
			int len = 1;
			int l = F[k];
			while (l != k) {
				++len;
				l = F[l];
			}
			
			if (len == 2) {
				S[k] = max(str - 2, S[k]);
			}
			
			max_cyc = max(len, max_cyc);
		}
		
		int max_str = 0;
		for (int i = 1; i <= N; ++i) {
			if (S[i] >= 0) {
				max_str += S[i] + S[F[i]] + 2;
				S[F[i]] = -1;
			}
		}
		
		int R = max(max_cyc, max_str);
		cout << R << endl;
	}
	
	return 0;
}