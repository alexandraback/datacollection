#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
long double r,t,t1,tep;
int cas,casx;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>cas;
    for (casx=1; casx<=cas; casx++)
    {
        cin>>r>>t;
        t1=sqrt((2*r-1)*(2*r-1)+8*t);
        tep=((-1)*(2*r-1)+t1)/4.0;
        long long ans=tep;
        cout<<"Case #"<<casx<<": "<<ans<<endl;
    }

    return 0;
}
