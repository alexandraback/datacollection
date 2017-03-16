#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("check.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int r,c,w;
        scanf("%d %d %d",&r,&c,&w);
        int ans=0;
        if(c%w)
        {
            ans = (r*(c/w))+w;
        }
        else ans = (r*(c/w))+w-1;
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}
