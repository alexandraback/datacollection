#include <bits/stdc++.h>

using namespace std;

//0 1 2 3  4  5  6  7

//1 i j k -1 -i -j -k

int g[10][10]={{0,1,2,3,4,5,6,7},
           {1,4,3,6,5,0,7,2},
           {2,7,4,1,6,3,0,5},
           {3,2,5,4,7,6,1,0},
           {4,5,6,7,0,1,2,3},
           {5,0,7,2,1,4,3,6},
           {6,3,0,5,2,7,4,1},
           {7,6,1,0,3,2,5,4}};

int change(char x)
{
    if(x=='1')
        return 0;
    if(x=='i')
        return 1;
    if(x=='j')
        return 2;
    return 3;
}

char str[10010];

int pre[10010];

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        int n;
        long long l;
        scanf("%d%lld",&n,&l);
        scanf("%s",str+1);
        pre[1]=change(str[1]);
        for(int i=2;i<=n;i++)
            pre[i]=g[pre[i-1]][change(str[i])];
        int x=pre[n];
        int now=0,sx=0,sy=0,tx=0,ty=0;
        for(int i=1;i<=5;i++) {
            for(int j=1;j<=n;j++) {
                now=g[now][change(str[j])];
                if(now==1) {
                    sx=i;
                    sy=j;
                    break;
                }
            }
            if(sx)
                break;
        }
        now=0;
        for(int i=1;i<=5;i++) {
            for(int j=n;j>=1;j--) {
                now=g[change(str[j])][now];
                if(now==3) {
                    tx=i;
                    ty=j;
                    break;
                }
            }
            if(tx)
                break;
        }
        if(sx==0||tx==0) {
            printf("Case #%d: NO\n",++cas);
            continue;
        }
        if(sx+tx>l+1) {
            printf("Case #%d: NO\n",++cas);
            continue;
        }
        if(sx+tx==l+1) {
            if(sy>=ty-1)
                printf("Case #%d: NO\n",++cas);
            else {
                now=0;
                for(int i=sy+1;i<ty;i++)
                    now=g[now][change(str[i])];
                if(now==2)
                    printf("Case #%d: YES\n",++cas);
                else
                    printf("Case #%d: NO\n",++cas);
            }
        }
        else {
            long long fuck=l-sx-tx;
            fuck%=4;
            int ans=0;
            for(int i=1;i<=fuck;i++)
                ans=g[ans][x];
            now=0;
            for(int i=sy+1;i<=n;i++)
                now=g[now][change(str[i])];
            now=g[now][ans];
            for(int i=1;i<ty;i++)
                now=g[now][change(str[i])];
            if(now==2)
                printf("Case #%d: YES\n",++cas);
            else
                printf("Case #%d: NO\n",++cas);
        }
    }
    return 0;
}
