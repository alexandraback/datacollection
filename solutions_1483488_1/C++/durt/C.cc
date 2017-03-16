#include <iostream>
using namespace std;

int A, B, T;

int tenbound(int n) {
	if (n < 10) return 1;
	else return 10 * tenbound(n/10);
}

int rshift(int n) {
	return T * (n%10) + n/10;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> A >> B;
		T = tenbound(A);
		
		int res = 0;
		for (int n = A; n <= B; n++)
			for (int m = rshift(n); m != n; m = rshift(m))
				if (A <= m && m <= B)
					res++;
		res /= 2;
		
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
