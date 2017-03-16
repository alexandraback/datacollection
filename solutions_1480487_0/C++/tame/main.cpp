#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
double s[1000];
int n;
double an[1000],sum,sq[1000];

int pan(int v,double p)
{
    p/=100000000;
    double st=sum*(1-p),t=s[v]+sum*p;
    for(int i=1;st>0&&i<=n;i++)
        if(i!=v&&s[i]<t)
            st-=t-s[i];
    if(st<=0)
        return 1;
    return 0;
}


int main()
{
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int g=1;g<=cas;g++)
    {
        sum=0;
        int i,j,k;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&s[i]);
            sum+=s[i];
        }
        printf("Case #%d:",g);
        for(i=1;i<=n;i++)
        {
             int l=0,r=100000000;
             int ans=100000000;
             while(l<=r)
        {
            int mid=(l+r)/2;
            if(pan(i,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        an[i]=ans;
        an[i]/=1000000;
        printf(" %.6f",an[i]);
        }

       
        printf("\n");
      
    }
    return 0;
}