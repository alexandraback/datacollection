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

ifstream in("C-small-1-attempt0.in");
ofstream out("output.txt");

struct Three
{
    int a, b, c;
    Three(int a_ = 0, int b_ = 0, int c_ = 0) : a(a_), b(b_), c(c_) {}
    int prod(int q = 0)
    {
        return (q & 4 ? a : 1) * (q & 2 ? b : 1) * (q & 1 ? c : 1);
    }
    bool operator<(const Three &t) const
    {
        return (a < t.a || (a == t.a && (b < t.b || (b == t.b && c < t.c))));
    }
};

void solve()
{
    int r, n, m, k;
    in >> r >> n >> m >> k;
    const int Q = (1 << n);
    map<Three, set<int>> w;
    Three t;
    for (t.a = 2; t.a <= m; ++t.a) {
        for (t.b = 2; t.b <= m; ++t.b) {
            for (t.c = 2; t.c <= m; ++t.c) {
                set<int> &s = w[t];
                for (int q = 0; q < Q; ++q) {
                    s.insert(t.prod(q));
                }
            }
        }
    }
    for (int z = 0; z < r; ++z) {
        vint a(k);
        for (int &x : a) {
            in >> x;
        }
        vector<Three> good;
        Three t;
        for (t.a = 2; t.a <= m; ++t.a) {
            for (t.b = 2; t.b <= m; ++t.b) {
                for (t.c = 2; t.c <= m; ++t.c) {
                    set<int> &s = w[t];
                    bool ok = true;
                    for (int x : a) {
                        if (s.count(x) == 0) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        good.pb(t);
                    }
                }
            }
        }
        int g = good.size();
        t = good[rand() % g];
        out << t.a << t.b << t.c << endl;
    }
}

int main()
{
    int cases;
    in >> cases;
    for (int z = 0; z < cases; ++z) {
        out << "Case #" << z + 1 << ":" << endl;
        solve();
    }

    return 0;
}
