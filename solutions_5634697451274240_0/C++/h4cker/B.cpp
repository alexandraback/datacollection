#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;
int a[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL), cout.precision(15);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string s; cin >> s;
		int N = s.length();
		for (int i = 0; i < N; i++) if (s[i] == '+') a[i] = 1; else a[i] = -1;
		int res = 0;
		while(1) {
			int cnt = a[0];
			for (int i = 0; i < N-1; i++) {
				if (a[i] == a[i+1]) cnt += a[i+1];
				else break;
			}
			if (cnt == N) {
				cout << "Case #" << t << ": "<< res << "\n";
				break;
			}
			for (int i = 0; i < abs(cnt); i++) {
				a[i] = -1*a[i];
			}
			res++;
		}
	}

	return 0;
}
