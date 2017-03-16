#include<iostream>
#include<algorithm>
#include<iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    double c,f,x,mx,tmp;
    cin>>t;
 //   freopen("out", "w", stdout);
    for(int i=1;i<=t;i++)
    {
        cin>>c>>f>>x;
        mx=x/2;
        tmp=0;
        for(int j=0;;j++)
        {
            tmp+=c/(2+j*f);
            if(tmp>=mx) break;
            mx=min(mx,x/(2+(j+1)*f)+tmp);
        }
        cout<<"Case #"<<i<<": "<<fixed<<setprecision(7)<<mx<<endl;
    }
    return 0;
}
