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
		for (ull n = 1; n <= K; n++) {
			ull newn = n;
			for (ull i = 2; i <= C; i++) {
				newn = (newn-1)*K + n;
			}
			cout << " " << newn;
		}
		cout << "\n";
	}

	return 0;
}
