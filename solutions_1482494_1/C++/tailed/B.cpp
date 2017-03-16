#include <mymacro.h>
using namespace std;

class Solver {
public:
	int solve() {
		int N;
		cin >> N;
		PI C[1000];
		rep(i, N) cin >> C[i].se >> C[i].fi;
		sort(C, C+N, greater<PI>());

		int R[1000] = {};
		int star = 0;
		for(int cnt=0;; cnt++) {
			bool ne = false;
			bool fin = true;
			rep(i, N) {
				int a = C[i].se, b = C[i].fi;
				if (R[i] != 2)
					fin = false;
				if (b <= star && R[i] < 2) {
					star += 2-R[i]; R[i] = 2;
					ne = true;
					break;
				}
			}
			if (fin) return cnt;
			if (ne) continue;
			rep(i, N) {
				int a = C[i].se, b = C[i].fi;
				if (a <= star && R[i] == 0) {
					star += 1; R[i] = 1;
					ne = true;
					break;
				}
			}
			if (!ne) return -1;
		}


	}
};

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		Solver sol;
		int k = sol.solve();
		if (k >= 0)
			cout << "Case #" << t << ": " << k << endl;
		else
			cout << "Case #" << t << ": Too Bad"  << endl;
	}
	return 0;
}

