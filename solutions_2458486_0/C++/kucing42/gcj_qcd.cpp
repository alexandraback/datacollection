#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm> 
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[1<<21];
int papa[50],vis[1<<21],x,n,k,ty[50],nisi[50],isi[50][50],mau,t;
void dfs(int mask){
	vis[mask] = 1;
	//cout << mask << endl;
	for (int i = 0; i <n; ++i){
		if ((mask & (1<<i)) == 0){
			int tmp = mask | (1<<i);
			if (vis[tmp]) continue;
			v[tmp].assign(v[mask].begin(),v[mask].end());
			v[tmp][ty[i]]--;
			for (int j = 0; j < nisi[i]; ++j)
				v[tmp][isi[i][j]]++;
			dfs(tmp);
		}
	}
}

int solve(int mask,int pos){
	if (vis[mask]>-1) return vis[mask];
	//cout << mask <<" " << pos << endl;
	if (mask == mau){
		int tmp = pos;
		stack<int> s;
		while (!s.empty()) s.pop();
		while (tmp != n){
			s.push(tmp);
			tmp = papa[tmp];
		}
		while (!s.empty()){
			printf(" %d",1+s.top());
			s.pop();
		}
		puts("");
		return vis[mask] = 1;
	}
	//vis[mask] = 0;

	for (int i = 0; i <n; ++i){
		if ((mask & (1<<i)) == 0){
			if (v[mask][ty[i]] > 0){
				papa[i] = pos;
				if (solve(mask|(1<<i),i)) return vis[mask] = 1;
			}	
		}
	}
	return vis[mask] = 0;
}


int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&t);
	int tc = 0;
	while (tc<t){
		printf("Case #%d:",++tc);
		scanf("%d %d",&k,&n);
		mau = (1<<n)-1;
		v[0].assign(41,0);
		for (int i = 0; i <k; ++i){
			scanf("%d",&x);
			v[0][x]++;
		}

		for (int i = 0; i <n; ++i){
			scanf("%d %d",&ty[i],&nisi[i]);
			for (int j = 0; j <nisi[i]; ++j)
				scanf("%d",&isi[i][j]);
		}
		memset(vis,0,sizeof(vis));
		dfs(0);
		memset(vis,-1,sizeof(vis));
		if (solve(0,n)==0) puts(" IMPOSSIBLE");
	}
}