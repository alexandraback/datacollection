#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#define inf 1000000000
#define ll long long int

using namespace std;

ll r,t;

ll cal(double a,double b,double c)
{
    double d=-b;

    d+=sqrt(b*b-4*a*c);
    d/=2*a;

    //printf("%.10lf\n",d);

    return (ll) d;
}

int main()
{
    int T,cas;
    ll a,b,n;

    freopen("A-small-attempt0(1).in","r",stdin);
    freopen("a-small.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        cin>>r>>t;

        printf("Case #%d: ",cas);

        n=cal(2,2.0*r-1,-t);

        b=(2*n*n + n*(2*r-1) );

        if(b<=t) cout<<n<<endl;
        else cout<<n-1<<endl;




    }

    return 0;
}
