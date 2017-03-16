#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>

using namespace std;

long long rever(long long x) {
    long long t1, t2;
    t1 = x;
    t2 = 0;
    while (t1 != 0) {
        t2 = t2 * 10 + t1 % 10;
        t1 = t1 / 10;
    }
    return t2;
}

long long leng(long long x) {
    long long t1, t2;
    t1 = x;
    t2 = 0;
    while (t1 != 0) {
        t2++;
        t1 = t1 / 10;
    }
    return t2;
}

long long mypow(long long x, long long z) {
    long long t1 = 1;
    for (long long i = 0; i < z; ++i)
        t1 = t1 * x;
    return t1;
}
int main() {
    long long t, i;
    long long x, ans;
    long long ten[15];
    ten[0] = 1;
    ten[1] = 10;
    for (i = 2; i <= 14; ++i) {
        ten[i] = ten[i-1] + pow(10, i/2) + pow(10, i-i/2) - 1;
    }
    cin >> t;
    for (long long z = 1; z <= t; ++z) {
        cin >> x;
        long long k = leng(x);
        cout << "Case #" << z << ": ";
        if (x < 10)
            cout << x << endl;
        else if (x == mypow(10, k-1)) {
            cout << ten[k-1] << endl;
        }
        else
        {
            bool plusone = false;
            if (x % mypow(10, k-k/2) == 0) {
                x--;
                plusone = true;
            }
            if (rever(x) % mypow(10, k/2) == 1) {
               ans = ten[k-1] + x - mypow(10, k-1);
            }
            else {
                ans = ten[k-1] + rever(x) % mypow(10, k/2) + x % mypow(10, k-k/2);
            }
            if (plusone)
               ans++;
            cout << ans << endl;
        }

    }
    return 0;
}
