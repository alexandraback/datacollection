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
#define vint vector<int>
#define viint vector<vector<int>>
#define vlint vector<long long>
#define vliint vector<vector<long long>>

ifstream in("B-small-attempt0.in");
ofstream out("output.txt");

void solve()
{
    int e, r, n;
    in >> e >> r >> n;
    vector<pair<int, int>> v;
    vint a(n, -1);
    for (int i = 0; i < n; ++i) {
        int x;
        in >> x;
        v.pb({x, i});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int q = n - 1; q >= 0; --q) {
        int i = v[q].second;
        int x = v[q].first;
        long long ps = 0;
        long long top = e;
        for (int j = 0; j < n; ++j) {
            if (a[j] >= 0) {
                ps += a[j];
                //cerr << j << ": " << a[j] << endl;
            } else if (j < i) {
                long long d = max(0ll, (j + 1) * r - ps);
                ps += d;
                //cerr << j << ": " << d << endl;
            } else {
                /*long long d = max(0ll, (j + 1) * r - ps);
                ps += d;
                cerr << j << ": " << d << endl;*/
            }
            if (j >= i) {
                top = min(top, e + j * r - ps);
            }
        }
        if (top < 0) {
            cerr << "FAIL!" << endl;
            exit(0);
        }
        a[i] = top;
        ans += ((long long) x) * top;
        //cerr << i << " " << top << endl;
    }
    out << ans;
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
