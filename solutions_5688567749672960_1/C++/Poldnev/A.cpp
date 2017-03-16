#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<long long, long long> plint;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<long long> vlint;
typedef vector<vector<long long>> vvlint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<long long, long long>> vplint;

ifstream in("A-large.in");
ofstream out("A-large.out");

ll trans(ll x) {
    ll res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int numcount(ll x) {
    int res = 0;
    while (x) {
        x /= 10;
        ++res;
    }
    return res;
}

void solve()
{
    long long n;
    in >> n;
    if (n < 10) {
        out << n;
        return;
    }
    int k = numcount(n);
    --k;
    vector<long long> deg10(15);
    deg10[0] = 1;
    for (int i = 1; i <= k; ++i) {
        deg10[i] = deg10[i - 1] * 10;
    }
    vector<long long> res10(k + 1);
    res10[0] = 1;
    res10[1] = 10;
    for (int i = 2; i <= k; ++i) {
        res10[i] = res10[i - 1] + deg10[i / 2] + deg10[i - i / 2] - 1;
    }
    long long res = res10[k];
    long long best = n - deg10[k];
    if (n == deg10[k]) {
        out << res;
        return;
    }
    int add = 0;
    if (n % 10 == 0) {
        --n;
        add = 1;
    }
    for (int i = 1; i <= k; ++i) {
        long long m = n - (n % deg10[i]) + 1;
        long long rm = trans(m);
        best = min(best, (rm - deg10[k]) + 1 + (n - m) + add);
    }
    out << best + res;
}

int main()
{
    int cases;
    in >> cases;
    for (int z = 0; z < cases; ++z) {
        out << "Case #" << z + 1 << ": ";
        solve();
        out << endl;
    }

    return 0;
}
