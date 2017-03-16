#include <mymacro.h>
using namespace std;

class Solver {
public:
	double solve() {
		int A, B;
		double P[100000];
		cin >> A >> B;
		rep(i, A) cin >> P[i];

		double p = 1;
		rep(i, A) p *= P[i];
		double ans = p * (B-A+1) + (1-p) * (2*B-A+2);

		p = 1;
		rep(i, A) {
			ans = min(ans, p * (A+B-2*i+1) + (1-p) * (A+2*B-2*i+2));
			p *= P[i];
		}

		ans = min(ans, (double)B+2);
		
		return ans;
	}
};

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		Solver sol;
//		cout << "Case #" << t << ": " << sol.solve() << endl;
		printf("Case #%d: %.6lf\n", t, sol.solve());
	}
	return 0;
}

