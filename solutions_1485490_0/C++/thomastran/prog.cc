#include "macro.hh"



typedef pair<double,int> mypair;
int H,N,M;
inline int state(int r, int c) {
	return r*M + c;
}



int main () {
	ifstream in("input");
	ofstream out("output");
	int T;
	in >> T; 
	rep(i,T) {
		out << "Case #" << i+1 << ": ";
		int N;
		in >> N >> M;
		vector<LL> A(N);
		vector<LL> a(N);
		rep(j,N) {
			in >> a[j];
			in >> A[j];
		}
		vector<LL> B(M);
		vector<LL> b(M);
		rep(j,M)	 {
			in >> b[j];
			in >> B[j];
		}

		while (A.size() < 3) {
			A.push_back(0);
			a.push_back(0);
		}

		printV(A);
		printV(a);
		printV(B);
		printV(b);

		vector<vector<LL> > state(3);
		rep(j,A.size()) {
			state[j].resize(M+1);
			state[j][0] = 0;
			rept(k,1,M+1)
				state[j][k] = state[j][k-1] + (B[k-1]==A[j]? b[k-1] : 0);
		}
		printVs(state);

		LL most = 0;
		if (A[0] == A[1] && A[1] == A[2]) {
			most = min(state[0][M],a[0]+a[1]+a[2]);
			out << most << endl;
			continue;
		}
		else if (A[0] == A[1]) {
			a[0] += a[1];
			a[1] = 0;
			A[1] = 0;
		}

		else if (A[1] == A[2]) {
			a[1] += a[2];
			a[2] = 0;
			A[2] = 0;
		}	

		
		rep(j,M+1) rept(k,j,M+1) {
			LL curr = min(state[0][j],a[0]) + min(state[1][k] - state[1][j], a[1]) + min (state[2][M] - state[2][k],a[2]);
			most = max(curr,most);
		}

		if (A[0] == A[2])
			most = max(most, min(state[0][M],a[0]+a[2]));
		out << most << endl;
		
	}
	
}
