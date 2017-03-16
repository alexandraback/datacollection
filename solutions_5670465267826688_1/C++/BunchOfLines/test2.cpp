#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MP make_pair

int L;
ll X;
string s;
map<pair<string,string>, string> m;

void setup() {
    string val[] = {"1", "i", "j", "k"};
    string table[4][4] = {
        {"1", "i", "j", "k"},
        {"i", "-1", "k", "-j"},
        {"j", "-k", "-1", "i"},
        {"k", "j", "-i", "-1"},
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[MP(val[i], val[j])] = table[i][j];
        }
    }
}

string mult(string a, string b) {
    int m1 = 1, m2 = 1;
    string l = a, r = b;
    if (a.size() == 2) {
        m1 = -1;
        l = a.substr(1);
    }
    if (b.size() == 2) {
        m2 = -1;
        r = b.substr(1);
    }
    string res = m[MP(l, r)];
    int s1 = m1 * m2;
    int s2;
    if (res.size() == 1) {
        s2 = 1;
    }
    else {
        s2 = -1;
        res = res.substr(1);
    }
    if (s1 * s2 == -1)
        res = "-" + res;
    return res;
}

string pow(string base, ll exp) {
    if (exp == 0)
        return "1";
    string p = pow(base, exp / 2);
    string ans = mult(p, p);
    if (exp % 2) {
        ans = mult(base, ans);
    }
    return ans;
}

string eval(string s) {
    string ans = "1";
    for (int i = 0; i < s.size(); i++) {
        ans = mult(ans, s.substr(i, 1));
    }
    return ans;
}

string can(string s, ll num_copies, string target_value) {
    int L = s.size();
    if (target_value == "i") {
        string ans = pow(eval(s), num_copies);
        if (ans == target_value)
            return "";
        for (int i = 0; i < L; i++) {
            ans = mult(ans, s.substr(i, 1));
            if (ans == target_value)
                return s.substr(0, i + 1);
        }
        return "invalid";
    } else {
        string ans = pow(eval(s), num_copies);
        if (ans == target_value)
            return "";
        for (int i = L - 1; i >= 0; i--) {
            ans = mult(s.substr(i, 1), ans);
            if (ans == target_value)
                return s.substr(i, L - i);
        }
        return "invalid";
    }
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    setup();
    int T;
    cin>>T;
    for (int cc = 1; cc <= T; cc++) {
        cin>>L>>X;
        cin>>s;

        string e = eval(s);
        if (pow(e, X) != "-1") {
            printf("Case #%d: NO\n", cc);
            continue;
        }

        string ans1 = "invalid";
        ll ncpy1 = 0;
        for (ll i = 0; i < 10; i++) {
            string ans = can(s, i, "i");
            if (ans != "invalid") {
                ans1 = ans;
                ncpy1 = i;
                break;
            }
        }

        string ans2 = "invalid";
        ll ncpy2 = 0;
        for (ll i = 0; i < 10; i++) {
            string ans = can(s, i, "k");
            if (ans != "invalid") {
                ans2 = ans;
                ncpy2 = i;
                break;
            }
        }
        if (ans1 != "invalid" && ans2 != "invalid") {
            ll ncpy = ncpy1 + ncpy2;
            if (ans1.size() + ans2.size() >= L) {
                ncpy += 2;
            } else {
                ncpy++;
            }
            if (ncpy <= X)
                printf("Case #%d: YES\n", cc);
            else
                printf("Case #%d: NO\n", cc);
        } else {
            printf("Case #%d: NO\n", cc);
        }
    }
    return 0;
}
