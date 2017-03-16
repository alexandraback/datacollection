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
		vector<int> s(N);
		int all = 1 << N;
		rep(j,N)
			in >> s[j];
		out << "Case #" << i+1 << ":"<< endl;
		bool ok = 0;
		map<int,int> db;
		rep(t,all) {
				int sum =0;
				rep(j,N) if (t & (1 << j))
					sum += s[j];
				if (db.find(sum) != db.end()) {
					int k = db[sum];
					rep(l,N) if (t & (1 << l))
						out << s[l] << " ";
					out << endl;
					rep(l,N) if (k & (1 << l))
						out << s[l] <<" ";
					out << endl;
					ok = 1;
					break;
				}
				db[sum] = t;
		}
		if (!ok)
			out << "Impossible" << endl;
	}
}
