#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

int main()
{
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
    {
        ld c,f,x;
        cin>>c>>f>>x;
        ld tt=0;
        cout<<"Case #"<<i<<": ";

        ld b=2;
        while ( f * ( x - c ) >= c * b  )
        {
            tt += c / b;
            b += f;
        }
        tt += x / b;
        cout<<fixed<<setprecision(9)<<tt;

        cout<<"\n";
    }

}

