#include<iostream>

using namespace std;

int main() {
	int Ncase;
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		long long r, t, s = 0, c = 0;
		cin >> r >> t;
		while (true) {
			s += 2 * r + 1;
			r += 2;
			if (s > t) {
				break;
			}
			c ++;
		}
		cout << "Case #" << T << ": " << c << endl;
	}
	
	return 0;
}
