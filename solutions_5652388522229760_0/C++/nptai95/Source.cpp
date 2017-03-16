#include <iostream>
using namespace std;
#define N 1000001

int calc(int n) {
	int res = 1;
	int cnt = 0;
	int mark[10] = { 0 };

	while (1) {
		int m = n*res;
		
	
		do {
			if (mark[m % 10] == 0) {
				mark[m % 10] = 1;
				cnt++;
			}

			m = m / 10;
		} while (m > 0);
 
		if (cnt == 10)
			return res;

		res++;
	}
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int x;
		cin >> x;

		if (x == 0) {
			cout << "Case #" << t << ": " << "INSOMNIA" << endl
				;
			continue;
		}
		
		cout << "Case #" << t << ": " << x*calc(x) << endl;
	}
}