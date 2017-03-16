#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned long long int r, t, req;
    int T;
    cin>>T;
    double a,b;
    int count;
    for(int cas=1; cas<=T; cas++)
    {
        cin>>r>>t;
        count = 0;

        while(true)
        {
            req=(1+2*r);

            if(req > t)
                break;

            t -= req;
            r += 2;
            count++;
        }

        cout<<"Case #"<<cas<<": "<<count<<endl;
    }
    return 0;
}
