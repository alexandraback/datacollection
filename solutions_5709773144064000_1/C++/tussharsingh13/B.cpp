#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)

int main()
{
        freopen ("B-large.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
               double c,f,x;
               double rate=2.0;
               cin>>c>>f>>x;
               double ans=1000000000.0;
               double tim=0.0;
               while(1)
               {
                        double temp;
                        temp=x/rate;
                        if(tim+temp>ans)
                        break;
                        ans=tim+temp;
                        tim+=c/rate;
                        rate+=f;
               }
               //cout<<"Case #"<<test<<": "<<ans<<"\n";
               printf("Case #%d: %.7lf\n",test,ans);
        }
        return 0;
}
