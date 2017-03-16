#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair


bool isPoly(long long n)
{
    vector<int> d;
    while (n > 0)
    {
        d.push_back(n % 10);
        n /= 10;
    }
    vector<int> b = d;
    reverse(d.begin(), d.end());
    return b == d;
}

long long p[1000 * 1000];
int sz = 0;

void pre()
{
     for (long long i = 1; i <= 10000000; ++i)
        if (isPoly(i) && isPoly(i * i))
            p[sz++] = i * i;
}

void solve(int test)
{
    long long a, b;
    cin >> a >> b;
    long long ans = 0;
    for (int i = 0; i < sz; ++i)
        if (p[i] >= a && p[i] <= b)
            ans++;
    cout << "Case #" << test << ": " << ans << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    pre();

    int test;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        solve(i);

    return 0;
}
