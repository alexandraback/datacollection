#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

int n,parent[MAX+1],v[MAX+1],vc,lastvc,pc[MAX],dp[MAX];

int longest_cycle(int node){
	vc++;
	if (v[node]>lastvc) return vc-v[node];
	if (v[node]) return 0;
	v[node]=vc;
	return longest_cycle(parent[node]);
}

void st(int node, int len=0){
	len++;
	if (v[node]>lastvc) return;
	if (dp[node]>len) return;
	v[node]=vc;
	dp[node]=len;
	if (parent[parent[node]]!=node) st(parent[node],len);
}

int main(){
	int res,t,u,i,j,k,a,b;
	cin>>t; for (u=0; u<t; u++){ cin>>n; 
		for (i=0; i<n; i++) v[i]=pc[i]=dp[i]=0; 
		for (i=0; i<n; i++){ cin>>a; a--; parent[i]=a; pc[a]++; }
		res=lastvc=vc=0; 
		for (i=0; i<n; i++) if (pc[i]==0){ a=longest_cycle(i); res=max(res,a); lastvc=vc; }
		for (i=0; i<n; i++) if (v[i]==0){ a=longest_cycle(i); res=max(res,a); lastvc=vc; }

		for (i=0; i<n; i++) if (pc[i]==0){ lastvc=vc; vc++; st(i); }
		k=0;
		for (i=0; i<n; i++) if (parent[i]>i && parent[parent[i]]==i) k+=max(1,dp[i])+max(1,dp[parent[i]]);
		res=max(res,k);
		cout<<"Case #"<<(u+1)<<": "<<res<<endl;
	}
	return 0;
}
