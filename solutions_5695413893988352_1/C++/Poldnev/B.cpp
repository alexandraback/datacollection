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

ifstream in("B-large.in");
//ifstream in("input.txt");
ofstream out("output.txt");

enum Mode {
    CLOSER, FIRST_HIGH, FIRST_LOW
};

vint to_mask(const string &s) {
    vint res;
    res.reserve(s.length());
    for (char c : s) {
        res.push_back(c == '?' ? -1 : c - '0');
    }
    return res;
}

void go(const vint &mask_a, const vint &mask_b, int p, Mode mode, bool try_first_high, ll cur_a, ll cur_b, ll &best_a, ll &best_b, ll &best_dist)
{
    if (p == mask_a.size()) {
        ll dist = abs(cur_a - cur_b);
        if (best_dist < 0 || dist < best_dist) {
            best_dist = dist;
            best_a = cur_a;
            best_b = cur_b;
        }
        return;
    }
    int ma = mask_a[p], mb = mask_b[p];
    if (ma >= 0 && mb >= 0) {
        Mode next_mode = mode;
        if (mode == CLOSER && ma < mb) {
            next_mode = FIRST_HIGH;
        } else if (mode == CLOSER && ma > mb) {
            next_mode = FIRST_LOW;
        }
        go(mask_a, mask_b, p + 1, next_mode, try_first_high, cur_a * 10 + ma, cur_b * 10 + mb, best_a, best_b, best_dist);
    } else if (mode != CLOSER) {
        int da = (ma >= 0 ? ma : (mode == FIRST_HIGH ? 9 : 0));
        int db = (mb >= 0 ? mb : (mode == FIRST_HIGH ? 0 : 9));
        go(mask_a, mask_b, p + 1, mode, try_first_high, cur_a * 10 + da, cur_b * 10 + db, best_a, best_b, best_dist);
    } else {
        if (ma < 0 && mb >= 0) {
            if (!try_first_high && mb > 0) {
                go(mask_a, mask_b, p + 1, FIRST_HIGH, try_first_high, cur_a * 10 + mb - 1, cur_b * 10 + mb, best_a, best_b, best_dist);
            }
            go(mask_a, mask_b, p + 1, mode, try_first_high, cur_a * 10 + mb, cur_b * 10 + mb, best_a, best_b, best_dist);
            if (try_first_high && mb < 9) {
                go(mask_a, mask_b, p + 1, FIRST_LOW, try_first_high, cur_a * 10 + mb + 1, cur_b * 10 + mb, best_a, best_b, best_dist);
            }
        } else if (ma >= 0 && mb < 0) {
            if (try_first_high && ma > 0) {
                go(mask_a, mask_b, p + 1, FIRST_LOW, try_first_high, cur_a * 10 + ma, cur_b * 10 + ma - 1, best_a, best_b, best_dist);
            }
            go(mask_a, mask_b, p + 1, mode, try_first_high, cur_a * 10 + ma, cur_b * 10 + ma, best_a, best_b, best_dist);
            if (!try_first_high && ma < 9) {
                go(mask_a, mask_b, p + 1, FIRST_HIGH, try_first_high, cur_a * 10 + ma, cur_b * 10 + ma + 1, best_a, best_b, best_dist);
            }
        } else {
            go(mask_a, mask_b, p + 1, mode, try_first_high, cur_a * 10, cur_b * 10, best_a, best_b, best_dist);
            if (try_first_high) {
                go(mask_a, mask_b, p + 1, FIRST_LOW, try_first_high, cur_a * 10 + 1, cur_b * 10, best_a, best_b, best_dist);
            } else {
                go(mask_a, mask_b, p + 1, FIRST_HIGH, try_first_high, cur_a * 10, cur_b * 10 + 1, best_a, best_b, best_dist);
            }
        }
    }
}

void solve()
{
    string s, t;
    in >> s >> t;
    vint a = to_mask(s), b = to_mask(t);

    int first_danger = 0;
    bool try_first_high = false;
    while (first_danger < a.size()) {
        int da = a[first_danger], db = b[first_danger];
        if (da >= 0 && db >= 0 && da != db) {
            try_first_high = (da < db);
            break;
        }
        ++first_danger;
    }

    ll best_a = -1, best_b = -1, best_dist = -1;
    go(a, b, 0, CLOSER, try_first_high, 0, 0, best_a, best_b, best_dist);
    out << setfill('0') << setw(s.length()) << best_a << " " << setfill('0') << setw(s.length()) << best_b;
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
