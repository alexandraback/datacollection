#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

using namespace std;

using ll = long long;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=1000;
int to[Nmax];
vector<int> come[Nmax];
int n;

void Input(){
	n=read();
	REP(i,n)
		come[i].clear();
	REP(i,n){
		to[i]=read()-1;
		come[to[i]].PB(i);
	}
}

bool vis[Nmax];

int Sub1(int s){
	memset(vis,false,sizeof(vis));
	int p=s;
	vis[s]=true;
	int res=1;
	while(1){
		int t=to[s];
		if(t==p)
			return res;
		if(vis[t])
			return 0;
		s=t;
		vis[s]=true;
		res++;
	}
	return res;
}

int Sub2(int s){
	vis[s]=true;
	int ret=0;
	for(auto c:come[s]){
		if(to[s]==c)
			continue;
		ret=max(ret,Sub2(c));
	}
	return ret+1;
}

void Solve(){
	int ans=0;
	REP(i,n)
		ans=max(ans,Sub1(i));
	int w=0;
	memset(vis,false,sizeof(vis));
	REP(i,n)
		if(!vis[i]&&to[to[i]]==i){
			w+=Sub2(i);
			w+=Sub2(to[i]);
		}
	ans=max(ans,w);
	printf("%d\n",ans);
}

int main(){
	int t=read();
	REP(caseNumber,t){
		Input();
		printf("Case #%d: ",caseNumber+1);
		Solve();
	}
}