#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50;

int T;
char a[N], b[N];
vector < pair <unsigned long long, pair <string, string> > > ans;

unsigned long long dif(string &A, string &B) {
    int n = A.size();
    unsigned long long d = 1;
    unsigned long long v_a = 0;
    unsigned long long v_b = 0;
    for (int i = n - 1; i >= 0; i--) {
        v_a += d * (A[i] - '0');
        v_b += d * (B[i] - '0');
        d *= 10;
    }
    if (v_a > v_b) {
        return v_a - v_b;
    } else {
        return v_b - v_a;
    }
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%s %s", a, b);
        int n = strlen(a);
        for (int i = 0; i < n; i++) {
            for (int l = 0; l < 10; l++) {
                for (int r = l + 1; r < 10; r++) {
                    bool flag = true;
                    if (a[i] != '?' && a[i] != (char) ('0' + l)) {
                        flag = false;
                    }
                    if (b[i] != '?' && b[i] != (char) ('0' + r)) {
                        flag = false;
                    }
                    for (int j = i - 1; j >= 0; j--) {
                        if (a[j] != '?' && b[j] != '?' && a[j] != b[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        continue;
                    }
                    string A = "";
                    string B = "";
                    for (int k = 0; k < i; k++) {
                        if (a[k] == '?' && b[k] == '?') {
                            A += '0';
                            B += '0';
                        } else if (a[k] == '?') {
                            A += b[k];
                            B += b[k];
                        } else {
                            A += a[k];
                            B += a[k];
                        }
                    }
                    A += (char) ('0' + l);
                    B += (char) ('0' + r);
                    for (int k = i + 1; k < n; k++) {
                        if (a[k] == '?') {
                            A += '9';
                        } else {
                            A += a[k];
                        }
                    }
                    for (int k = i + 1; k < n; k++) {
                        if (b[k] == '?') {
                            B += '0';
                        } else {
                            B += b[k];
                        }
                    }
                    if (flag) {
                        ans.push_back({dif(A, B), {A, B}});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int l = 0; l < 10; l++) {
                for (int r = l - 1; r >= 0; r--) {
                    bool flag = true;
                    if (a[i] != '?' && a[i] != (char) ('0' + l)) {
                        flag = false;
                    }
                    if (b[i] != '?' && b[i] != (char) ('0' + r)) {
                        flag = false;
                    }
                    for (int k = i - 1; k >= 0; k--) {
                        if (a[k] != '?' && b[k] != '?' && a[k] != b[k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        continue;
                    }
                    string A = "";
                    string B = "";
                    for (int k = 0; k < i; k++) {
                        if (a[k] == '?' && b[k] == '?') {
                            A += '0';
                            B += '0';
                        } else if (a[k] == '?') {
                            A += b[k];
                            B += b[k];
                        } else {
                            A += a[k];
                            B += a[k];
                        }
                    }
                    A += (char) ('0' + l);
                    B += (char) ('0' + r);
                    for (int k = i + 1; k < n; k++) {
                        if (a[k] == '?') {
                            A += '0';
                        } else {
                            A += a[k];
                        }
                    }
                    for (int k = i + 1; k < n; k++) {
                        if (b[k] == '?') {
                            B += '9';
                        } else {
                            B += b[k];
                        }
                    }
                    if (flag) {
                        ans.push_back({dif(A, B), {A, B}});
                    }
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == '?' && b[i] == '?') {
                a[i] = '0';
                b[i] = '0';
            } else if (a[i] == '?') {
                a[i] = b[i];
            } else if (b[i] == '?') {
                b[i] = a[i];
            } else if (a[i] != b[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.push_back({0, {string(a), string(b)}});
        }
        sort(ans.begin(), ans.end());
        printf("Case #%d: %s %s\n", t, ans[0].second.first.c_str(), ans[0].second.second.c_str());
        ans.clear();
    }

    return 0;

}
