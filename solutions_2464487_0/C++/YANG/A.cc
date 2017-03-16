#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <gmpxx.h>

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cout.precision(8);

    cin >> T;
    for (int i = 1; i <= T; i++) {
        long r, t;
        cin >> r >> t;

        mpz_class gr(r);
        mpz_class gt(t);
        mpz_class n = (sqrt(8*gt+(2*gr-1)*(2*gr-1))-2*gr+1)/4;

        cout << "Case #" << i << ": " << n.get_str() << endl;
    }
}
