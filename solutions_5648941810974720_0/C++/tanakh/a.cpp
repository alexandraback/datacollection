#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

const string digs[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

map<pair<int, map<char, int>>, string> tbl;

string rec(int mi, const map<char, int> &m)
{
    bool remain = false;
    for (auto &kv: m) if (kv.second > 0) remain = true;
    if (!remain) return "";

    auto key = make_pair(mi, m);
    if (tbl.count(key)) {
        return tbl[key];
    }

    string &ret = tbl[key];
    ret = "-";

    for (int i = mi; i <= 9; i++) {
        map<char, int> tt = m;
        int use = 0;
        const string &dig = digs[i];
        for (int j = 0; j < dig.size(); j++) {
            if (tt[dig[j]] > 0) {
                tt[dig[j]]--;
                use++;
            }
        }
        if (use == dig.size()) {
            string rest = rec(i, tt);
            if (rest != "-") {
                ret = (char)('0' + i) + rest;
                break;
            }
        }
    }

    return ret;
}

void solve()
{
    string s;
    cin >> s;

    map<char, int> mm;
    for (char &c: s) mm[c]++;

    cout << rec(0, mm) << endl;
}


int main()
{
    int t; cin >> t;
    for (int cn = 1; cn <= t; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}