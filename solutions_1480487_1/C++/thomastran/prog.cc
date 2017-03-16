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
		int N;
		in >> N;	
		vector<double> s(N);
		rep(j,N)
			in >> s[j];
		out << "Case #" << i+1 << ": ";
		out << fixed;
		double X = 0;
		rep(j,N)
			X += s[j];
		rep(j,N) {
			double low = 0.0;
			double high = 100.0;
			rep(k,40) {
				double mid = (low + high)/2;
				double t= s[j] + (mid/100)*X;
				double ttl =0.0;
				rep(l,N) 	if (l!=j && s[l] < t)
					ttl += (t-s[l])/X;
				if (ttl + mid/100 < 1.0)  
					low = mid;
				else 
					high = mid;
			}
			out << setprecision(6) << low << " ";
		}
		out << endl;
	}
}
