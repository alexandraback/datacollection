#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

string C, J;

string CC, JJ;
long long delta;
int n;

long long toNumber(string &S) {
    long long ret = 0;
    for (int i = 0; i < S.size(); ++ i)
        ret = ret * 10 + (long long)(S[i] - '0');
    return ret;
}

void search(int x, int flag) {
    if (x == n) {
        long long A = toNumber(C);
        long long B = toNumber(J);
        long long K;
        if (A > B)
            K = A - B;
        else
            K = B - A;
        if (K < delta) {
            delta = K;
            CC = C;
            JJ = J;
        }
        else if (K == delta) {
            if (C < CC) {
                CC = C;
                JJ = J;
            }
            else if (C == CC && J < JJ) {
                CC = C;
                JJ = J;
            }
        }
        return;
    }
    if (C[x] == '?' && J[x] == '?') {
        if (flag == 0) {
            C[x] = J[x] = '0';
            search(x + 1, 0);

            C[x] = '0'; J[x] = '1';
            search(x + 1, 1);

            C[x] = '1'; J[x] = '0';
            search(x + 1, -1);
        }
        else if (flag == 1) {
            C[x] = '9';
            J[x] = '0';
            search(x + 1, 1);
        }
        else {
            C[x] = '0';
            J[x] = '9';
            search(x + 1, -1);
        }
        C[x] = J[x] = '?';
    }
    else if (C[x] == '?') {
        if (flag == 0) {
            C[x] = J[x];
            search(x + 1, 0);

            if (J[x] != '0') {
                C[x] = J[x] - 1;
                search(x + 1, 1);
            }
            if (J[x] != '9') {
                C[x] = J[x] + 1;
                search(x + 1, -1);
            }
        }
        else if (flag == 1) {
            C[x] = '9';
            search(x + 1, 1);
        }
        else {
            C[x] = '0';
            search(x + 1, -1);
        }
        C[x] = '?';
    }
    else if (J[x] == '?') {
        if (flag == 0) {
            J[x] = C[x];
            search(x + 1, 0);

            if (C[x] != '0') {
                J[x] = C[x] - 1;
                search(x + 1, -1);
            }
            if (C[x] != '9') {
                J[x] = C[x] + 1;
                search(x + 1, 1);
            }
        }
        else if (flag == 1) {
            J[x] = '0';
            search(x + 1, 1);
        }
        else {
            J[x] = '9';
            search(x + 1, -1);
        }
        J[x] = '?';
    }
    else if (flag == 0) {
        if (C[x] < J[x])
            search(x + 1, 1);
        else if (C[x] > J[x])
            search(x + 1, -1);
        else
            search(x + 1, 0);
    }
    else search(x + 1, flag);
}

void solve() {
    n = C.size();
    delta = 999999999999999999LL;
    CC = ""; JJ = "";
    search(0, 0);
    cout << CC << " " << JJ << endl;
}

int main() {
    int T;
    int test = 1;
    for (cin >> T; T --;) {
        cin >> C >> J;
        cout << "Case #" << test ++ << ": ";
        solve();
    }
    return 0;
}
