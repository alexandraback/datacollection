//#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
using namespace std;

ifstream cin("D-small-attempt6.in");
ofstream cout("mik.txt");

int key[200],startkeys[201];
vector< vector<int> > contents;
int T,K,N;

bool on(int mask,int i){ return (1<<i & mask); }
int turnon(int mask,int i){ return (1<<i | mask); }

int dp[1<<21];
int ch[1<<21];
int f(int state){
	if(dp[state]!=-1) return dp[state];
	if(state==(1<<N)-1) return 1;
	int keys[201];
	for(int i=0;i<=200;i++) keys[i]=startkeys[i];
	for(int i=0;i<N;i++){
		if(on(state,i)){
			keys[key[i]]--;
			for(int j=0;j<contents[i].size();j++) keys[contents[i][j]]++;
		}
	}
	dp[state]=0;
	for(int i=1;i<=200;i++){
		if(keys[i]>0){
			for(int j=0;j<N;j++) if(key[j]==i && !on(state,j)){
				int tmp=f(turnon(state,j));
				dp[state]=tmp || dp[state];
				if(tmp && (j<ch[state] || ch[state]==-1)) ch[state]=j;
			}
		}
	}
	return dp[state];
}
void g(int state,vector<int> &path){
	if(state==(1<<N)-1) return;
	path.push_back(ch[state]+1);
	g(turnon(state,ch[state]),path);
}
int main(){
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>K>>N;
		fill(&(dp[0]),&(dp[(1<<21)-1])+1,-1);
		fill(&(ch[0]),&(ch[(1<<21)-1])+1,-1);
		contents.clear();
		vector<int> v;
		for(int i=0;i<N;i++) contents.push_back(v);
		for(int i=0;i<200;i++) key[i]=0;
		for(int i=0;i<=200;i++) startkeys[i]=0;
		for(int i=0;i<K;i++){ int tmp; cin>>tmp; startkeys[tmp]++; }
		for(int i=0;i<N;i++){
			int Ti,Ki;
			cin>>Ti>>Ki;
			key[i]=Ti;
			for(int j=0;j<Ki;j++){
				int tmp; cin>>tmp;
				contents[i].push_back(tmp);
			}
		}
		cout<<"Case #"<<t<<": ";
		if(f(0)){
			vector<int> path;
			g(0,path);
			for(int i=0;i<N;i++){
				cout<<path[i];
				if(i!=N-1) cout<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}
	}
}