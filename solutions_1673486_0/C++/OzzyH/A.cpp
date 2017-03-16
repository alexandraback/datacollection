//#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ifstream cin("A-small.in");
ofstream cout("A-small.out");

int main () {
	int T; cin >> T >> ws;
	for (int t=0; t<T; t++) {
		int A, B;
		cin >> A >> B;
		double *p = new double[A];
		for (int i=0; i<A; i++)
			cin >> p[i];
		double mn = 2+B;
		double prob = 1;
		for (int i=A; i>=0; i--) {
			if (i!=A) prob *= p[A-1-i];
			double temp = (double)(B-A+1 + 2*i) + (1.0-prob)*(double)(B+1);
			mn = min(mn, temp);
		}
		delete [] p;
		cout << "Case #" << t+1 << ": ";
		cout << setprecision (9) << mn << endl;
	}
}
