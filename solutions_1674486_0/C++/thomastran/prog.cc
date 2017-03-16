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
		in >> N;
		vector<vector<int> > par(N);
		vector<bool> good(N,1);
		rep(j,N) {
			int Mi;
			in >> Mi;
			par[j].resize(Mi);
			rep(k,Mi) {
				in >>	par[j][k];
				par[j][k]--;
				good[par[j][k]]=0;
			}
		}
		bool dm = 0;
		

		rep(j,N) if (good[j]) {
			queue<int> Q;
			vector<bool> seen(N,0);	
			Q.push(j);
			while (!Q.empty()) {
				int curr = Q.front();
				Q.pop();
				if (seen[curr]) {
					dm = 1;
					break;
				}
				rep(k,par[curr].size()) 
					Q.push(par[curr][k]);
				seen[curr] = 1;
			}
		}
		
		if (dm) 
			out << "Yes" << endl;
		else
			out << "No" << endl;
	}
	
}
