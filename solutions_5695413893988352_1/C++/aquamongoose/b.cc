#include <bits/stdc++.h>
using namespace std;

long long dif(string a, string b) {
    long long A, B;
    stringstream ss;
    ss << a << ' ' << b;
    ss >> A;
    ss >> B;
    return llabs(A-B);
}

void assign_best(string &ansa, string &ansb, string &tempa, string &tempb) {
    if (ansa == "") {
        ansa = tempa;
        ansb = tempb;
        return;
    }
    long long firs = dif(ansa, ansb), seco = dif(tempa, tempb);
    if (seco < firs) {
        ansa = tempa;
        ansb = tempb;
    } else if (firs == seco && tempa < ansa) {
        ansa = tempa;
        ansb = tempb;
    } else if (firs == seco && tempa == ansa && tempb < ansb) {
        ansa = tempa;
        ansb = tempb;
    }
}

void attemptA(string &ansa, string &ansb, string tempa, string tempb) {
    for (int i=0; i<tempa.size(); i++) {
        if (tempa[i] == '?')
            tempa[i] = '0';
        if (tempb[i] == '?')
            tempb[i] = '9';
    }
    assign_best(ansa, ansb, tempa, tempb);
}

void attemptB(string &ansa, string &ansb, string tempa, string tempb) {
    for (int i=0; i<tempa.size(); i++) {
        if (tempa[i] == '?')
            tempa[i] = '9';
        if (tempb[i] == '?')
            tempb[i] = '0';
    }
    assign_best(ansa, ansb, tempa, tempb);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int cas=1; cas<=cases; cas++) {
        cout << "Case #" << cas << ": ";
        string a, b;
        cin >> a >> b;
        while (a.size() < b.size()) a = "0"+a;
        while (b.size() < a.size()) b = "0"+b;
        string ansa, ansb;
        for (int i=0; i<a.size(); i++) {
            if (a[i] == '?') {
                if (b[i] == '?') {
                    a[i] = '1';
                    b[i] = '0';
                    attemptA(ansa, ansb, a, b);
                    a[i] = '0';
                    b[i] = '1';
                    attemptB(ansa, ansb, a, b);
                    a[i] = '0';
                    b[i] = '0';
                } else {
                    if (b[i] < '9') {
                        a[i] = b[i]+1;
                        attemptA(ansa, ansb, a, b);
                    }
                    if (b[i] > '0') {
                        a[i] = b[i]-1;
                        attemptB(ansa, ansb, a, b);
                    }
                    a[i] = b[i];
                }
            } else if (b[i] == '?') {
                if (a[i] < '9') {
                    b[i] = a[i]+1;
                    attemptB(ansa, ansb, a, b);
                }
                if (a[i] > '0') {
                    b[i] = a[i]-1;
                    attemptA(ansa, ansb, a, b);
                }
                b[i] = a[i];
            } else if (a[i] > b[i]) {
                attemptA(ansa, ansb, a, b);
            } else if (a[i] < b[i]) {
                attemptB(ansa, ansb, a, b);
            }
        }
        attemptA(ansa, ansb, a, b);
        attemptB(ansa, ansb, a, b);
        cout << ansa << ' ' << ansb << endl;
    }
    return 0;
}
