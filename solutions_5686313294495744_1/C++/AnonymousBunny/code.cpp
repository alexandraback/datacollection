#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define left _left
#define right _right
#define maxn 4010
int uu;

void print(int res){
	cout<<"Case #"<<uu<<": "<<res<<endl;
}
vector <int> L, R;
map <string, int> M;
vector <int> adj[maxn];



int vis[maxn], left[maxn], right[maxn];
void reset (){
	for (int i=0; i<maxn; i++){
		vis[i]= 0;
		left[i]= -1;
		right[i]= -1;
		adj[i].clear();
	}
	L.clear();
	R.clear();
	M.clear();
}

bool dfs (int v){
	if (vis[v]) return 0;
	int nt;
	vis[v]= 1;
	for (int i=0; i<adj[v].size(); i++){
		nt= adj[v][i];
		if (right[nt]==-1){
			right[nt]= v;
			left[v]= nt;
			return 1;
		}
	}
	for (int i=0; i<adj[v].size(); i++){
		nt= adj[v][i];
		if (dfs(right[nt])){
			right[nt]= v;
			left[v]= nt;
			return 1;
		}
	}
	return 0;
}

int getnt (int cur){
	for (int i=0; i<=cur; i++) vis[i]= 0;
	int res= 0;
	bool done;
	do{
		done= 1;
		for (int i=0; i<=cur; i++) vis[i]= 0;
		for (int i=0; i<R.size(); i++){
			if (left[R[i]]==-1  and dfs(R[i])) done= 0;
		}
	} while (!done);
	for (int i=1; i<=cur; i++) if (left[i]!=-1) res++;
	return res;
}


void solve(){
	int n, m;
	string p, q;
	cin>>n;
	int cur= 0;
	for (int i=1; i<=n; i++){
		cin>>p>>q;
		q+="!";
		if (!M[p]) {
			cur++;
			M[p]= cur;
		}
		if (!M[q]){
			cur++;
			M[q]= cur;
		}
		L.push_back(M[p]);
		R.push_back(M[q]);
	//	cout<<"add "<<M[p]<<" "<<M[q]<<endl;
		adj[M[p]].push_back(M[q]);
		adj[M[q]].push_back(M[p]);
	}
	int res= cur-getnt(cur);
	res= n-res;
//	cout<<"hi "<<getnt(cur)<<endl;
	cout<<"Case #"<<uu<<": "<<res<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for (uu=1; uu<=t; uu++){
		reset();
		solve();
	}
	return 0;
}
