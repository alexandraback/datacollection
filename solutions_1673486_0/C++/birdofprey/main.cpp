#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

fstream in("in.txt", fstream::in);
fstream out("out.txt", fstream::out);

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

void solve(){
	/* Solve here the case and output the answer without "Case #X: " prefix, but with "endl" in the end */
	int A, B;
	in >> A >> B;
	double *p = new double [A];
	for(int i = 0; i < A; i++) in >> p[i];

	double prod = 1.0, res = B + A + 1;
	for(int i = 0; i < A; i++){
		prod *= p[i];
		int D = A - i - 1;
		double expected = 2 * B + 2 * D - A + 2 - prod * (B + 1);
		res = MIN(res, expected);
	}
	res = MIN(B + 2, res);
	out << setprecision(10) << res << endl;

	delete[] p;
}

int main(){
	int T; in >> T;
	for(int t = 0; t < T; t++){
		out << "Case #" << t + 1 << ": ";
		solve();
	}
	return 0;
}
