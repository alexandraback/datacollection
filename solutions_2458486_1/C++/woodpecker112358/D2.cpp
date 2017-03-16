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
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int K,N,cur_keys[205],chest[205],need[205];
bool taken[205];
vector<int>v[405],ans;
bool isposs(int no)
{
    bool vis[405]={false};
    int i,nw;
    queue<int> q;
    q.push(no);
    vis[no]=true;
    rep(i,N)
    {
        vis[i]=taken[i];
    }
    rep(i,203)
        if(cur_keys[i]&&i!=chest[no])
        {
            vis[i+N]=true;
            q.push(i+N);
        }
    while(!q.empty()&&!vis[chest[no]+N])
    {
        nw=q.front();
        q.pop();
        for(i=0;i<v[nw].size();i++)
        {
            if(nw<N&&vis[v[nw][i]+N])
                continue;
            else if(nw<N)
               vis[v[nw][i]+N]=true;
            else if(vis[v[nw][i]])
                continue;
            else
                vis[v[nw][i]]=true;
            if(nw<N)
                q.push(v[nw][i]+N);
            else
                q.push(v[nw][i]);
        }
    }
    if(vis[chest[no]+N])
        return true;
    return false;
}
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("Dout.txt","w",stdout);
	int t,T,val,sz,i,j;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    scanf("%d%d",&K,&N);
	    memset(cur_keys,0,sizeof(cur_keys));
	    memset(taken,0,sizeof(taken));
	    memset(need,0,sizeof(need));
	    rep(i,405)
            v[i].clear();
	    rep(i,K)
	    {
	        scanf("%d",&val);
	        cur_keys[val-1]++;
        }
	    rep(i,N)
	    {
	        scanf("%d",&chest[i]);
	        chest[i]--;
	        v[chest[i]+N].PB(i);
	        need[chest[i]]++;
	        scanf("%d",&sz);
	        v[i].resize(sz);
	        rep(j,sz)
	        {
                scanf("%d",&v[i][j]);
                v[i][j]--;
	        }
	    }
	    ans.clear();
	    rep(i,N)
	    {
	        rep(j,N)
	        {
	            if(taken[j]||!cur_keys[chest[j]])
                    continue;
                if(cur_keys[chest[j]]>1||need[chest[j]]==1)
                {
                    taken[j]=true;
                    ans.PB(j);
                    cur_keys[chest[j]]--;
                    need[chest[j]]--;
                    //cout<<j+1<<endl;
                    break;
                }
                else if(isposs(j))
                {
                    taken[j]=true;
                    ans.PB(j);
                    cur_keys[chest[j]]--;
                    need[chest[j]]--;
                    //cout<<j+1<<endl;
                    break;
                }
	        }
	        if(j==N)
                break;
            else
            {
                Rep(k,v[j].size())
                    cur_keys[v[j][k]]++;
            }
	    }
	    if(Size(ans)<N)
	    {
	        printf("Case #%d: IMPOSSIBLE\n",t);
	    }
	    else
	    {
	        printf("Case #%d: ",t);
	        rep(i,Size(ans)-1)
                printf("%d ",ans[i]+1);
            printf("%d\n",ans[Size(ans)-1]+1);
	    }
	}
	return 0;
}

