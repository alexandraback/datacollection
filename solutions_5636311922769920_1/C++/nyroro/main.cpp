#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin>>t;

    for(int ti=1;ti<=t;ti++)
    {
        int k,c,s;
        cin>>k>>c>>s;

        cout<<"Case #"<<ti<<":";
        if(s==k)
        {
            for(int i=1;i<=k;i++)
            {
                cout<<" "<<i;
            }
            cout<<endl;
            continue;
        }
        else if(c*s<k)
        {
            cout<<" IMPOSSIBLE"<<endl;
            continue;
        }
        else
        {
            if(c>k)c=k;
            int j=0;

            long long kc=1;

            for(int i=0;i<c;i++)
            {
                kc*=k;
            }
            for(int i=0;i<(int)ceil(1.0*k/c);i++)
            {
                long long ret=1;

                for(int x=0;x<c;x++)
                {
                    long long tmp=1;
                    for(int y=c-x-1;y>0;y--)tmp*=k;
                    ret+=tmp*(j+x);
                }
                j+=c;
                cout<<" "<<min(ret,kc);
            }
            cout<<endl;
        }
    }
    return 0;
}
