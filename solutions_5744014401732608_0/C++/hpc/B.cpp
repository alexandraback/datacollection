//GCJ 2016 round1C B
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 52
using namespace std;
int B;
long long int M;
int c[MAXN][MAXN];
int y[MAXN];
void solve()
{
    long long int s=1;
    int x;
    if(B==2)
    {
        if(M==1)
        {
            printf("POSSIBLE\n");
            printf("01\n");
            printf("00\n");
        }
        else printf("IMPOSSIBLE\n");
        return;
    }
    for(x=2;x<=B-1;++x)
    {
        s*=2;
        if(s==M)
        {
            printf("POSSIBLE\n");
            for(int i=1;i<=B;++i)
            {
                for(int j=1;j<=B;++j)
                {
                    if(i<j && j<=x) printf("1");
                    else if(j==B&&i<=x) printf("1");
                    else printf("0");
                    if(j==B) printf("\n");
                }
            }
            return;
        }
        if(s>M)
        {
            printf("POSSIBLE\n");
            long long r = M-s/2;
            int k=0;
            bool t=0;
            while(r>0)
            {
                y[k++]=r%2;
                if(r%2==1) t=1;
                r/=2;
            }
            x--;
            for(int i=1;i<=B;++i)
            {
                for(int j=1;j<=B;++j)
                {
                    if(i<j && j<=x) printf("1");
                    else if(j==B&&i<=x) printf("1");
                    else if(i>=2&&y[i-2]==1&&j==x+1) printf("1");
                    else if(i==x+1&&j==B&&t==1) printf("1");
                    else printf("0");
                    if(j==B) printf("\n");
                }
            }
            return;
        }
    }
    printf("IMPOSSIBLE\n");
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int Case;
    scanf("%d",&Case);
    for(int t=1;t<=Case;++t)
    {
        memset(y,0,sizeof(y));
        scanf("%d%lld",&B,&M);
        printf("Case #%d: ",t);
        solve();


    }
    return 0;
}
