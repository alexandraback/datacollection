#include<bits/stdc++.h>
using namespace std;
int nCases,x,r,c,m;
int main (void)
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    cin>>nCases;
    for(int aCase = 1;aCase <= nCases;aCase++)
    {
        cin>>x>>r>>c;
        cout<<"Case #"<<aCase<<": ";
        if(x>=7 || (r*c)%x)
        {
            cout<<"RICHARD\n";
            continue;
        }
        if(x== 1|| x==2 || (x==3 && min(r,c)==2) || (x==5 && min(r,c)==3 && max(r,c)>=10))
            cout<<"GABRIEL\n";
        else
        {
            m=(x+1)/2+1;
            if(m<=min(r,c))
                cout<<"GABRIEL\n";
            else
                cout<<"RICHARD\n";
        }
    }
    return 0;
}
