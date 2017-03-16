#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> Point;
typedef vector<Point> vp;
typedef vector<vp> vvp;

bool DBG = false;

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        os << vector[i];
    }
    return os;
}

vi get_freq(const string& s) {
    vi freq(26, 0);
    forn(i, s.size()) {
        freq[s[i] - 'A']++;
    }
    return freq;
}
//
//vi res;
//for (const auto& kv : m) {
//    int d = kv.first;
//    string str = kv.second;
//    vi dfreq = get_freq(str);
//    int cnt = 0;
//    while (true) {
//        bool ok = true;
//        forn(i, str.size()) {
//            int q = str[i] - 'A';
//            if (sfreq[q] < dfreq[q]) {
//                ok = false;
//                break;
//            }
//        }
//        if (ok) {
//            ++cnt;
//            forn(i, str.size()) {
//                int q = str[i] - 'A';
//                sfreq[q] -= dfreq[q];
//            }
//        } else {
//            break;
//        }
//    }
//    forn(i, cnt) {
//        res.push_back(d);
//    }
//}

void add(vi& res, int freq, int d) {
    forn(i, freq) {
        res.push_back(d);
    }
}

void update(vi& sfreq, const string& digit, int cnt) {
    vi f = get_freq(digit);
    forn(i, f.size()) {
        sfreq[i] -= f[i] * cnt;
    }
}

vi solve(const string& s) {
    map<int, string> m;
    m[0] = "ZERO";  // Z
    m[2] = "TWO";  // W
    m[4] = "FOUR";  // U
    m[6] = "SIX";  // X
    m[8] = "EIGHT";  // G
    // ---
    m[1] = "ONE";  // O
    m[3] = "THREE";  // H
    m[5] = "FIVE";  // F
    m[7] = "SEVEN";  // S
    m[9] = "NINE";  // rest
    
    vb is_vis(s.size(), false);
    vi sfreq = get_freq(s);
    vi res;
    int zerofreq = sfreq['Z' - 'A'];
    add(res, zerofreq, 0);
    int twofreq = sfreq['W' - 'A'];
    add(res, twofreq, 2);
    int fourfreq = sfreq['U' - 'A'];
    add(res, fourfreq, 4);
    int sixfreq = sfreq['X' - 'A'];
    add(res, sixfreq, 6);
    int eightfreq = sfreq['G' - 'A'];
    add(res, eightfreq, 8);
    update(sfreq, m[0], zerofreq);
    update(sfreq, m[2], twofreq);
    update(sfreq, m[4], fourfreq);
    update(sfreq, m[6], sixfreq);
    update(sfreq, m[8], eightfreq);
    /// ...
    int onefreq = sfreq['O' - 'A'];
    add(res, onefreq, 1);
    int threefreq = sfreq['H' - 'A'];
    add(res, threefreq, 3);
    int fivefreq = sfreq['F' - 'A'];
    add(res, fivefreq, 5);
    int sevenfreq = sfreq['S' - 'A'];
    add(res, sevenfreq, 7);
    update(sfreq, m[1], onefreq);
    update(sfreq, m[3], threefreq);
    update(sfreq, m[5], fivefreq);
    update(sfreq, m[7], sevenfreq);
    int ninefreq = sfreq['I' - 'A'];
    add(res, ninefreq, 9);
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int nt;
    cin >> nt;
    forn(t, nt) {
        string s;
        cin >> s;
        cout << "Case #" << t + 1 << ": " << solve(s) << endl;
    }
    return 0;
}
