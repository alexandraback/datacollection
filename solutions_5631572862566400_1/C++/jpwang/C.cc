#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int F[1024];
int v[1024], loop[1024];

int maxloop, N;

int countloop(int i){
	if(loop[i])
		return 0; 
	loop[i]=1;
	return countloop(F[i]) + 1;
}

void dfs(int i, int c){
	if(v[i]==c){
		//loop 
		int l = countloop(i); 
		if(l>maxloop)
			maxloop=l;
		return;
	}
	if(v[i])
		return;
	v[i]=c; 
	dfs(F[i],c);
}

vector<int> adj[1024];

int reverse(int i){
	int b=0;
	for(int j=0; j<adj[i].size(); j++){
		if(F[i] == adj[i][j])continue;
		int c = reverse(adj[i][j]); 
		b = max(b, c); 
	}
	return b+1;
}

int main(){
	int T;
	cin >> T;
	for(int k=0; k<T; k++){
		cin >> N;
		for(int i=0; i<N; i++)
			adj[i].clear();
			
		for(int i=0; i<N; i++){
			cin >> F[i];
			F[i]--;
			v[i]=loop[i]=0;
			adj[F[i]].push_back(i);
		}
		
		maxloop=1;
		int chain=0;

		for(int i=0; i<N; i++){
			dfs(i, i+1); 
			if(F[F[i]]==i)
				chain+=reverse(i);
		}


		cout << "Case #" << (k+1) << ": " << max(chain, maxloop) << "\n";
	}
}
