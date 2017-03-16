#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

const int full_mask = (1<<10) - 1;

void fill_digits(lng num, int& mask)
{
    while (num)
    {
        mask |= (1<<(num%10));
        num /= 10;
    }
}

lng solve(int step)
{
    lng n = step;

    if (n == 0)
    {
        return -1;
    }

    int mask = 0;
    fill_digits(n, mask);

    while (mask != full_mask)
    {
        n += step;
        fill_digits(n, mask);
    }

    return n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        int n;
        cin >> n;

        auto res = solve(n);

        std::cout << "Case #" << tc + 1 << ": ";

        if (res < 0)
        {
            std::cout << "INSOMNIA";
        }
        else
        {
            std::cout << res;
        }
        
        std::cout << endl;
    }
    
    return 0;
}
