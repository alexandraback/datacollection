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
int K,N,cur_keys[205],chest[205];
bool vis[1<<20];
vector<int>v[205],ans;
bool fans(int mask)
{
    if(vis[mask])
        return false;
    if(mask==0)
        return true;
    vis[mask]=true;
    int nmsk=mask,i,j;
    rep(i,N)
    {
        if(!cur_keys[chest[i]]||((1<<i)&mask)==0)
            continue;
        cur_keys[chest[i]]--;
        nmsk=mask^(1<<i);
        rep(j,Size(v[i]))
        {
            cur_keys[v[i][j]]++;
        }
        if(fans(nmsk))
        {
            ans.PB(i);
            return true;
        }
        rep(j,Size(v[i]))
            cur_keys[v[i][j]]--;
        cur_keys[chest[i]]++;
    }
    return false;
}
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("Dout.txt","w",stdout);
	int t,T,val,sz,i,j;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    scanf("%d%d",&K,&N);
	    memset(cur_keys,0,sizeof(cur_keys));
	    rep(i,1<<N)
	    {
	        vis[i]=false;
	    }
	    rep(i,K)
	    {
	        scanf("%d",&val);
	        cur_keys[val]++;
	    }
	    rep(i,N)
	    {
	        scanf("%d",&chest[i]);
	        scanf("%d",&sz);
	        v[i].resize(sz);
	        rep(j,sz)
                scanf("%d",&v[i][j]);
	    }
	    ans.clear();
	    if(!fans((1<<N)-1))
            printf("Case #%d: IMPOSSIBLE\n",t);
        else
        {
            printf("Case #%d: ",t);
            for(i=Size(ans)-1;i;i--)
                printf("%d ",ans[i]+1);
            printf("%d\n",ans[0]+1);
        }
	}
	return 0;
}

