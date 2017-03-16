#include <iostream>
using namespace std;

int d[100];

int main() {
	int it, nt;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int c, nd, v, i, v1, r = 0;

		cin >> c >> nd >> v;
		for (i = 0; i < nd; i++) cin >> d[i];

		for (i = 0, v1 = 0; v1 < v; ) {
			if (i < nd && d[i] <= v1 + 1) {
				for (int j = 0; j < c && v1 < v; j++) v1 += d[i];
				i++;
			} else {
				// ieviešam monētu ar vērtību v1 + 1
				int t = v1 + 1;

				r++;
				for (int j = 0; j < c && v1 < v; j++) v1 += t;
			}
		}

		cout << "Case #" << it << ": " << r << endl;
	}
}
