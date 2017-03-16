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

ifstream in("A-small-attempt0.in");
ofstream out("A-small-attempt0.out");

int trans(int x) {
    int res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

void solve()
{
    int n;
    in >> n;
    vector<int> len(n + 1, 0);
    len[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int ri = trans(i);
        len[i] = len[i - 1] + 1;
        if (ri < i && i % 10 != 0) {
            len[i] = min(len[i], len[ri] + 1);
        }
    }
    out << len[n]; //<< endl;
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
