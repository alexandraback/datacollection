#include <bits/stdc++.h>
using namespace std;


int f(vector<int>  Q,int t){
	int cost = 0;
	for(int i = Q.size() - 1;i > t;i--)
		if(Q[i]){
			cost += Q[i];
			Q[i - t] += Q[i];
		}
	return cost + t;
}

int solve(vector<int> &  Q){
	int s = 1,e = Q.size() - 1,m,ans = e;
	for(int i = s;i <= e;i++)
		ans = min(ans,f(Q,i));
	return ans;
}

int main(){
	int T,D,a;
	scanf("%d",&T);
	for(int t = 1;t <= T;t++){
		scanf("%d",&D);
		vector<int> V(D);
		for(int i = 0;i < D;i++)scanf("%d",&V[i]);
			sort(V.begin(),V.end());
		vector<int> Q(V.back() + 1,0);
		for(int i = 0;i < V.size();i++) Q[V[i]]++;
		printf("Case #%d: %d\n",t,solve(Q));
	}
	return 0;
}