#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    freopen("innn.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> n;
    int cs = 0;
    while(n--) {
        long long x, y;
        char ch;
        cs++;
        cout << "Case #" << cs << ": ";
        cin >> x >> ch >> y;

        bool flag = false;

        long long g = __gcd(x, y);
        x /= g;
        y /= g;
        if(__builtin_popcount(y) > 1 || x > y) {
            cout << "impossible" << endl;
            continue;
        }
        long long num = 0;
        while(x != y) {
            num ++;
            x *= 2;
            g = __gcd(x,y);
            x /= g;
            y /= g;
            long long xx = log2(x);
            x = 1<<xx;
        }
        cout << num << endl;
    }
}
