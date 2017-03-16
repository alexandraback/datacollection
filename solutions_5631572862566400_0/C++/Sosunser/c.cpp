#include <bits/stdc++.h>
using namespace std;

int t,n,sol;
int bff[1001];
int used[1001];
int startNode;
int inCircle = 1;

void solve(int node, bool req){
	used[node] = 1;
	if((bff[node] == startNode) || req == 0){
		sol = max(sol,inCircle);
	}
	if(req){
		if(!used[bff[node]]){
			inCircle++;
			if(bff[bff[node]] != node) solve(bff[node],1);
			else solve(bff[node],0);
			inCircle--;
		}
	}else{
		for(int i = 0; i < n; i++){
			if(!used[i]){
				inCircle++;
				if(bff[i] != node) solve(i,1);
				else solve(i,0);
				inCircle--;
			}
		}
	}
	used[node] = 0;
	return;
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d\n",&t);
	for(int i = 1; i <= t; i++){
		sol = 0;
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			scanf("%d",&bff[j]);
			bff[j]--;
		}
		for(int j = 0; j < n; j++){
			startNode = j;
			solve(j,1);
		}
		cout << "Case #" << i << ": " << sol << endl;
	}
}