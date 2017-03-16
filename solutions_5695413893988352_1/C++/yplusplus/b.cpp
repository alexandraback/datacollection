#include <iostream>
#include <cassert>
#include <string>
using namespace std;

void set_max(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') s[i] = '9';
    }
}

void set_min(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') s[i] = '0';
    }
}

long long delta(const string &a, const string &b) {
    long long d = 0;
    try {
        long long A = stoll(a);
        long long B = stoll(b);
        d = A - B;
    } catch (...) {
        cout << a << " " << b << endl;
        assert(false);
    }
    return d >= 0 ? d : -d;
}

string set_dight(string s, int pos, char d) {
    if (s[pos] == '?') s[pos] = d;
    return s;
}

long long ansD;
string ansC, ansJ;
void update(const string &CC, const string &JJ) {
    long long d = delta(CC, JJ);
    if (d < ansD || (d == ansD && CC < ansC) || 
            (d == ansD && CC == ansC && JJ < ansJ))
    {
        ansD = d;
        ansC = CC;
        ansJ = JJ;
    }
}

int main() {
    int T, Case = 1;
    cin >> T;
    while (T--) {
        string C, J;
        cin >> C >> J;
        ansD = LLONG_MAX;
        int n = C.length();
        string CC, JJ;
        for (int i = 0; i < n; i++) {
            bool c = C[i] == '?';
            bool j = J[i] == '?';
            if (c && j) {
                CC = set_dight(C, i, '0'); set_max(CC);
                JJ = set_dight(J, i, '1'); set_min(JJ);
                update(CC, JJ);
                CC = set_dight(C, i, '1'); set_min(CC);
                JJ = set_dight(J, i, '0'); set_max(JJ);
                update(CC, JJ);
                C[i] = J[i] = '0';
            } else if (c) {
                if (J[i] < '9') {
                    CC = set_dight(C, i, J[i] + 1); set_min(CC);
                    JJ = set_dight(J, i, J[i]); set_max(JJ);
                    update(CC, JJ);
                }
                if (J[i] > '0') {
                    CC = set_dight(C, i, J[i] - 1); set_max(CC);
                    JJ = set_dight(J, i, J[i]); set_min(JJ);
                    update(CC, JJ);
                }
                C[i] = J[i];
            } else if (j) {
                if (C[i] < '9') {
                    CC = set_dight(C, i, C[i]); set_max(CC);
                    JJ = set_dight(J, i, C[i] + 1); set_min(JJ);
                    update(CC, JJ);
                }
                if (C[i] > '0') {
                    CC = set_dight(C, i, C[i]); set_min(CC);
                    JJ = set_dight(J, i, C[i] - 1); set_max(JJ);
                    update(CC, JJ);
                }
                J[i] = C[i];
            } else {
                if (C[i] != J[i]) {
                    if (C[i] > J[i]) {
                        set_min(C);
                        set_max(J);
                        update(C, J);
                    } else {
                        set_max(C);
                        set_min(J);
                        update(C, J);
                    }
                    break;
                }
            }
        }
        if (C == J) update(C, J);
        cout << "Case #" << Case++ << ": " << ansC << " " << ansJ << endl;
    }
    return 0;
}
