#include <iostream>
#include <fstream>

using namespace std;
ifstream in("A-small-attempt0.in");
ofstream out("Bullseye.out");
int T;
typedef long long ll;
const double PI = 3.14159265359;

ll work(ll r, double t)
{
    ll k = 0,area;
    while (t > 0)
    {
        area = 2*r+1;
        t -= area;
        if (t >= 0) ++k;
        r += 2;
    }
    return k;
}

int main()
{
    in >> T;
    for (int i = 1; i <= T; ++i)
    {
        ll r;
        double t;
        in >> r >> t;
        out << "Case #" << i << ": " << work(r,t) << '\n';
    }
    return 0;
}
