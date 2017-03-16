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

ifstream in("C-small-attempt0.in");
ofstream out("output.txt");

void solve()
{
    int n;
    in >> n;
    map<string, int> firsts, seconds;
    vpint pairs(n);
    for (pint &p : pairs) {
        string ff, ss;
        in >> ff >> ss;
        if (firsts.count(ff)) {
            p.f = firsts[ff];
        } else {
            int size = firsts.size();
            p.f = firsts[ff] = size;
        }
        if (seconds.count(ss)) {
            p.s = seconds[ss];
        } else {
            int size = seconds.size();
            p.s = seconds[ss] = size;
        }
    }

    int result = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        auto is_fake = [mask](int i) -> bool { return mask & (1 << i); };
        vector<bool> w1(firsts.size(), false), w2(seconds.size(), false);
        int fake_count = n;
        for (int i = 0; i < n; ++i) {
            if (!is_fake(i)) {
                --fake_count;
                w1[pairs[i].f] = true;
                w2[pairs[i].s] = true;
            }
        }
        int done_fakes = 0;
        for (int i = 0; i < n; ++i) {
            if (is_fake(i) && w1[pairs[i].f] && w2[pairs[i].s]) {
                ++done_fakes;
            }
        }
        if (done_fakes == fake_count && fake_count > result) {
            result = fake_count;
        }
    }
    out << result;
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
