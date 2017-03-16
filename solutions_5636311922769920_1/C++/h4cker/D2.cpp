#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

typedef unsigned long long ull;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL), cout.precision(15);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		ull K, C, S; cin >> K >> C >> S;
		cout << "Case #" << t << ":";
		ull res = 0;
		vector<ull> v;
		if (C == 1) {
			res = K;
			for (ull i = 1; i <= K; i++) v.push_back(i);
		} else {
			res = K/2;
			for (ull n = 2; n <= K; n += 2) {
				ull newn = n-1;
				for (ull i = 2; i <= C; i++) {
					newn = (newn-1)*K + n-1;
				}
				v.push_back(newn+1);
			}
			if (K%2 != 0) {
				res++;
				ull newn = K-1;
				for (ull i = 2; i <= C; i++) {
					newn = (newn-1)*K + K-1;
				}
				v.push_back(newn+1);
			}
		}
		if (res <= S) {
			for (int i = 0; i < v.size(); i++) cout << " " << v[i];
		} else cout << "IMPOSSIBLE";
		cout << "\n";
	}

	return 0;
}
