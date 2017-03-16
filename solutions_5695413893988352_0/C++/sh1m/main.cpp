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


string get_str(int x, int sz) {
    string res;
    forn(i, sz) {
        res += ('0' + x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

set<int> get_options(string s) {
    set<int> options;
    int res = 0;
    bool any_questions = false;
    forn(i, s.size()) {
        if (s[i] == '?') {
            any_questions = true;
            forn(j, 10) {
                string t = s;
                t[i] = static_cast<char>('0' + j);
                auto topt = get_options(t);
                for(const auto& opt : topt) {
                    options.insert(opt);
                }
            }
        } else {
            res = res * 10 + (s[i] - '0');
        }
    }
    if (any_questions == false) {
        options.insert(res);
    }
    return options;
}

string solve(const string& cs, const string& js) {
    set<int> co = get_options(cs);
    set<int> jo = get_options(js);
    Point resp = mp(INT_MAX, INT_MAX);
    int min_diff = INT_MAX;
    for (int cnum : co) {
        auto it = jo.lower_bound(cnum);
        int diff = INT_MAX;
        Point p;
        if (it != jo.end()) {
            int loc_diff = abs(*it - cnum);
            if (loc_diff < diff) {
                diff = loc_diff;
                p = mp(cnum, *it);
            }
        }
        if (it != jo.begin()) {
            --it;
            int loc_diff = abs(*it - cnum);
            if (loc_diff <= diff) {
                diff = loc_diff;
                p = mp(cnum, *it);
            }
        }
        
        if (diff < min_diff || (diff == min_diff && p.X < resp.X) || (diff == min_diff && p.X == resp.X && p.Y < resp.Y)) {
            min_diff = diff;
            resp = p;
        }
    }
    int tsize = (int)cs.size();
    return get_str(resp.X, tsize) + " " + get_str(resp.Y, tsize);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int nt;
    cin >> nt;
    forn(t, nt) {
        string cs, js;
        cin >> cs >> js;
        cout << "Case #" << t + 1 << ": " << solve(cs, js) << endl;
    }
    return 0;
}
