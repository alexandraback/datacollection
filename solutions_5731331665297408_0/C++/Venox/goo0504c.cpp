	#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <math.h> 
#include <algorithm> 
#include <stdio.h> 
using namespace std;


#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())

int dfs(vector< VI > &pt,int st,vector<int> &av){
	int a=1;
	av[st]=0;
	REP(i,pt[st].size()){
		if(av[pt[st][i]])a+=dfs(pt,pt[st][i],av);
	}
	return a;

}

struct cmp
{
 bool operator()(const pair<string,int>  &a,const pair<string,int>  &b)
 {
	 return a.first>b.first;//×îÐ¡¶Ñ
 }
};
string smartdfs(vector< VI > &pt,vector<string> &dir,int st,vector<int> &av){
	string a;
	av[st]=0;
	priority_queue<pair<string,int>,vector< pair<string,int> >, cmp > qu;
	qu.push(MP(dir[st],st));
	while(!qu.empty()){
		int cu=qu.top().second;
		qu.pop();
		a+=dir[cu];
		REP(i,pt[cu].size()){
			if(av[pt[cu][i]]){
				qu.push(MP(dir[pt[cu][i]],pt[cu][i]));
				av[pt[cu][i]]=0;
			}
		}
	}
	
	return a;

}
string smartdfs2(vector< VI > &pt,vector<string> &dir,int st,vector<int> &av){
	string a;
	av[st]=0;
	a+=dir[st];
	priority_queue<pair<string,int>,vector< pair<string,int> >, cmp > qu;
	REP(i,pt[st].size()){
		int cu=pt[st][i];
		if(av[cu]){
			qu.push(MP(dir[cu],cu));
		}
	}
	while(!qu.empty()){
		int cu=qu.top().second;
		qu.pop();
		if(av[cu]){
			a+=smartdfs2(pt,dir,cu,av);
		}
	}
	return a;

}
void judge(){
	int  n,m;
	scanf("%d%d",&n,&m);
	vector<pair<string,int >> zip(n);
	vector<string> dir(n);
	REP(i,n){
		cin>>zip[i].first;
		dir[i]=zip[i].first;
		zip[i].second=i;
	}
	sort(ALL(zip));
	vector< VI > pat(n,vector<int>(0));
	vector< VI > ref(n,vector<int>(0));
	REP(i,m){
		int f,t;
		cin>>f>>t;
		--f,--t;
		pat[f].push_back(t);
		pat[t].push_back(f);
		ref[t].push_back(f);
	}
	/*vector<int> rs;
	REP(i,n){
		vector<int> av(n,1);
		int test=dfs(pat,i,av);
		if(test==n)rs.push_back(i);
	}*/
	int root=zip[0].second;
	/*for(int i=0;i<rs.size();++i){
		if(dir[rs[i]]<dir[root]){
			root=rs[i];
		}
	}*/
	
	vector<int> avi(n,1);
	cout<<smartdfs2(pat,dir,root,avi);


}
int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		cerr<<tt<<endl;
		printf("Case #%d: ",tt+1);
		judge();
		
		printf("\n");
	}




	return 1;



}