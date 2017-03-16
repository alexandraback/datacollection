#include <bits/stdc++.h>
using namespace std;
const int MAXN=51;
int b;
bool haveEdge[MAXN][MAXN];
int f(int x)
{
    return x+2;
}
void output()
{
    puts("POSSIBLE");
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++) printf("%d",haveEdge[i][j]?1:0);
        printf("\n");
    }
}
void main2()
{
        long long M;
        scanf("%d%lld",&b,&M);
        for(int i=1;i<=b;i++)
            for(int j=1;j<=b;j++) haveEdge[i][j]=false;
        long long maxAns=1ll<<(b-2);
        //if(M>1ll*maxAns) puts("IMPOSSIBLE");
        haveEdge[1][b]=true;
        M--;
        for(int vadd=2;M>0&&vadd<b;vadd++)
        {
            haveEdge[1][vadd]=true;
            long long gets=(1ll<<vadd-2);
            if(M<=gets)
            {
                haveEdge[vadd][b]=true;
                M--;
                for(int bit=0;bit<60;bit++)
                {
                    if(M&(1ll<<bit)) haveEdge[vadd][bit+2]=true;
                }
                output();
                return;
            }
            else
            {
                for(int i=2;i<vadd;i++) haveEdge[vadd][i]=true;
                haveEdge[vadd][b]=true;
                M-=gets;
            }
        }
        if(M>0) puts("IMPOSSIBLE"); else output();
        return;
}
#define FILE true
int main()
{
    if(FILE){
    freopen("B.txt","r",stdin);
    freopen("Bout.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        main2();
    }
}
