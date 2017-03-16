#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T;
double r,t;

const double pi=acos(-1);

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    cin>>T;
    int ca=0;
    while (T--)
    {
        cin>>r>>t;
        t=t;
        double a=2,b=2*r-1,c=-t;
        double ans=(-b+sqrt(b*b-4*a*c))/(2*a);
        ans+=1e-8;
        printf("Case #%d: ",++ca);
        cout<<(int)ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
