#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
bool visited[1000];
int to[1000];
vector<int> rev[1000];
vector<int> vs;
int cmp[1000];
int getdepth(int cur){
	if(visited[cur])	return 0;
	visited[cur]=true;
	int ret=0;
	for(int i=0;i<rev[cur].size();i++){
		if(!visited[rev[cur][i]]){
			if(rev[cur][i]!=to[cur]){
				ret=max(ret,getdepth(rev[cur][i]));
			}
		}
	}
	return ret+1;
}
void dfs(int v){
	visited[v]=true;
	if(!visited[to[v]])	dfs(to[v]);
	vs.push_back(v);
}
void rdfs(int v,int k){
	visited[v]=true;
	cmp[v]=k;
	for(int i=0;i<rev[v].size();i++){
		if(!visited[rev[v][i]])	rdfs(rev[v][i],k);
	}
}
	
int main(){
	ofstream ofs("out.txt");
	int t;	cin>>t;
	for(int cases=1;cases<=t;cases++){
		int n;	cin>>n;
		memset(prev,-1,sizeof(prev));
		for(int i=0;i<n;i++){
			visited[i]=false;
			to[i]=n;
			rev[i].clear();
			cmp[i]=-1;
		}
		for(int i=0;i<n;i++){
			cin>>to[i];
			to[i]--;
			rev[to[i]].push_back(i);
		}
		int ret=1;
		for(int i=0;i<n;i++){
			if(to[to[i]]==i){
				ret=max(ret,getdepth(i)+getdepth(to[i]));
			}
		}
		memset(visited,0,sizeof(visited));
		vs.clear();
		for(int v=0;v<n;v++){
			if(!visited[v])	dfs(v);
		}
		memset(visited,0,sizeof(visited));
		int k=0;
		for(int i=vs.size()-1;i>=0;i--){
			if(!visited[vs[i]])	rdfs(vs[i],k++);
		}
		map<int,int> mp;
		for(int i=0;i<n;i++){
			mp[cmp[i]]++;
		}
		for(auto it:mp){
			ret=max(ret,it.second);
		}
		ofs<<"Case #"<<cases<<": "<<ret<<endl;
	}
	ofs.close();
	return 0;
}
