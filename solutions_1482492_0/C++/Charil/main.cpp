#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream inf("B-small-attempt0.in");
ofstream outf("out.txt");

const int MAXN = 2010;
const long double eps = 1e-9;

long double tmm[MAXN], x[MAXN];

int main() {
	int T; inf >> T;
	for (int Tt = 1; Tt <= T; Tt++) {
		long double D;
		int N, A;
		inf >> D >> N >> A;
		for (int i = 0; i < N; i++) {
			inf >> tmm[i] >> x[i];
			//if (x[i] > D) {
			//	x[i] = D;
			//	t[i] = x[i-1]
			//}
		}
		outf << "Case #" << Tt << ":\n";
		for (int k = 0; k < A; k++) {
			long double a; inf >> a;
			long double v = 0.0, cd = x[0];
			long double ct = 0.0, tt = 0.0;
			for (int i = 0; i < N; i++) {
				long double cv = 0.0;
				long double tmp = x[i];
				if (i > 0) cv = (x[i]-x[i-1]) / (tmm[i]-tmm[i-1]);
				if (x[i] > D) x[i] = D;
				long double d = x[i];
				if (i > 0) d = x[i]-x[i-1];
				if (i > 0) ct += d / cv;
				//long double t0 = (-2*v + sqrt(4*v*v+8*a*d)) / (2*a);
				long double t0 = (-v + sqrt(v*v+2*a*d)) / a;
				if (tt+t0 < ct) {
					tt = ct;
					v = cv;
				} else {
					tt += t0;
					v += a*t0;
				}
				if (abs(x[i]-D) <= eps) {
					x[i] = tmp;
					break;
				}
				x[i] = tmp;
			}
			/*if (N == 2) {
				double t2 = sqrt(2*D/a);
				double st, a2;
				if (tmm[1]-tmm[0] > t2) {
				} else if (tmm[1]-tmm[0] == t2) {
					a2 = tmm[1]+t2;
				} else {
					double d2 = t2*((x[1]-x[0])/(tmm[1]-tmm[0]));
					a2 = tmm[0]+t2+(D-d2)/((x[1]-x[0])/(tmm[1]-tmm[0]));
				}
			}*/
			outf << fixed << setprecision(9) << tt << "\n";
		}
	}
}