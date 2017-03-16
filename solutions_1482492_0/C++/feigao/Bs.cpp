#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i = (a); i != b; i++)
#define Rep(i,n) For(i,0,n)
#define debug(x) cout<<#x<<": "<<x<<endl
#define Pb push_back
#define Mp make_pair

template<class T>void show(T a,int n) {Rep(i,n)cout<<a[i]<<' ';cout<<endl;}
template<class T>void show(T a,int n,int m) {Rep(i,n){Rep(j,m)cout<<a[i][j]<<' ';cout<<endl;}}


int main() {
	int T;
	scanf("%d\n", &T);

	Rep(iT, T) {
		double D; int N, A;
		scanf("%lf%d%d", &D, &N, &A);
		vector<double> t(N), x(N), acc(A);
		int pmk = 0;
		Rep(i,N) {
			scanf("%lf%lf", &t[i], &x[i]);
			if (x[i] < D) {
				pmk = i;
			}
		}
		Rep(i,A) scanf("%lf", &acc[i]);

		printf("Case #%d:\n", iT+1);
		if (N > 1 && x[0] < D) { // N = 2 && x[0] < D
			double v = (x[1] - x[0])/(t[1]-t[0]);
			x[1] = D;
			t[1] = (D-x[0])/v;
			double dt = t[1] - t[0];
			Rep(i, A) {
				double a = acc[i];
				if (0.5*a*dt*dt > D) {
					printf("%.8lf\n", t[1]);
				} else {
					printf("%.8lf\n", sqrt(2.0*D/a));
				}
			}
		} else { // N = 1 || x[0] >= D
			Rep(iacc, A) {
				double a = acc[iacc];
				printf("%.8lf\n", sqrt(2.0*D/a));
			}
		}
	}
	return 0;
}
