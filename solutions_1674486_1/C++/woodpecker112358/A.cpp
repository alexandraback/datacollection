#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
#define pi (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define SZ 1001
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
vector<int> gr[SZ];
int deg[SZ];
bool vis[SZ];
int n,nw;
bool check(int node)
{
    //cout<<node<<endl;
    vis[node]=true;
    for(int i=0;i<gr[node].size();i++)
    {
        //cout<<i<<endl;
        //cout<<i<<endl;
        if(vis[gr[node][i]])
            return true;
        if(check(gr[node][i]))
            return true;
    }
    return false;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("sol.txt","w",stdout);
	int t,T,i,val,j;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    scanf("%d",&n);
	    memset(gr,0,sizeof(gr));
	    memset(deg,0,sizeof(deg));
	    //memset(ma,-1,sizeof(mark));
	    for(i=1;i<=n;i++)
	    {
	        scanf("%d",&deg[i]);
	        for(j=0;j<deg[i];j++)
                {
                    scanf("%d",&val);
                    gr[val].push_back(i);
                }
	    }
	    bool ok=false;
	    for(i=1;i<=n;i++)
	    {
	        memset(vis,0,sizeof(vis));
	        if(check(i))
	        {
	            ok=true;
	            break;
	        }
	    }
		printf("Case #%d: ",t);
		if(ok)
            printf("Yes\n");
        else
            printf("No\n");
	}
	return 0;
}

