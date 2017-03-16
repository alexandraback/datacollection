#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin >> T;
    for(int k = 1; k<=T; k++)
    {
        ll r,t;
        cin >> r >> t;
        double dn = 0.5*(sqrt((double(r)-0.5)*(double(r)-0.5)+2.0*double(t))-(double(r)-0.5));
        ll n = ll(dn);
        while(n*(2*r+2*n-1)>t) n--;
        while(n*(2*r+2*n-1)<=t) n++;
        cout << "Case #" << k << ": " << n-1 << endl;
    }
}
