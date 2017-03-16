#include<bits/stdc++.h>
using namespace std;
int ret[1100],n,a[1100],nCases,r,c;
int main (void)
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    cin>>nCases;
    for(int aCase=1;aCase<=nCases;aCase++)
    {
        cin>>n;
        r=0;
        c=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            r+=a[i];
        }
        for(int i=1;i*i<=1000;i++)
        {
            c=0;
            for(int j=0;j<n;j++)
                c+=(a[j]+i-1)/i-1;
            r=min(r,c+i);
        }
        cout<<"Case #"<<aCase<<": "<<r<<endl;
    }
    return 0;
}
