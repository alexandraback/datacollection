#include "macro.hh"


void solve(ostream& out, int caseNum, int A, int B, vector<double> &P) {
	out << "Case #" << caseNum << ": ";
	vector<double> R(A);
	R[0] = P[0];
	double res = 2.0*B;
	rept(i,1,A) 
		R[i] = R[i-1] * P[i];
	rep(i,A) {
		double d = R[i]*((B-A) + 2*(A-i-1)+1) + (1-R[i])*( (B-A) + 2*(A-i-1) + 1 + B + 1);
		res = min(d,res);
	}	
	
	res = min(res,B+2.0);

	out << res << endl;
}

int main () {
	ifstream in("input");
	ofstream out("output");
	int T;
	in >> T; 
	rep(i,T) {
		int A,B;
		in >> A >> B;
		vector<double> P(A);
		rep(j,A)
			in >> P[j];
		solve(out, i+1, A ,B, P);
	}
}
