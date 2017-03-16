#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>

using namespace std;

void solve(int t) {
	cout << "Case #"<< t<<": ";
	int N, M, mi = 474747, index, a,b;
	cin >> N >> M;
	vector<int> ZIP(N), VIS(N, 0), path, BFS(N, 0) ;
	map<int,int> MAP;
	vector<vector<int> > g(N);
	stack<int> st;

	for(int i=0; i < N; i++){ cin >> ZIP[i]; if(mi > ZIP[i]) { mi = ZIP[i]; index = i;} MAP[ZIP[i]] = i; }
	for(int i=0; i < M; i++) {
		cin >> a >> b; a--; b--; 
		g[a].push_back(b);
		g[b].push_back(a);
	}

	path.push_back(index);
	cout << ZIP[index];
	VIS[index] = true;
	int sm, maxBack = 0, p; bool cont;
	for(int n=0; n < N-1; n++) {
		sm = 474747;
		maxBack = 0;

		for(int i=path.size()-1 ; i > 0; i--) {
			BFS.resize(0); BFS.resize(N,0);
			for(int j=0; j < N; j++) if(VIS[j]) BFS[j] = true;
			for(int j=0; j < i; j++) BFS[path[j]] =false;

			st.push(index);
			while(!st.empty()) {
				p = st.top(); st.pop();
				for(int j=0; j < g[p].size(); j++)
					if(BFS[g[p][j]] == false) {
						BFS[g[p][j]] = true;
						st.push(g[p][j]);
					}
			}

			bool cont = true;
			for(int j=0; j < N; j++)
				if(BFS[j] == 0) cont = false;
			if(cont==false) break;
			maxBack++;
		}
		for(int i=path.size()-1; i >= ((int) path.size()) -1 - maxBack && i >= 0; i--) {
			for(int j=0; j < g[path[i]].size(); j++) {
				if(!VIS[g[path[i]][j]]) sm = min(sm, ZIP[g[path[i]][j]]);
			}
		}
		cont = true;
		while(1) {
			for(int j=0; j < g[path[path.size()-1]].size(); j++) {
				if(sm == ZIP[g[path[path.size()-1]][j]]) cont = false;
			}
			if(cont == false) break;
			path.pop_back();
		}

		cout << sm;
		VIS[MAP[sm]] = true;
		path.push_back(MAP[sm]);	
	}

	cout << endl;	
}

int main(void) {
	int T;
	cin >> T;

	for(int t=1;t<=T;t++) solve(t);
}