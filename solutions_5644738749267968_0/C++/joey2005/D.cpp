#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int readDouble() {
    char buf[100];
    scanf("%s", buf);
    int pos = -1;
    for (int i = 0; buf[i]; ++i) {
        if (buf[i] == '.') {
            pos = i;
            break;
        }
    }
    int res = 0;
    for (int i = 0; i < pos; ++i) {
        res = res * 10 + int(buf[i] - '0');
    }
    int base = 100000;
    for (int i = pos + 1; buf[i]; ++i) {
        res = res * 10 + int(buf[i] - '0');
        base /= 10;
    }
    res *= base;
    return res;
}

vector<int> prepare(int len) {
    vector<int> res(len);
    for (int i = 0; i < res.size(); ++i) {
        res[i] = readDouble();
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int n;
    scanf("%d", &n);

    vector<int> a = prepare(n);
    vector<int> b = prepare(n);
    int ansB = 0;
    vector<int> b2(b);
    for (int i = n - 1; i >= 0; --i) {
        int j;
        for (j = b2.size() - 1; j >= 0; --j) {
            if (b2[j] > a[i]) {
                break;
            }
        }
        if (j < 0) {
            ansB++;
            b2.erase(b2.begin() + b2.size() - 1);
        } else {
            b2.erase(b2.begin() + j);
        }
    }

    int ansA = 0;
    for (int i = n; i > 0; --i) {
        bool ok = true;
        for (int j = 0; j < i && ok; ++j) {
            if (a[j] < b[n - i + j]) {
                ok = false;
            }
        }
        if (ok) {
            ansA = i;
            break;
        }
    }

    printf("%d %d\n", ansA, ansB);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        printf("Case #%d: ", caseId);
        solve();
    }
}
