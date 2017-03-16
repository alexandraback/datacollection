#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int ct[25000];
int n;
int wk(int t)
{
    scanf("%d",&n);
    for(int i=0;i<=3000;i++)
        ct[i]=0;
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            int b;
            cin>>b;
            ct[b]++;
        }
    }
    cout<<"Case #"<<t<<": ";
    for(int i=0;i<=2500;i++)
    {
        if(ct[i]%2==1)
            cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    string s;
    int T;
    freopen("B-s.in","r",stdin);
    freopen("B.out","w",stdout);
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        wk(tt);
    }
}
