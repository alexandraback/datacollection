#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int h[110][110];
int n,m;
int mh[110],ml[110];
int cas=0;
int main()
{
   freopen("input.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int T;
   scanf("%d",&T);
   while(T--)
   {
        scanf("%d%d",&n,&m);
        memset(mh,-1,sizeof(mh));
        memset(ml,-1,sizeof(ml));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&h[i][j]);
                mh[i]=max(mh[i],h[i][j]);
                ml[j]=max(ml[j],h[i][j]);
            }
        bool flag=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(mh[i]!=h[i][j] && ml[j]!=h[i][j])
                {
                    flag=false;
                    goto FUCK;
                }
        FUCK:;
        printf("Case #%d: ",++cas);
        if(flag)
            puts("YES");
        else
            puts("NO");
   }
   return 0;
}
