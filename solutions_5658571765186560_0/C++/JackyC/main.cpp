#include <iostream>
#include <string>

using namespace std;

void formatOutput(int nCase, bool rWin) {
	cout << "Case #" << nCase+1 << ": ";
	cout << (rWin? "RICHARD": "GABRIEL") << endl;
}

void solve(int nCase) {
	int X=0, R=0, C=0;
	bool rWin = true;	

	cin >> X >> R >> C;

	do {
		if (X>=7) break;
		if ((R*C)%X != 0) break;
		if (X<=2) {
			rWin = false;
			break;
		}

		if (R>C) {
			int dum = C;
			C = R;
			R = dum;
		} // R<=C

		if (X>2*R-1) {
			break;
		}

		if (R==1) {
			rWin = false;
			break;
		}

		if (R==2) {
			if (X<4) {
				rWin = false;
			}
			break;
		}

		if (R==3) {
			if (X<6) {
				rWin = false;
			}
			break;
		}

		rWin = false;

	} while (false);

	formatOutput(nCase, rWin);
}

int main() {
	int nCase;
	cin >> nCase;

	for (int i=0; i<nCase; i++) {
		solve(i);
	}
}
