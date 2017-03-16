#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("output.txt","w",stdout);
    long int i,t,r,c,w,res;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        res=0;
        cin >> r >> c >> w;
        res=c/w*r;
        res+=w-1;
        if(c%w!=0)
            res++;
        cout<<"Case #"<<i<<": "<<res<<"\n";
    }
    return 0;
}
