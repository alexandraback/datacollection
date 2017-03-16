#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include <list>
#include <sstream>

#define F(i,n) for(int i = 0, n_ = (n); i<n_; i++)
#define FS(i,s,n) for(int i = (s), n_ = (n); i<n_; i++)
#define AA first
#define BB second
#define XX first.first
#define YY first.second
#define ZZ second
#define PB push_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PRI;
typedef pair<PRI,int> TRI;

template<typename T> inline void updatemin(T &a, T b) {if(a>b) a=b;}
template<typename T> inline void updatemax(T &a, T b) {if(a<b) a=b;}
template<typename T> inline T gcd(T a, T b) {
	T d;
	while(b!=0) d=b, b=a%b, a=d;
	return a;
}

typedef vector< list<int> > graph;

bool dfs(graph &g, vector<int> &pre, int dest, int cur){
	if(cur==dest) return true;
	bool found = false;
	for(list<int>::iterator it = g[cur].begin(); it != g[cur].end(); ++it)
		if(pre[*it]==-1){
			pre[*it]=cur;
			if(dfs(g,pre,dest,*it)) return true;
		}
	return false;
}

bool check(graph &g, int A, int B){
	vector<int> pre(g.size(), -1);
	pre[A]=A;
	
	if(!dfs(g, pre, B, A)) return false;

	int D = B, C = pre[D];
	do{
		g[C].remove(D);
		vector<int> pre(g.size(), -1);
		pre[A]=A;
		if(dfs(g, pre, B, A)) return true;
		g[C].push_back(D);
		D=C; C=pre[D];
	} while(D!=A);

	return false;
}

int main(int argc, char* argv[]){
	int T, N, M, k;
	cin>>T;
	F(test,T){
		cin>>N;
		graph g(N);
		F(i,N){
			cin>>M;
			F(j,M){
				cin>>k;
				g[i].push_back(k-1);
			}
		}

		bool check_ = false;
		F(i,N){
			F(j,N) if(i!=j) if(check(g,i,j)){
				check_ = true;
				break;
			}
			if(check_) break;
		}

		if(check_) cout<<"Case #"<<test+1<<": Yes"<<endl;
		else cout<<"Case #"<<test+1<<": No"<<endl;
	}

	return 0;
}