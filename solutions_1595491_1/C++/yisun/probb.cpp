#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

fstream in, out;

int t, n, s, p, v;

int min (int x, int y) { if (x < y ) return x; return y;}

int ispossible(int thresh, int sum) {
	if (thresh == 0) {
		return 1;
	} else if (thresh == 1) {
		if (sum >= 1) {
			return 1;
		} else {
			return 0;
		}
	}
	if (3 * thresh <= sum) {
		return 1;
	} else if (3 * thresh - 1 <= sum) {
		return 1;
	} else if (3 * thresh - 2 <= sum) {
		return 1;
	} else {
		return 0;
	}
}

int isspossible(int thresh, int sum) {
	if (thresh == 0) {
		return 1;
	} else if (thresh == 1) {
		if (sum >= 2) {
			return 1;
		} else {
			return 0;
		}
	}
	if (3 * thresh + 2 <= sum) {
		return 1;
	} else if (3 * thresh - 2 == sum || 3 * thresh <= sum) {
		return 1;
	} else if (3 * thresh - 4 <= sum) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	in.open("probb.in", fstream::in);
	out.open("probb.out", fstream::out);

	in >> t;
    for (int i = 0; i < t; i++) {
		int posans = 0;
		int sposchange[7];
		for (int j = 0; j < 7; j++) {
			sposchange[j] = 0;
		}
		
		in >> n >> s >> p;
		for (int j = 0; j < n; j++) {
			in >> v;

			posans += ispossible(p, v);
			sposchange[3 + isspossible(p, v) - ispossible(p, v)]++;
		}
	
		int ans = posans;
		cout << ans << endl;
		for (int k = 6; k >= 0; k--) {
			if (sposchange[k] <= s) {
				s -= sposchange[k];
				ans += sposchange[k] * (k - 3);
				sposchange[k] = 0;
			} else {
				ans += s * (k - 3);
				break;
			}
		}
		out << "Case #" << i + 1 << ": " << ans << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
