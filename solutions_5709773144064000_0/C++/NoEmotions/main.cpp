#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int ti=0;ti<t;++ti)
    {
        long double in=2.0,c,f,x,time=0.0;
        cin>>c>>f>>x;

        long double mintime=x/in;

        while(time+c/in+x/(in+f)<mintime)
        {
            time+=c/in;
            in+=f;
            mintime=time+x/in;
        }
        cout<<"Case #"<<ti+1<<": "<<fixed<<setprecision(7)<<mintime<<endl;
    }
    return 0;
}
