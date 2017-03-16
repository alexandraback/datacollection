#include "macro.hh"


	
map<char,char> L;

void solve(ostream& out, int caseNum, int N, int S, int p, vector<int>& V) {
	out << "Case #" << caseNum << ": ";
	int res = 0;
	if (p == 0) {
		out << N << endl;
		return;
	}
	if (p == 1) {
		rep(i,N)
			res += (V[i] > 0);
		out << res << endl;
		return;
	}

	rep(i,N) if (V[i] >= 3*p-4) {
		if (V[i] < 3*p-2) {
			if (S) {
				S--;
				res++;
			}
		}
		else 
			res++;
	}
	out << res << endl;

}

int main () {
	ifstream in("input");
	ofstream out("output");
	int T;
	in >> T; 
	rep(i,T) {
		int N,S,p;
		in >> N >> S >> p;
		vector<int> V(N);
		rep(j,N)
			in >> V[j];
		solve(out, i+1, N,S,p,V);		
	}
}
