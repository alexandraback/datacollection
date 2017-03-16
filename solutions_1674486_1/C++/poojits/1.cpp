#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long int LL;
bool traverse(vector< vector<bool> > &graph,int &c,int &n,vector< vector<bool> > &reach){
	stack<int> s;
	s.push(c);
	while(!s.empty()){
		int node=s.top();
		s.pop();
		for(int i=0;i<n;i++){
               		if(i!=c&&graph[node][i]){
               			if(!reach[c][i]){
               				reach[c][i]=true;
               				s.push(i);
               			}
               			else{
               				return true;
               			}
               		}
               	}
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	for(int cases=1;cases<=t;cases++){
		int n,m;
		cin>>n;
		vector< vector<bool> > matrix(n,vector<bool>(n,false));
		vector< vector<bool> > reach(n,vector<bool>(n,false));
		for(int i=0;i<n;i++){
			cin>>m;
			for(int j=1;j<=m;j++){
				int x;
				cin>>x;
				matrix[i][x-1]=true;
			}
		}
		bool what=false;
		for(int i=0;i<n;i++){
			what = traverse(matrix,i,n,reach);
			if(what) break;
		}
		if(what){
			cout<<"Case #"<<cases<<": "<<"Yes"<<endl;
		}
		else {
			cout<<"Case #"<<cases<<": "<<"No"<<endl;
		}
	}
	return 0;
}
