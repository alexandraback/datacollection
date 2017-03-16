#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

#define double long double

const int N=2000+40;
const int A=250+5;
double t[N],x[N],a[A];

double calc(int n,double D,int ai)
{int i;
    double mmax=0;
    for(i=0;i<n;++i)
        mmax=max(mmax,t[i]-sqrt(2*x[i]/ai));
    return mmax+sqrt(2*D/ai);
}

int main()
{
    int T;
    cin>>T;
    for(int tt=1;tt<=T;++tt)
    {int i,j;
        double D;
        cin>>D;
        int n,an;
        cin>>n>>an;
        for(i=0;i<n;++i)
            cin>>t[i]>>x[i];
        for(i=0;i<an;++i)
            cin>>a[i];
        if(x[n-1]>D)
        {
            t[n-1]=(D-x[n-2])/
                ((x[n-1]-x[n-2])/(t[n-1]-t[n-2]))
                    +t[n-2];
            x[n-1]=D;
        }

        cout<<"Case #"<<tt<<":\n";
        for(i=0;i<an;++i)
            cout<<fixed<<setprecision(7)
                <<calc(n,D,a[i])<<endl;
        //cout<<endl;
    }
    return 0;
}
