#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int T, a, b, c, k;
    cin >> T;
    for (int x=1; x<=T; x++) {
        cin >> a >> b >> c >> k;
		int p = a*b*c;
		int mask = 1 << p;
		while (mask--) {
			int AB[3][3] = {};
			int BC[3][3] = {};
			int AC[3][3] = {};
			bool ok = 1;
			int bits = 0;
			for (int i=0; i<p; i++) {
				if (mask & (1 << i)) {
					bits++;
					int A = i / (b*c);
					int B = i / c % b;
					int C = i % c;
					ok &= (++AB[A][B] <= k) && (++AC[A][C] <= k) && (++BC[B][C] <= k);
				}
			}
			if (ok) {
				cout << "Case #" << x << ": " << bits << endl;
				for (int i=0; i<p; i++) {
					if (mask & (1 << i)) {
						int A = i / (b*c);
						int B = i / c % b;
						int C = i % c;
						cout << A+1 << ' ' << B+1 << ' ' << C+1 << endl;
					}
				}
				break;
			}
		}
    }
}
