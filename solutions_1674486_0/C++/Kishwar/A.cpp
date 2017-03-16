/*
ID: kishwarshafin
PROG:
LANG: C++
*/
/*
Timus JI: 119454XP
*/
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1010
#define INF 2147483647
#define in(a) freopen(a,"r",stdin)
#define out(a) freopen(a,"w",stdout)
vector<int>G[MAX];
bool color[MAX];
bool ins[MAX];
bool outs[MAX];
int visit[MAX];
int n_v;
int src;
int sink;
bool ache;
int now;
void dfs(int src)
{
    color[src]=1;

    for(int i=0;i<G[src].size();i++)
    {
        visit[G[src][i]]++;
        if(visit[G[src][i]]>1 && G[src][i]!=now)ache=true;
        if(color[G[src][i]]==0)
            dfs(G[src][i]);
    }
}


void take_input()
{
    cin>>n_v;
    memset(ins,0,sizeof(ins));
    memset(outs,0,sizeof(outs));
    memset(color,0,sizeof(color));
    for(int i=1;i<=n_v;i++)G[i].clear();

    for(int i=1;i<=n_v;i++)
    {
        int M;
        cin>>M;
        for(int j=0;j<M;j++)
        {
            int y;
            cin>>y;
            G[i].push_back(y);
            outs[i]=1;
            ins[y]=1;
        }
    }
    ache=false;
    for(int i=1;i<=n_v;i++)
    {
        if(ins[i]==1)continue;
        ache=false;
        memset(visit,0,sizeof(visit));
        memset(color,0,sizeof(color));
        now=i;
        dfs(i);
        if(ache)break;
    }
    if(ache==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
	in("in.txt");
	out("out.txt");
    #endif

    int t,caseno=1;
    cin>>t;
    while(t--)
    {
        printf("Case #%d: ",caseno++);
        take_input();
    }
	return 0;
}
