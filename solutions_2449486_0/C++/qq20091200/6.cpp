#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAXN 101

int h[MAXN][MAXN];

int n,m;

int r[MAXN];
int c[MAXN];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int ct;
    scanf("%d",&ct);
    for(int ncase=1;ncase<=ct;ncase++)
    {
        int i,j;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&h[i][j]);
        bool ans=true;
        for(i=0;i<n;i++)
        {
            r[i]=0;
            for(j=0;j<m;j++)
            {
                if(r[i]<h[i][j])
                    r[i]=h[i][j];
            }
        }
        for(i=0;i<m;i++)
        {
            c[i]=0;
            for(j=0;j<n;j++)
            {
                if(c[i]<h[j][i])
                    c[i]=h[j][i];
            }
        }
        for(i=0;i<n && ans;i++)
        for(j=0;j<m;j++)
        {
            if(h[i][j]<r[i] && h[i][j]<c[j])
            {
                ans=false;
                break;
            }
        }
        printf("Case #%d: ",ncase);
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
