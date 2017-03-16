#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int L = 10000000;

vector<long long> ret;

bool check(long long x)
{
    char buf[20];
    int l = sprintf(buf, "%I64d", x);
    for (int i = 0; i < l / 2; ++i)
        if (buf[i] != buf[l - 1 - i])
            return false;
    return true;
}

long long calc(long long x)
{
    return upper_bound(ret.begin(), ret.end(), x) - ret.begin();
}

int main()
{
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);

    for (long long i = 1; i <= L; ++i)
        if (check(i) && check(i * i))
            ret.push_back(i * i);
    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        long long a, b;
        cin >> a >> b;
        cout << calc(b) - calc(a - 1);
        printf("\n");
    }
    
    return 0;
}
