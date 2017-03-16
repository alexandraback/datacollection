#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

double c[2500][2500];

int main()
{
    freopen("in2.txt","r",stdin);
    freopen("out.txt","w",stdout);
    memset(c,0,sizeof(c));
    for(int i=0;i<2500;i++)
    {
        c[i][0]=c[i][i]=1.0;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    int t,n,x,y,r;
    double a,b;
    long long s;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d",&n,&x,&y);
        r=abs(x)+abs(y);
        r=r/2+1;
        s=0;
        for(int i=1;i<r;i++)
        {
            s+=4*i-3;
            if(s>n)break;
        }
        //printf("%d:%I64d %I64d(%d)||",r,s,s+4*r-3,s+4*r-3<=n);
        if(s>n)
        {
            printf("Case #%d: %e\n",cas,0.0);
            continue;
        }
        if(s+4*r-3<=n)
        {
            printf("Case #%d: %e\n",cas,1.0);
            continue;
        }
        n-=s;
        s=2*r-1;
        a=0.0,b=0.0;
        for(int i=0;i<=n;i++)
            if(i<s&&n-i<s)
            {
                b+=c[n][i];
                if(i>y)a+=c[n][i];
            }
        //printf("%.10f %.10f\n",a,b);
        printf("Case #%d: %e\n",cas,a/b);
    }
    return 0;
}
