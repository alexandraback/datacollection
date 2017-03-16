#include <cstdio>
#include <algorithm>
using namespace std;
void rec(int te)
{
    int t,r,e,n,va;
    int dy[20][10]={0};
    scanf("%d%d%d",&e,&r,&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&va);
        for(int k=e;k>=0;k--)
        {
            for(int us=k;us>=0;us--)
            {
                dy[j+1][min(k-us+r,e)]=max(dy[j+1][min(k-us+r,e)],dy[j][k]+us*va);
            }
        }
    }
    int out=0;
    for(int j=0;j<=e;j++)
        out=max(dy[n][j],out);
    printf("Case #%d: %d\n",te,out);
}
int main()
{

    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        rec(i+1);
    }
}
