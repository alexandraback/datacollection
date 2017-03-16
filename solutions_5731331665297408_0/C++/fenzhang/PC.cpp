#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

typedef long long int lnt;
typedef double dou;

int n,m;
int z[200];
#include<vector>
vector<int>e[200];
int cmp(int a,int b){
	return z[a]<z[b];
}
int vis[200];
int cvis[200];
int q[200],qs,qe;
int nocon(int w,int dpt){
	for(int i=0;i<n;i++){
		cvis[i]=vis[i];
	}
	qs=qe=0;
	q[qe++]=w;
	for(;qs<qe;){
		w=q[qs++];
		for(int i=0;i<(int)e[w].size();i++){
			int t=e[w][i];
			if(cvis[t]==dpt){
				return 0;
			}
			else{
				continue;
			}
			cvis[t]=7122*71;
		}
	}
	return 1;
}
void dfs(int w,int dpt){
	vector<int>a;
	a.push_back(w);
	for(;a.size();){
		sort(a.begin(),a.end(),cmp);
		w=a.front();
		for(int i=0;i+1<(int)a.size();i++)a[i]=a[i+1];
		a.pop_back();
		if(vis[w])continue;
		
		vis[w]=dpt;
		printf("%05d",z[w]);
		for(int i=0;i<e[w].size();i++){
			int t=e[w][i];
			if(vis[t]){
				continue;
			}
			if(nocon(t,dpt))dfs(t,dpt+1);
			else{a.push_back(t);}
		}
	}
}
void sol(int uuu){
	scanf("%d %d",&n,&m);
	int s=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",z+i);
		if(s==-1||z[s]>z[i]){
			s=i;
		}
	}
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end(),cmp);
		vis[i]=0;
	}
	printf("Case #%d: ",uuu);
	dfs(s,1);
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	puts("");
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("pc_s.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++)sol(ti);
	return 0;
}

