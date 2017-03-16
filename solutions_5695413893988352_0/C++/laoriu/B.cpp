#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)(1e18) * 2 + 1;

string special_case(string c, string j) {
    for(int i = 0; i < c.length(); i++)
        if ((c[i] != '?') && (j[i] != '?') && (c[i] != j[i]))
            return "";
    for(int i = 0; i < c.length(); i++)
        if (c[i] == '?') {
            if (j[i] == '?') c[i] = '0';
            else c[i] = j[i];
        }
    return c + " " + c;
}

long long toInt64(string s) {
    long long res = 0;
    for(int i = 0; i < s.length(); i++) res = res * 10 + (s[i] - '0');
    return res;
}

long long getDiff(string a, string b) {
    long long aa = toInt64(a), bb = toInt64(b);
    return abs(aa - bb);
}

pair<string, string> get(string big, string small) {
    string b = "", s = "";
    int p = -1;
    for(int i = 0; i < big.length(); i++) {
        b += (big[i] != '?') ? big[i] : '0';
        s += (small[i] != '?') ? small[i] : '0';
        if ((big[i] != '?') && (small[i] != '?') && (big[i] != small[i])) {
            p = i;
            break;
        }
    }

    for(int i = p + 1; i < big.length(); i++) {
        if (big[i] != '?') b += big[i]; else b += '0';
        if (small[i] != '?') s += small[i]; else s += '9';
    }

    return make_pair(b, s);
}

void updateBest(string &cur_best_c, string &cur_best_j, string new_c, string new_j) {
    long long cur_best_diff = (cur_best_c == "") ? INF : getDiff(cur_best_c, cur_best_j);
    long long new_diff = getDiff(new_c, new_j);
    if ((new_diff < cur_best_diff) || ((new_diff == cur_best_diff) && ( (new_c < cur_best_c) || ((new_c == cur_best_c) && (new_j < cur_best_j)) ))) {
        cur_best_c = new_c;
        cur_best_j = new_j;
    }
}

string solve() {
    string c, j;
    cin >> c >> j;

    if (special_case(c, j) != "") return special_case(c, j);

    string cur_best_c = "", cur_best_j = "";
    for(int i = 0; i < c.length(); i++) {
        char old_c_i = c[i], old_j_i = j[i];
        for(int d1 = 0; d1 <= 9; d1++)
            for(int d2 = 0; d2 <= 9; d2++)
                if (d1 != d2)
                    if ((c[i] - '0' == d1) || (old_c_i == '?'))
                        if ((j[i] - '0' == d2) || (old_j_i == '?')) {
                            c[i] = char(d1 + 48); j[i] = char(d2 + 48);
                            string big = (d1 > d2) ? c : j;
                            string small = (d1 > d2) ? j : c;
                            pair<string, string> pss = get(big, small);
                            string new_c = (d1 > d2) ? pss.first : pss.second;
                            string new_j = (d1 > d2) ? pss.second : pss.first;
                            updateBest(cur_best_c, cur_best_j, new_c, new_j);
                        }
        c[i] = old_c_i; j[i] = old_j_i;
        if ((c[i] != '?') && (j[i] != '?') && (c[i] != j[i])) break;
        if (c[i] != '?') j[i] = c[i];
        if (j[i] != '?') c[i] = j[i];
    }

    return cur_best_c + " " + cur_best_j;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int ntests;
    scanf("%d\n", &ntests);
    for(int tc = 1; tc <= ntests; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}
