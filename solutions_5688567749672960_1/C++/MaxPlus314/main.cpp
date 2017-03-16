#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

string cs, t;
stringstream ci;

int ans(int64_t n)
{
//    if (n <= 10)
//        return n;
    if (n <= 20)
        return n;
    ci.clear();
    ci << n;
    ci >> cs;
    int64_t cans = 0, b;
    ci.clear();
    ci << cs.substr((cs.size()) / 2, cs.size());
    ci >> b;
    if (b == 0)
        return ans(n - 1) + 1;
    cans += b - 1;
    n -= b - 1;
    bool rev = 0;
    if (cs[0] != '1')
        rev = 1;
    for (int i = 1; i < (cs.size()) / 2; ++i)
        if (cs[i] != '0')
            rev = 1;
    if (!rev)
        return ans(----n) + cans + 2;
    ci.clear();
    ci << n;
    ci >> cs;
    reverse(cs.begin(), cs.end());
    ci.clear();
    ci << cs;
    ci >> n;
    return ans(n) + cans + 1;
}

int main()
{
    int Q;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> Q;
    for (int i = 1; i <= Q; ++i)
    {
        int64_t n;
        cin >> n;
        cout << "Case #" << i << ": " << ans(n) << '\n';
    }
    return 0;
}
