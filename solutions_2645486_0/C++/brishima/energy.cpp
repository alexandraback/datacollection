#include<fstream>
#include<cstring>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;


long long T,e,r,n,v[10000000],hb[10000000],ha[10000000];
set<int>done;
struct comp{
	bool operator()(const int& a,const int& b)const{return v[a]<v[b];}
};
priority_queue<int,vector<int>,comp>que;
ifstream fin("input.in");
ofstream fout("output.out");

int main(){
	fin>>T;
	for(int k=1;k<=T;k++){
		while(!que.empty())que.pop();
		done.clear();
		fin>>e>>r>>n;
		long long tot=0;
		for(int i=0;i<n;i++){
			fin>>v[i];
			que.push(i);
		}
		while(!que.empty()){
			int node=que.top();
			que.pop();
			long long en=e;
			set<int>::iterator right=done.upper_bound(node);
			set<int>::iterator left=right;
			if(left!=done.begin()){
				left--;
				en=min(en,(node-*left)*r+ha[*left]);
			}
			hb[node]=en;
			if(right!=done.end())en=min(en,en-(hb[*right]-(*right-node)*r));
			tot+=en*v[node];
			ha[node]=hb[node]-en;
			done.insert(node);
		}
		fout<<"Case #"<<k<<": "<<tot<<'\n';
	}
}