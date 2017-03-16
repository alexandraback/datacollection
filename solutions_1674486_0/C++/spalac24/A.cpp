using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAXN 1005

int mat [MAXN][MAXN];
int direct [MAXN][MAXN];
int n;
int univn;
bool univ = false;
vector <int> graph [MAXN];
int start;

bool dfs (int node) {
	mat[start][node]++;
	if ((mat[start][node] == 2) && start != node)  {
	//	cout<<"Came from "<<start<<" to "<<node<<endl;
		return true;	
	}
	for (int i = 0; i < n; ++i) {
		if (direct[node][i]) {
			if (dfs(i)) {univ = true;return true;	}
		}	
	}
	
	return false;
	
}

int main(){
	int t;
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n;
		int a,b,m;
		cout<<"Case #"<<cas<<": ";
		univ = false;
		For(i,0,n+5) For(j,0,n+5) {mat[i][j] = 0;direct[i][j] = 0;}
		
		for (int i = 0; i < n; ++i) {
			graph[i].clear();
			cin>>m;
			while(m--){
				cin>>b;
				//graph[a].push_back(b);
				//mat[i][b-1] = 1;
				direct[i][b-1] = 1;	
			}
		}
		
		bool test = true;
			for (int i = 0; test && (i < n) && !univ; ++i) {
				start = i;
				if(dfs(i)){univ = true;}
			}
		if (univ) cout<<"Yes"<<endl;
		else cout <<"No"<<endl;
		/*for (int i  = 0; i < n; ++i) {
			For(j,0,n){
				cout<<mat[i][j]<<" ";	
			}	
			cout<<endl;
		}*/
			
	}
return 0;
}
