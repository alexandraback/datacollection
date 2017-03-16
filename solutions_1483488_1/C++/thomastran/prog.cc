#include "macro.hh"


string toString(int A) {
	ostringstream oss;
	oss << A;
	return oss.str();

}	

void solve(ostream& out, int caseNum, int A, int B) {
	out << "Case #" << caseNum << ": ";
	string sa = toString(A);
	string sb = toString(B);
	int res = 0;
	int n = sa.size();
	rept(num,A,B) {
		string dg = toString(num);
		set<string> M;
		rept(i,1,n) {
			string cdd = dg.substr(i) + dg.substr(0,i);
			if (dg.compare(cdd) < 0 && cdd.compare(sb) <= 0 )
				M.insert(cdd);
		}
		res += M.size();
	}
	out << res << endl;
}

int main () {
	ifstream in("input");
	ofstream out("output");
	int T;
	in >> T; 
	rep(i,T) {
		int A, B;
		in >> A >> B;
		solve(out, i+1, A,B);		
	}
}
