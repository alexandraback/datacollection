#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int cs=0;
    while(t--)
    {
        cs++;
        int a,b;
        cin>>a>>b;
        double p[a],pro[a];
        for(int x=0;x<a;x++)
        {
            cin>>p[x];
            if(x==0)pro[x]=p[x];
            else
            pro[x]=pro[x-1]*p[x];
        }
        double ans=100000000.0;
        //press enter right away
        ans=min(ans,(double)1+b+1);
        //cout<<ans<<"\n";
        //keep on typing
        ans=min(ans,pro[a-1]*(b-a+1)+(1-pro[a-1])*(b-a+1+b+1));
        //cout<<ans<<"\n";

        //back space all
        ans=min(ans,(double)a+b+1);
        //cout<<ans<<"\n";
        for(int x=1;x<a;x++)
        {
            //press backspace x times
            ans=min(ans,pro[a-x-1]*(x+(b-a+x)+1)+(1-pro[a-x-1])*(x+(b-a+x)+1+b+1));
        }
        printf("Case #%d: %.6f\n",cs,ans);
        //cout<<"Case #"<<cs<<": "<<ans<<"\n";
    }
    return 0;
}
