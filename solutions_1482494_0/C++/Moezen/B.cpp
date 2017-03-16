#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = 1<<30;
const double eps = 1e-8;

int ans,st,n,req[3000][3];
bool vis[3000][3];
int main()
{
//    freopen("B-small-attempt1.in","r",stdin);
 //   freopen("Bout.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        bool flag;
        st=0;
        ans=0;
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&req[i][0],&req[i][1]);
        while(st<n*2)
        {
            flag=false;
            for(int i=0;i<n;i++)
                if(!vis[i][1]&&st>=req[i][1])
                {
                    ans++;
                    flag=true;
                    vis[i][1]=true;
                    if(vis[i][0]) st+=1;
                    else
                    {
                        vis[i][0]=true;
                        st+=2;
                    }
                    break;
                }
            if(!flag)
            {
                int x=-1;
                for(int i=0;i<n;i++)
                    if(!vis[i][0]&&st>=req[i][0])
                        if(x==-1||req[x][1]<req[i][1])
                            x=i;
                if(x!=-1)
                {
                    ans++;
                    flag=true;
                    vis[x][0]=true;
                    st+=1;
                }
            }
            if(!flag) break;
        }
        if(st==n*2) printf("Case #%d: %d\n",cas,ans);
        else printf("Case #%d: Too Bad\n",cas);
    }
	return 0;
}
