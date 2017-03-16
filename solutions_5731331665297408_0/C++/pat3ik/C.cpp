#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

string zip[maxn];
int d2i[maxn],is[maxn],n;
vi vtx[maxn];
int bst[maxn],curr[maxn],cl,bl;


bool cmpx(int a,int b){
	return zip[a] < zip[b];
}
bool is_cool(){
	if(bl == 0) return true;
	FOR(i,cl){
		if(bst[i] < curr[i]) 
			return false;
		else if(curr[i] < bst[i]) return true;
	}
	return true;
}
void find_best(){
	if(is_cool())
	{
		bl = cl;
		FOR(i,bl) bst[i] = curr[i];
	}
}

int last[maxn];
bool vis[maxn];

void f(int x,bool back){
	if(!vis[x]) curr[cl++] = x;
	vis[x] = true;
	
	if(cl == n){
		find_best();
		if(!back){ vis[x] = false; cl--; }
		return;
	}
	if(!is_cool()){
		if(!back){ vis[x] = false; cl--; }
		return;
	}
	
	FOR(i,vtx[x].size())
		if(!vis[vtx[x][i]])
		{
			last[vtx[x][i]] = x;
			f(vtx[x][i],false);
			last[vtx[x][i]] = -1;
		}
	
	if(last[x] != -1) f(last[x],true); // go back
	
	if(back) return;
	
	vis[x] = false;
	cl--;
}
int main(){
	int T,m,a,b;
	cin>>T;
	
	FORR(tt,1,T + 1){
		cin>>n>>m;
		
		FOR(i,n) vtx[i].clear();
		FOR(i,n){
			cin>>zip[i];
			is[i] = i;
		}
		
		sort(is,is + n,&cmpx);
		FOR(i,n){
			d2i[is[i]] = i;
		}
		FOR(i,m)
		{	
			cin>>a>>b;
			a--; b--; 
			vtx[d2i[a]].pb(d2i[b]);
			vtx[d2i[b]].pb(d2i[a]);
		}
		
		FOR(i,n) sort(vtx[i].begin(),vtx[i].end());
		bl = 0;
			
		memset(last,-1,sizeof last);
		FOR(i,n)
		{
			cl = 0;
			memset(vis,0,sizeof vis);
			memset(last,-1,sizeof last);
			f(i,false);
		}
		string ans = "";
		FOR(i,n)
			ans += zip[is[bst[i]]];
		cout<<"Case #"<<tt<<": "<<ans<<"\n";
	}
	return 0;
}
