#include <iostream>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;
typedef long long LL;


int main() {
    int T;
    LL R, t;
    cin>>T;
    for( int tc = 1; tc <= T; ++tc ) {
         cin>>R>>t;
         LL l = 1, r = (LL)sqrt(t*1.0) + 10;
         while( l <= r ) {
                //cout<<l<<" "<<r<<endl;
                LL mid = (l+r)>>1;
                if( (R*2+2*mid-1) <= 1.0*t/mid + eps) l = mid + 1;
                else r = mid - 1; 
         }
         while( (R*2+2*r-1) <= 1.0*t/r + eps) ++r;
         cout<<"Case #"<<tc<<": "<<r-1<<endl;
    }
    return 0;
}
