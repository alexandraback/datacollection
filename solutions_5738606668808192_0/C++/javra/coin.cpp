#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef long long int llint;

// This program uses the GNU multiple precision library,
// available at gmplib.org
#include <gmp.h>
#include <gmpxx.h>
using Z = mpz_class;

// compile with -lgmp -lgmpxx

#define debug(s) cout << "*** " << (s) << " ***\n"

void solve()
{
    int N, J;
    cin >> N >> J;
    char s[N+1] = {0};
    s[0] = '1';
    s[N-1] = '1';
    for(int i = 1; i < N-1; i++)
        s[i] = '0';

    int found = 0;
    while(found < J)
    {
        long divisors[11] = {0};
        for(int base = 2; base <= 10; base++)
        {
            Z n(s, base);
            if(mpz_probab_prime_p(n.get_mpz_t(), 15) != 0)
                goto nextN;

            Z div = 3;
            while(true)
            {
                if(n % div == 0)
                {
                    divisors[base] = div.get_si();
                    break;
                }
                div += 1;
                if(div > 100000)
                    goto nextN;
            }
        }

        found += 1;
        cout << s << " ";
        for(int base = 2; base <= 10; base++)
        {
            cout << divisors[base];
            if(base < 10)
                cout << " ";
        }
        cout << "\n";

    nextN:
        for(int i = N-2; i >= 1; i--)
        {
            if(s[i] == '0')
            {
                s[i] = '1';
                break;
            }
            s[i] = '0';
        }
    }

}

int main()
{
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cout << endl;
        solve();
    }
    return 0;
}

