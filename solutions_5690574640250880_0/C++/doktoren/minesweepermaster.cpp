#include <assert.h>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int ti=1; ti<=t; ti++) {
		//cout << endl;
		cout << "Case #" << ti << ":" << endl;
		int r, c, m;
		cin >> r >> c >> m;
		//cout << r << " " << c << " " << m << endl;
		int spaces = r*c - m;
		if (r!=1 && c!=1 && spaces!=1 && (spaces==2 || spaces==3 || spaces==5 || spaces==7 || ((r==2 || c==2) && (spaces&1)))) {
			cout << "Impossible" << endl;
			continue;
		}
		int rows[r];
		if (r == 1) {
			rows[0] = spaces;
		} else if (c == 1) {
			for (int i=0; i<r; i++)
				rows[i] = i<spaces ? 1 : 0;
		} else if (spaces == 1) {
			rows[0] = 1;
			for (int i=1; i<r; i++)
				rows[i] = 0;
		} else if (spaces <= 2*c+1) {
			if (spaces & 1) {
				rows[0] = rows[1] = (spaces >> 1) - 1;
				rows[2] = 3;
				for (int i=3; i<r; i++)
					rows[i] = 0;
			} else {
				rows[0] = rows[1] = spaces >> 1;
				for (int i=2; i<r; i++)
					rows[i] = 0;
			}
		} else {
			for (int i=0; i<r; i++) {
				rows[i] = spaces < c ? spaces : c;
				spaces -= rows[i];
				if (rows[i] == 1) {
					++rows[i];
					--rows[i-1];
				}
			}
		}
		for (int ri=0; ri<r; ri++) {
			for (int ci=0; ci<c; ci++) {
				cout << ((ri==0 && ci==0) ? 'c' : (ci < rows[ri] ? '.' : '*'));
			}
			cout << endl;
		}
	}
	return 0;
}
