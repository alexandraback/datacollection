#include<cstdio>
using namespace std;
int p[205];
double q[205],t[205];
bool s[205];
int main ()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("sun.out","w",stdout);
    int nn,n,sum,sumx,num;
    double key;
    scanf("%d",&nn);
    for(int i=1; i<=nn; ++i)
    {
        scanf("%d",&n);
        sum=0;
        for(int j=1; j<=n; ++j)
        {
            s[j]=1;
            scanf("%d",&p[j]);
            sum+=p[j];
        }
        sumx=sum;
        num=n;
        printf("Case #%d:",i);
        for(int j=1; j<=n; ++j)
            t[j]=double(p[j])/sum;
        key=2/double(n);
        for(int j=1; j<=n; ++j)
            if(key<=t[j])
            {
                q[j]=0;
                s[j]=0;
                --num;
                sumx-=p[j];
            }
        key=double(sum+sumx)/num;
        for(int j=1;j<=n;++j)
            if(s[j])
            {
                q[j]=(key-p[j])/sum;
            }
        for(int j=1; j<=n; ++j)
            printf(" %.6lf",q[j]*100);
        printf("\n");
    }
    return 0;
}
