#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=110;
double p[maxn],p1[maxn];

int main()
{
   // freopen("A-small-attempt0.in","r",stdin);
   // freopen("A-small-attempt0.out","w",stdout);
    int ca,cas=1,A,B;
    cin>>ca;
    while(ca--)
    {
        cin>>A>>B;
        for(int i=A-1;i>=0;i--)
          cin>>p[i];
        for(int i=0;i<(1<<A);i++)
        {
            p1[i]=1;
            for(int j=0;j<A;j++)
             if(i&(1<<j)) p1[i]*=(1-p[j]);
             else p1[i]*=p[j];
           //cout<<p1[i]<<" "<<i<<endl;
        }
        double ans=(B-A+1)*p1[0]+(1-p1[0])*(2*B-A+2);
        ans=min(ans,B+2.0);
        //cout<<ans<<endl;
        for(int j=1;j<=A;j++)
        {
             double tmp=0;
             for(int i=0;i<(1<<A);i++)
             {
                 if((i-(1<<j)+1)<=0) tmp+=(j+j+B-A+1)*p1[i];
                 else tmp+=(j+j+B-A+1+B+1)*p1[i];
             }
           // cout<<tmp<<endl;
            ans=min(ans,tmp);
        }
        printf("Case #%d: %.6lf\n",cas++,ans);
    }
    return 0;
}
