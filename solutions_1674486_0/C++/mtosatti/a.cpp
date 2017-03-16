#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int inh[1000][11], anc[1000][1000], done[1000];

bool mark(int n, int a) {
		if(anc[n][a]) {
				return true;
		} else {
				anc[n][a] = 1;
				return false;
		}
}

bool search(int n) {
		vector<int> s;
		s.push_back(n);
		while(!s.empty()) {
			int a = s[0];
			for(int qi = 1; qi <= inh[a][0]; qi++) {
					int anca = inh[a][qi];
					if(mark(n,anca)) return true;
					if(done[anca]) {	
						for(int ai = 0; ai < 1000; ai++) if(anc[anca][ai] && mark(n,ai)) return true;						
					} else {
						s.push_back(anca);
					}
			}
			s.erase(s.begin());
		}
		return false;
}

int main() {
		int T, N, M;
		bool diam;
		cin >> T;
		for(int t = 1; t<= T; t++) {
				cout << "Case #" << t << ": ";
				diam = false;
				memset(anc,0,1000000);
				memset(done,0,1000);
				cin >> N;
				for(int n = 0; n < N; n++) {
						cin >> M;
						inh[n][0] = M;
						for(int m = 1; m <= M; m++) {
								cin >> inh[n][m];
								inh[n][m]--;
						}
				}
				for(int n = 0; n < N; n++) {
						if(!done[n]) {
								diam = search(n);
						}
						if (diam) break;
				}
				if(diam) {
						cout << "Yes" << endl;
				} else {
						cout << "No" << endl;
				}
		}
}
