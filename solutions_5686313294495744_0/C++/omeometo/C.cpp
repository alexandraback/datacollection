#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool aug(vector<vector<int> > adj,int p,vector<int>& partner,vector<int>& vis){
	if(p==-1)return true;
	for(int i=0;i<adj[p].size();i++){
		int q=adj[p][i];
		if(vis[q]==0){
			vis[q]=1;
			if(aug(adj,partner[q],partner,vis)){
				partner[p]=q;
				partner[q]=p;
				return true;
			}
		}
	}
	return false;
}

int calc(vector<vector<int> > adj, int l){
	int n=adj.size();
	vector<int> partner(n,-1);
	int ret=0;
	for(int i=0;i<l;i++){
		vector<int> vis(n,0);
		if(aug(adj,i,partner,vis))ret++;
	}
	return ret;
}

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		
		int n;
		scanf("%d",&n);
		vector<vector<int> > adj0(n);
		vector<vector<int> > adj1(n);
		vector<vector<int> > adj(2*n);
		map<string,int> idx0,idx1;
		for(int i=0;i<n;i++){
			char buf0[30],buf1[30];
			scanf("%s%s",buf0,buf1);
			string s0=string(buf0),s1=string(buf1);
			int p,q;
			if(idx0.count(s0)>0)p=idx0[s0]; else {p=idx0.size();idx0.insert(make_pair(s0,p));}
			if(idx1.count(s1)>0)q=idx1[s1]; else {q=idx1.size();idx1.insert(make_pair(s1,q));}
			adj0[p].push_back(q);
			adj1[q].push_back(p);
		}
		for(int i=0;i<adj0.size();i++)for(int j=0;j<adj0[i].size();j++)adj[i].push_back(adj0[i][j]+adj0.size());
		for(int i=0;i<adj1.size();i++)for(int j=0;j<adj1[i].size();j++)adj[i+adj0.size()].push_back(adj1[i][j]);
		
		
		printf("%d\n",n+calc(adj,adj0.size())-(int)idx0.size()-(int)idx1.size());
	}
}