/*
* Filename:    C.cpp
* Desciption:  Desciption
* Created:     2016年05月01日 01时13分06秒 星期日
* Author:      JIngwei Xu [mail:xu_jingwei@outlook.com]
*
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

//Init Const
const int INF=1e7;
const int MAX_V=2000+7;
map<string,int> mapx,mapy;
//Global Variables
int n,m,t,ans;
string s1,s2;
//Function Declaration
struct edge{
	int to,cap,rev;
};
vector<edge>G[MAX_V];
bool used[MAX_V];

void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f){
	if(v==t)return f;
	used[v]=true;
	for (unsigned int i = 0; i < G[v].size(); i += 1)
	{
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(f==0)return flow;
		flow +=f;
	}
}

//Main Program
int main()
{
#ifdef AC_THIS_PROBLEM
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d",&t);
	for (int tcase = 1; tcase<=t; tcase += 1)
	{
		printf("Case #%d: ",tcase);
		scanf("%d",&n);
		
		int num1=0,num2=n;
		mapx.clear();
		mapy.clear();
		vector<edge>G[MAX_V];
		memset(used,false,sizeof(used));
		
		for (int i = 0; i < MAX_V; i += 1)
		{
			G[i].clear();
		}
		for (int i = 0; i < n; i += 1)
		{
			cin>>s1>>s2;
			if(mapx[s1]==0){
				num1++;
				mapx[s1]=num1;
				add_edge(0,num1,INF);
			}
			if (mapy[s2]==0)
			{
				num2++;
				mapy[s2]=num2;
				add_edge(num2,2*n+1,INF);
			}
			add_edge(mapx[s1],mapy[s2],1);
		}
//		printf("num1:%d,num2:%d\n",num1,num2-n);
		int nummax=max(num1,num2-n);
		add_edge(2*n+2,0,nummax);
//		ans=max_flow(2*n+2,2*n+1);
		printf("%d\n",n-nummax);
	}
	return 0;
}

