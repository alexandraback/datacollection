#include <iostream>
#include <cassert>
using namespace std;

static inline long long ipow(long long x, long long y) {
    long long ret = 1;
    while (y--)
        ret *= x;
    return ret;
}

static void process(int t) {
    cout << "Case #" << t << ":";
    int k, c, s;
    cin >> k >> c >> s;
    if (s < k) {
        cout << " IMPOSSIBLE" << endl;
        return ;
    }
    if (k == 1) {
        cout << " 1" << endl;
        return ;
    }
    for (int i = 1 ; i <= k ; ++i) {
        cout << ' ' << ( 1LL - ipow(k, c) ) / ( 1LL - k )  * ( i - 1LL )  + 1LL;
    }
    cout << endl;
}

int main()
{
    assert(ipow(2, 3) == 8);
    int t = 0;
    cin >> t;
    for (int i = 1 ; i <= t ; ++i)
        process(i);
}

