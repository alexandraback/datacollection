#include <iostream>
#include <stdio.h>
using namespace std;
int gao(long long now)
{
    int ret=0;
    while(now>0)
    {
        ret|=(1<<(now%10));
        now/=10;
    }
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;

    for(int ti=1;ti<=t;ti++)
    //for(int n=1;n<=1e6;n++)
    {
        int n;
        cin>>n;

        cout<<"Case #"<<ti<<": ";
        if(n==0)
        {
            cout<<"INSOMNIA"<<endl;
        }
        else
        {
            int state = 0;
            state|=gao(n);
            int ans=1;
            long long now = n;
            while(state<((1<<10)-1))
            {
                now+=n;
                state|=gao(now);
                ans++;
            }
            cout<<1ll*n*ans<<endl;
        }
    }
    return 0;
}
