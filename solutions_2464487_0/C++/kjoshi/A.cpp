#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main()
{
    int i,j,k,l;
    int T,t;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("output-A.txt","w",stdout);

    cin>>T;
    for(t=1;t<=T;++t)
    {
        long long r,x,a;
        cin>>r>>x;
        long double R=r;
        long double X=x;
        long double D=4*R*R+1-4*R+8*X;
        //cout<<D<<endl;
        D=sqrt(D);
        double N=-2*R+1+D;
        N=N/4.0;
        a=N;
        a++;
        while((2*a*a+(2*r-1)*a)>x)
            a--;
       // N=t/N;
        //cout<<a<<endl;
        cout<<"Case #"<<t<<": "<<a<<endl;
        //printf("Case #%d: %d\n",t,a);
    }


    return 0;
}
