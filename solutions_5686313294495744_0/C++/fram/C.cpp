#include <iostream>
#include <vector>
using namespace std;

int p, n;
string a[2000], b[2000];
string col[4000];
int mat;

vector<int> e[4000];
vector<int> taken[4000];
bool visited[4000];
bool preso[4000];

bool vai(int v){
	visited[v] = true;
	for(int i=0; i<(int)e[v].size(); i++) if(taken[v][i] == 0){
		int u = e[v][i]; if(visited[u]) continue;
		visited[u] = true;
		if(preso[u] == 0){
			preso[u] = 1;
			preso[v] = 1;
			taken[v][i] = 1;
			int j = 0; while(e[u][j] != v) j++; taken[u][j] = 1;
			mat++;
			return true;
		}
		
		for(int j=0; j<(int)e[u].size(); j++) if(taken[u][j] == 1){
			int w = e[u][j]; if(visited[w]) continue;
			if(vai(w)){
				preso[w] = preso[u] = preso[v] = 1;
				taken[v][i] = 1;
				int k = 0; while(e[u][k] != v) k++; taken[u][k] = 1;
				taken[u][j] = 0;
				k = 0; while(e[w][k] != u) k++; taken[w][k] = 0;
				return true;
			}
		}
	}
	return false;
}

void solve(){
	cin >> p;
	n = 0;
	for(int i=0; i<p; i++){
		cin >> a[i] >> b[i];
		a[i] += '0';
		b[i] += '1';
		int na = 0; while(na < n && col[na] != a[i]) na++;
		if(na >= n) {col[n] = a[i]; n++;}
		int nb = 0; while(nb < n && col[nb] != b[i]) nb++;
		if(nb >= n) {col[n] = b[i]; n++;}
		
		e[na].push_back(nb); taken[na].push_back(0);
		e[nb].push_back(na); taken[nb].push_back(0);
	}
	
	for(int i=0; i<n; i++) preso[i] = 0;
	mat = 0;
	
	while(1){
		bool found = false;
		for(int i=0; i<n; i++) visited[i] = false;
		for(int i=0; i<n; i++) if(!visited[i] && !preso[i]) if(vai(i)) found = true;
		if(!found) break;
	}
	cerr << p << ' ' << mat << ' ' << n << endl;
	cout << p +mat- n << endl;
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
