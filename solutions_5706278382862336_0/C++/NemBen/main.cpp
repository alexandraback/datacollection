#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


__int64 gcd(__int64 m, __int64 n) {
   __int64 r;
   while (n != 0) {
      r = m % n;
      m = n;
      n = r;
   }
   return m;
}

int main() {
	__int64 table[41];

	__int64 t = 1;
	for (int i = 0; i <= 40; ++i, t *= 2) {
		table[i] = t;
	}

	int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
		char c;
		__int64 P, Q; cin >> P >> c >> Q;

		__int64 d = gcd(P,Q);
		P /= d;
		Q /= d;

		bool found = false;
		int j;
		for (int i = 0; i <= 40 && !found; ++i) {
			j = i;
			found = (table[i] == Q);
		}

		cout << "Case #" << t << ": ";
		if (!found) {
			cout << "impossible";
		} else {
			int k;
			for (int i = 0; i <= 40 && table[i] <= P; ++i) {
				k = i;
			}
			cout << (j - k);
		}
		cout << endl;


    }
}