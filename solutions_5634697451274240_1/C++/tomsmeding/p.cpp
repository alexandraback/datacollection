#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cassert>

using namespace std;

unordered_set<vector<bool>> seen;

int bfs(int N,vector<bool> inpc){
	seen.clear();
	int i,j;
	for(i=0;i<N;i++)if(!inpc[i])break;
	if(i==N)return 0;
	queue<pair<vector<bool>,int>> qu;
	qu.emplace(inpc,0);
	vector<bool> flipped;
	flipped.resize(N);
	while(true){
		assert(qu.size());
		const pair<vector<bool>,int> &pcp=qu.front();
		const vector<bool> &pc=pcp.first;
		const int depth=pcp.second;
		if(seen.find(pc)!=seen.end()){
			// cerr<<'*';
			qu.pop();
			continue;
		}
		seen.insert(pc);
		for(i=0;i<N;i++){ //last one to flip
			while(i<N-1&&pc[i]==pc[i+1])i++;

			for(j=0;j<=i;j++)flipped[j]=!pc[i-j];
			for(;j<N;j++)flipped[j]=pc[j];
			for(j=0;j<N;j++)if(!flipped[j])break;
			if(j==N)return depth+1;
			qu.emplace(flipped,depth+1);
		}
		qu.pop();
	}
}

int easy(int N,vector<bool> pc){
	int ch=0;
	for(int i=1;i<N;i++)ch+=pc[i]!=pc[i-1];
	return ch+!pc[N-1];
}

int main(){
	int T,tt;
	cin>>T;
	string line;
	for(tt=1;tt<=T;tt++){
		cout<<"Case #"<<tt<<": ";
		cin>>line;
		int N=line.size();
		vector<bool> pc;
		pc.resize(N);
		for(int i=0;i<N;i++)pc[i]=line[i]=='+';
		//int res=bfs(N,pc);
		int res2=easy(N,pc);
		//assert(res==res2);
		cout<<res2<<endl;
	}
}
