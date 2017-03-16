#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=110000;
double p[maxn];

int main()
{
   // freopen("A-large.in","r",stdin);
   // freopen("A-large.out","w",stdout);
    int ca,cas=1,A,B;
    cin>>ca;
    while(ca--)
    {
        cin>>A>>B;
        double p1=1;
        for(int i=A-1;i>=0;i--)
          cin>>p[i],p1*=p[i];
        double ans=(B-A+1)*p1+(1-p1)*(2*B-A+2);
        //cout<<ans<<endl;
        ans=min(ans,B+2.0);
        for(int i=0;i<A;i++)
        {
            pp=1;
            for(int j=A-1;j>i;j--) pp*=p[j];
            double tmp=pp*(B-A+2*i+3)+(1-pp)*(B-A+2*i+4+B);
           // cout<<pp<<" "<<tmp<<endl;
            ans=min(ans,tmp);
        }
        printf("Case #%d: %.6lf\n",cas++,ans);
    }
    return 0;
}
