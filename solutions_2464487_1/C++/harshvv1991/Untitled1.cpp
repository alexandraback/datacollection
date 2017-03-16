#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned long long int r, t, k, temp;
    int T;
    cin>>T;

    for(int cas=1; cas<=T; cas++)
    {
        cin>>r>>t;

        k=(1+2*r)-2;

        double discriminant = (pow(k,2) + 8*t);
        temp = (unsigned long long int)floor((sqrt(discriminant)-k)/4);

        if((2*pow(temp,2))+(temp*k) <= t)
            cout<<"Case #"<<cas<<": "<<temp<<endl;
        else
            cout<<"Case #"<<cas<<": "<<temp-1<<endl;
    }
    return 0;
}
