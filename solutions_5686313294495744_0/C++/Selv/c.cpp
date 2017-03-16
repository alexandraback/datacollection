#include<bits/stdc++.h>

using namespace std;

map<string,int> M;
int cnt;

vector<int> V[4040];
int S[4040];
int U[4040],D[4040];

int Rep[4040];

int Find(int a){
	if(Rep[a] != a) Rep[a] = Find(Rep[a]);
	return Rep[a];
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return false;
	Rep[a] = b;
	return true;
}


int dfs(int a, int &x, int &y){
	x++;
	S[a] = 1;
	for(int v : V[a]){
		if(!S[v]) dfs(v,y,x);
	}
}

void test(){
	int n;
	cin >> n;

	M.clear();
	cnt = 0;
	
	for(int i = 0; i < n*3+50; i++){
		V[i].clear();
		S[i] = 0;
		U[i] = 0;
		D[i] = 0;
		Rep[i] = i;
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		string aa,bb;
		cin >> aa >> bb;
		aa += "L";
		bb += "R";
		int a, b;

		if(M.count(aa) == 0) M[aa] = ++cnt;
		if(M.count(bb) == 0) M[bb] = ++cnt;


			V[M[aa]].push_back(M[bb]);
			V[M[bb]].push_back(M[aa]);
			D[M[aa]] ++;
			D[M[bb]] ++;

	}

	for(int i = 1; i <= cnt; i++){
		if(!S[i]){
			int x = 0;
			int y = 0;
			dfs(i,x,y);
			ans += max(x,y);
		}
	}
	
	printf("%d\n", n-ans);

}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		test();
	}
}

