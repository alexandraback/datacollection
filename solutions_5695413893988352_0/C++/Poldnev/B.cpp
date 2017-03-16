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

ifstream in("B-small-attempt0.in");
ofstream out("output.txt");

bool check(const string &pat, int x) {
    int pos = pat.length() - 1;
    while (x || pos >= 0) {
        int d = x % 10;
        if (pos < 0 || !(pat[pos] == '?' || pat[pos] - '0' == d)) {
            return false;
        }
        --pos;
        x /= 10;
    }
    return x == 0;
}

void solve()
{
    string s, t;
    in >> s >> t;
    int sr = -1, tr = -1;
    for (int sn = 0; sn < 1000; ++sn) {
        if (!check(s, sn)) {
            continue;
        }
        for (int tn = 0; tn < 1000; ++tn) {
            if (!check(t, tn)) {
                continue;
            }
            if (sr < 0 || abs(sn - tn) < abs(sr - tr)) {
                sr = sn;
                tr = tn;
            }
        }
    }
    out << setfill('0') << setw(s.length()) << sr << " " << setfill('0') << setw(s.length()) << tr;
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
