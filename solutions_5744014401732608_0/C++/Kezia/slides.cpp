#include <bits/stdc++.h>
using namespace std;

int b,m,ok,ct,o[10][10],vis[10],t,no;
vector<int> v[10];

void dfs(int pos, int par){
	if (vis[pos]){
		no=1; return;
	}
	if (pos==b) ct++;
	else{
		vis[pos]=1;
		int sz=v[pos].size();
		for (int i=0;i<sz;i++){
			dfs(v[pos][i],pos);
		}
		vis[pos]=0;
	}
}

void rec(int x, int y){
	if (ok) return;
	if (x==b){
		ct=no=0; memset(vis,0,sizeof(vis)); dfs(1,-1);
		if (!no&&ct==m){
			cout << "POSSIBLE\n";
			ok=1;
			for (int i=1;i<=b;i++){
				for (int j=1;j<=b;j++){
					cout << o[i][j];
				}
				cout << "\n";
			}
		}
	}else if (x==y) rec(x,y+1);
	else{
		int nxx=x,nxy=y+1;;
		if (!o[y][x]){
			o[x][y]=1; v[x].push_back(y);
			if (y==b){
				nxx=x+1; nxy=1;
			}
			rec(nxx,nxy);
			o[x][y]=0; v[x].pop_back();
		}	
		rec(nxx,nxy);
	}
}

int main(){
//	ios::sync_with_stdio(0); cin.tie(0);
	freopen("slides.in","r",stdin);
	freopen("slides.out","w",stdout);
	cin >> t;
	for (int tc=1;tc<=t;tc++){
		cout << "Case #" << tc << ": ";
		cin >> b >> m;
		ok=0; rec(1,1);
		if (!ok) cout << "IMPOSSIBLE\n";
	}
}
