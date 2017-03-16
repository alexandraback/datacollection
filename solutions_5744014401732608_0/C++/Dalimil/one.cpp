#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vvi mat;
vector<ll> ways;
vi seen;
vi topo;
void countWays(int n){
	for(int j=0;j<topo.size();j++){
		int k = topo[j];
		//if(n == 2) cout << "s "<<k << endl;
		for(int i=0;i<n;i++){
			if(mat[k][i] == 1){ // edge
				// if(seen[i] == 1) return false;
				ways[i] += ways[k];
			}
		}
	}
}

bool topolog(int u, int n){
	seen[u] = 1;
	for(int i=0;i<n;i++){
		if(mat[u][i] == 1){
			if(seen[i] == 1) return false;

			if(seen[i] == 0) topolog(i, n);
		}
	}
	seen[u] = 2;
	topo.push_back(u);
}

void printMat(int n){
	cout << "=------"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << mat[i][j];
		}cout << endl;
	}
	cout << "--------"<<endl;
}
int solve(int a, int b, int n, int m){
	if(a == n){
		/*if(n == 5 && mat[0][1] && mat[0][4] && mat[1][2] && mat[1][3] && mat[2][4] && mat[3][2] && mat[3][4]){
			 cout << "go "<<endl;
			 printMat(n);
		}*/
		seen = vi(n, 0);
		topo = vi();
		int ok = topolog(0, n);
		if(!ok) return false;
		reverse(topo.begin(), topo.end());
		//if(n == 5 && mat[0][1] && mat[0][4] && mat[1][2] && mat[1][3] && mat[2][4] && mat[3][2] && mat[3][4]){
		/*if(n == 5){
			cout <<"start";
			for(int i=0;i<topo.size();i++){
				cout << topo[i] <<" ";
			}cout << endl;
		}*/
		ways = vector<ll>(n, 0);
		ways[0] = 1;
		countWays(n);
		ll cc = ways[n-1];
		/*if(n == 2){
			for(int i=0;i<ways.size();i++){
				cout << ways[i] <<" ";
			} cout << endl;
		}*/
		if(cc == m) return true;
		return false;
	}

	int na = a;
	int nb = b;
	if(b != n-1) nb++;
	else{
		na++;
		nb = 0;
	}
	if(a == b) mat[a][b] = 0;
	else if(a == n-1) mat[a][b] = 0;
	else if(mat[b][a] == 1) mat[a][b] = 0;
	else{
		mat[a][b] = 1;
		int ok = solve(na, nb, n, m);
		if(ok) return true;
		mat[a][b] = 0;
	}
	return solve(na, nb, n, m);
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		ll n, m; cin >> n >> m;
		mat = vvi(n, vi(n, -1));
		int ok = solve(0, 0, n, m);

		cout << "Case #"<<t<<": ";
		if(ok){
			cout << "POSSIBLE"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout << mat[i][j];
				}cout << endl;
			}
		}else{
			cout << "IMPOSSIBLE"<<endl;
		}
	}

}
