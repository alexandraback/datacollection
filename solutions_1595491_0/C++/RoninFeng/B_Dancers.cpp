#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int N, S, p, a, lim1, lim2, res = 0;
	cin >> N >> S >> p;
	if (p == 0) {
		res = N;
		for (int i = 0; i < N; i++)	cin >> a;
	} else {
		lim1 = max(3*p-4, 1);
		lim2 = 3*p-2;
		for (int i = 0; i < N; i++) {
			cin >> a;
			if (a >= lim1 && a < lim2 && S > 0) {
				res++;
				S--;
			} else if (a >= lim2) {
				res++;
			}
		}
	}
	cout << res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": "; 
		solve(); 
		cout << endl;
	}

	return 0;
}