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

int can(int s, int i, int k, ll num_copies) {
    int j;
    if (s == i * k)
        j = -1;
    else
        j = 1;
    if (i == -1) num_copies--;
    if (j == -1) num_copies--;
    if (k == -1) num_copies--;
    return num_copies >= 0 && (num_copies % 2 == 0);
}

int sign(string s) {
    string mul = "1";
    for (int i = 0; i < s.size(); i++) {
        mul = mult(mul, s.substr(i, 1));
    }
    if (mul != "1" &&  mul != "-1")
        return 0;
    if (mul.size() == 1)
        return 1;
    return -1;
}

int can_solve(string s, string cpy, ll num_copies) {
    int L = s.size();
    int sgn = sign(s);

    string mul = "1";
    int ipos = -1, ineg = -1;
    for (int i = 0; i < L; i++) {
        mul = mult(mul, s.substr(i, 1));
        if (ipos == -1 && mul == "i") {
            ipos = i;
        }
        if (ineg == -1 && mul == "-i") {
            ineg = i;
        }
    }

    mul = "1";
    int kpos = -1, kneg = -1;
    for (int i = L - 1; i >= 0; i--) {
        mul = mult(s.substr(i, 1), mul);
        if (kpos == -1 && mul == "k") {
            kpos = i;
        }
        if (kneg == -1 && mul == "-k") {
            kneg = i;
        }
    }
    int a[] = {1, -1};
    int i1[] = {ipos, ineg}, k1[] = {kpos, kneg};
    int res = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            if (i1[i] >= 0 && k1[j] >= 0 && i1[i] < k1[j]) {
                res = res || can(sgn, a[i], a[j], num_copies);
            }
        }

    return res;
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    setup();
    int T;
    cin>>T;
    for (int cc = 1; cc <= T; cc++) {
        cin>>L>>X;
        cin>>s;
        string temp = "";
        for (int i = 0; i < X; i++)
            temp += s;
        L = L * X;
        X = 0;
        string mul = "1";
        for (int i = 0; i < L; i++) {
            mul = mult(mul, temp.substr(i, 1));
        }

        if (mul != "-1") {
            /*if (X % 2 == 0) {
                mul = mult(mul, mul);
                L *= 2;
                X /= 2;
                s += s;
            } else {*/
                printf("Case #%d: NO\n", cc);
                continue;
            //}
        }

        int res = 0;
        string cpy = s, curr = temp;
        ll num_copies = 0;
        for (int i = 0; i < 10 && num_copies >= 0; i++) {
            if (can_solve(curr, cpy, num_copies)) {
                res = 1;
                break;
            }
            curr += s;
            num_copies--;
        }

        if (res)
            printf("Case #%d: YES\n", cc);
        else
            printf("Case #%d: NO\n", cc);
    }
    return 0;
}
