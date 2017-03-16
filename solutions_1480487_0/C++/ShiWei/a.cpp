#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;
#define inf 0x7fffffff
#define min(a,b) a<b?a:b
int p[210];
double q[210],t[210];
bool s[210];
int main ()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("b.out","w",stdout);
    int nCase,n,sum,Sum,num;
    double flag;
    scanf("%d",&nCase);
    for(int i=1; i<=nCase; ++i)
    {
        scanf("%d",&n);
        sum=0;
        for(int j=1; j<=n; ++j)
        {
            s[j]=1;
            scanf("%d",&p[j]);
            sum+=p[j];
        }
        Sum=sum;
        num=n;
        printf("Case #%d:",i);
        for(int j=1; j<=n; ++j)
            t[j]=double(p[j])/sum;
        flag=2/double(n);
        for(int j=1; j<=n; ++j)
            if(flag<=t[j])
            {
                q[j]=0;
                s[j]=0;
                --num;
                Sum-=p[j];
            }
        flag=double(sum+Sum)/num;
        for(int j=1;j<=n;++j)
            if(s[j])
            {
                q[j]=(flag-p[j])/sum;
            }
        for(int j=1; j<=n; ++j)
            printf(" %lf",q[j]*100);
        printf("\n");
    }
    return 0;
}