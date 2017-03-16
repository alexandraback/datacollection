#include <iostream>
#include <cstdio>

using namespace std;

typedef long long lld;


lld t;
lld r;

bool check(lld n)
{
//    if (2*n*n+(2*r-1)*n<=t) return true;
    if (t/(2*n+2*r-1)>=n) return true;
    return false;
}

lld solve()
{
    lld l = 1;
    lld r = 2000000000;
    while (l != r) {
        lld m = (l + r + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m-1;
        }
    }
    return l;
}

int main()
{
    int tc;
    cin >> tc;
    for (int c=1; c<=tc; ++c) {
        cin >> r >> t;
        cout << "Case #" << c << ": " << solve() << endl;
    }
    return 0;
}

