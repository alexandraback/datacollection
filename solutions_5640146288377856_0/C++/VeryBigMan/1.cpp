#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int ans=0;
        int r,c,w;
        cin>>r>>c>>w;
        ans=c/w+w-1;
        if(c%w!=0)
        {
            ans+=1;
        }
        cout<<"Case #"<<tt<<": "<<ans*r<<endl;
    }
    return 0;
}
