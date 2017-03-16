#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fcntl.h>
#include <fstream>
// #include <hash_map>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>

using namespace std;
// using namespace __gnu_cxx;  // Essential if you want to use hash_map.

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <double> vd;
typedef vector <string> vs;
typedef vector <pii> vpii;

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fe(it, X) for (typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)  // -std=gnu++98, 0x, 11.
#define fev(i, v) for (int i = 0; i < sz(v); ++i)
#define pb push_back
#define pf pop_front
#define mp(a, b) make_pair(a, b)
#define sz(x) (static_cast<int> ((x).size()))
#define sqr(x) ((x) * (x))

int K, N;

map<int, int> init;
vi types;
vector<map<int, int> > keys;

vector<string> flags;

string recur(const map<int, int> &_cur, int flag) {
    if (flag == (1 << N) - 1) {
        return "";
    }
    if (sz(flags[flag]) == 0) {
        rep(i, N) {
            int mask = 1 << i;
            if ((flag & mask) == 0) {
                int type = types[i];
                map<int, int> cur = _cur;
                map<int, int>::iterator it = cur.find(type);
                if (it != cur.end()) {
                    assert(it->second > 0);
                    if (--(it->second) == 0) {
                        cur.erase(it);
                    }
                    fe (itr, keys[i]) {
                        cur[itr->first] += itr->second;
                    }
                    string ret = recur(cur, flag | mask);
                    if (ret != "IMPOSSIBLE") {
                        char buf[20];
                        itoa(i + 1, buf, 10);
                        flags[flag] = " " + (buf + ret);
                        return flags[flag];
                    }
                }
            }
        }
        flags[flag] = "IMPOSSIBLE";
    }
    return flags[flag];
}

string solve() {
    flags.clear();
    flags.resize(1 << N, "");
    return recur(init, 0);
}

void output() {
}

void main2() {
    /*ifstream in("sample.txt");
    ofstream out("sample.output");*/
    ifstream in("D-small-attempt0.in");
    ofstream out("D-small-attempt0.output");
    /*ifstream in("D-large.in");
    ofstream out("D-large.output");*/
    int num_cases;
    in >> num_cases;
    cout << num_cases << endl;
    for (int i = 1; i <= num_cases; ++i) {
        in >> K >> N;
        // cout << K << " " << N << endl;
        init.clear();
        rep(j, K) {
            int t;
            in >> t;
            ++init[t];
        }
        keys.clear();
        types.clear();
        rep(j, N) {
            int type, have;
            in >> type >> have;
            map<int, int> key;
            rep(k, have) {
                int t;
                in >> t;
                ++key[t];
            }
            types.pb(type);
            keys.pb(key);
        }
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
        out << "Case #" << i << ": " << ans << endl;

    }
    in.close();
    out.close();
}

int main() {
    main2();

    return 0;
}
