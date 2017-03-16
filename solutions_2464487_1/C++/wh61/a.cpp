#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

#define LL long long
#define EPS 1e-10
#define pi (acos(-1.0))

int main()
{
    freopen("Al.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, ca = 0;
    cin >> T;
    while (T--)
    {
        LL r, t;
        LL L = 0, R = 1000000000000000002;
    //  LL L = 0, R = 10;
        cin >> r >> t;
        double _t = t;
      //  _t /= pi;
        while (L < R)
        {
            LL mid = (L + R) / 2 + 1;
            double _mid = (double)mid;
            double _r = (double)r;
            double temp = (2 * _r - 3.0) * _mid + 4.0 * ((_mid + 1) * _mid / 2);
            if (temp <= _t + EPS) L = mid;
            else R =  mid - 1;
        }
        printf("Case #%d: %I64d\n", ++ca, L);
    }
    return 0;
}
