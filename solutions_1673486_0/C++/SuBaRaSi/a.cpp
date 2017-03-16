#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

long double ps[100009];

int main()
{
    ps[0] = 1;
    int T;
    cin >> T;
    for(int tn = 1; tn <= T; tn++)
    {
        cout << "Case #" << tn << ':';

        int A, B;
        cin >> A >> B;

        for(int i = 1; i <= A; i++)
        {
            cin >> ps[i];
            ps[i] *= ps[i - 1];
        }


        double ans = B + 2;
        
        for(int i = 1; i <= A; i++)
        {
            double t = ps[i] * (A - i + B - i + 1) + (1 - ps[i]) * (A - i + B - i + 1 + B + 1);
            ans = min(ans, t);
        }

        cout.precision(10);
        cout << " " << fixed << ans << '\n';


        
    }

    return 0;
}
