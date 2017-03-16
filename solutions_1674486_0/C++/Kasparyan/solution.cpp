#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#pragma comment(linker, "/STACK:165777216")
using namespace std;
vector <int> gr[1013];
int n;
int b[1013];
vector <int> topsort;
bool ans;
void dfs1(int v){
	b[v]=true;
	for(int i=0; i<gr[v].size(); i++){
		if(b[gr[v][i]]==0){
			dfs1(gr[v][i]);
		}
	}
	topsort.push_back(v);
}
int step=1;
void dfs2(int v){
	b[v]=step;
	for(int i=0; i<gr[v].size(); i++){
		if(b[gr[v][i]]!=step){
			dfs2(gr[v][i]);
		}else{
			if(b[gr[v][i]]==step){
				ans=true;
			}
		}
	}
}
int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n;
		for(int j=0; j<=n; j++){
			gr[j].clear();
		}
		int m;
		for(int j=1; j<=n; j++){
			cin>>m;
			int v;
			for(int k=0; k<m; k++){
				cin>>v;
				gr[j].push_back(v);
			}
		}
		memset(b,0,sizeof(b));
		topsort.clear();
		ans=false;
		for(int j=1; j<=n; j++){
			if(b[j]==0){
				dfs1(j);
			}
		}
		memset(b,0,sizeof(b));
		ans=false;
		for(int j=n-1; j>=0; j--){
			if(b[topsort[j]]==0){
				dfs2(topsort[j]);
				step++;
			}
		}
		cout<<"Case #"<<i+1<<": ";
		if(ans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}