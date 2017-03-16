#include <iostream>
#include <cmath>
using namespace std;

long long rq, tq;
long double r, t;


void real_main()
{
    cin>>rq>>tq;
    r = rq; t = tq;
    double n = (sqrt((2*r-1)*(2*r-1)+8*t)-2*r+1)/4;
    cout<<(long long)floor(n)<<endl;
}

int main()
{
    int T; cin>>T;
    for (int i=0;i<T;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        real_main();
    }
    return 0;
}
