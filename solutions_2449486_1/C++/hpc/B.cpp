#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 105
using namespace std;
int N,M;
int map[MAXN][MAXN],a[MAXN][MAXN];
bool process()
{
    int h=0,MAXH,aH;
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            h=max(h,map[i][j]);
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            a[i][j]=h;
    while(1)
    {
        bool tmp=0;
        for(int i=0;i<N;++i)
        {
            MAXH=aH=0;
            for(int j=0;j<M;++j)
               aH=max(aH,a[i][j]);
            for(int j=0;j<M;++j)
                if(map[i][j]<=aH)
                    MAXH=max(MAXH,map[i][j]);
            if(aH==MAXH)
                continue;
            tmp=1;
            for(int j=0;j<M;++j)
                a[i][j]=MAXH;
        }
        for(int i=0;i<M;++i)
        {
            MAXH=aH=0;
            for(int j=0;j<N;++j)
               aH=max(aH,a[j][i]);
            for(int j=0;j<N;++j)
                if(map[j][i]<=aH)
                    MAXH=max(MAXH,map[j][i]);
            if(aH==MAXH)
                continue;
            tmp=1;
            for(int j=0;j<N;++j)
                a[j][i]=MAXH;
        }
        if(tmp==0) break;
    }
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            if(map[i][j]!=a[i][j])
                return false;
    return true;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t,T;
    scanf("%d",&t);
    T=t;
    while(t--)
    {
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;++i)
            for(int j=0;j<M;++j)
                scanf("%d",&map[i][j]);
        printf("Case #%d: ",T-t);
        bool b=process();
        if(b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
