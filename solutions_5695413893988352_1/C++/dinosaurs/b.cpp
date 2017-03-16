#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 22;

int T, n;
char a_s[MAXN], b_s[MAXN];
long long best_a, best_b;
long long min_diff = 1000000000000000000LL;

void solve(int i, long long a, long long b) {
    if (i == n) {
        long long cur_diff = abs(a - b);
        if (cur_diff < min_diff || (cur_diff == min_diff && a < best_a) || (cur_diff == min_diff && a == best_a && b < best_b)) {
            min_diff = cur_diff;
            best_a = a;
            best_b = b;
        }
        return;
    }

    if (a_s[i] != '?' && b_s[i] != '?') {
        solve(i + 1, a * 10 + (a_s[i] - '0'), b * 10 + (b_s[i] - '0'));
    } else if (a_s[i] == '?' && b_s[i] != '?') {
        if (a == b) {
            solve(i + 1, a * 10 + (b_s[i] - '0'), b * 10 + (b_s[i] - '0'));
            if (b_s[i] > '0') {
                solve(i + 1, a * 10 + (b_s[i] - '0' - 1), b * 10 + (b_s[i] - '0'));
            }
            if (b_s[i] < '9') {
                solve(i + 1, a * 10 + (b_s[i] - '0' + 1), b * 10 + (b_s[i] - '0'));
            }
        } else if (a < b) {
            solve(i + 1, a * 10 + 9, b * 10 + (b_s[i] - '0'));
        } else { // a > b
            solve(i + 1, a * 10, b * 10 + (b_s[i] - '0'));
        }
    } else if (a_s[i] != '?' && b_s[i] == '?') {
        if (a == b) {
            solve(i + 1, a * 10 + (a_s[i] - '0'), b * 10 + (a_s[i] - '0'));
            if (a_s[i] > '0') {
                solve(i + 1, a * 10 + (a_s[i] - '0'), b * 10 + (a_s[i] - '0' - 1));
            }
            if (a_s[i] < '9') {
                solve(i + 1, a * 10 + (a_s[i] - '0'), b * 10 + (a_s[i] - '0' + 1));
            }
        } else if (a < b) {
            solve(i + 1, a * 10 + (a_s[i] - '0'), b * 10);
        } else { // a > b
            solve(i + 1, a * 10 + (a_s[i] - '0'), b * 10 + 9);
        }
    } else { // both ?: try 00, 01, and 10
        if (a == b) {
            solve(i + 1, a * 10, b * 10);
            solve(i + 1, a * 10, b * 10 + 1);
            solve(i + 1, a * 10 + 1, b * 10);
        } else if (a < b) {
            solve(i + 1, a * 10 + 9, b * 10);
        } else { // a > b
            solve(i + 1, a * 10, b * 10 + 9);
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s", a_s);
        scanf("%s", b_s);
        n = strlen(a_s);

        min_diff = 1000000000000000000LL;
        solve(0, 0, 0);

        for (int i = n - 1; i >= 0; --i) {
            a_s[i] = '0' + (char) (best_a % 10);
            b_s[i] = '0' + (char) (best_b % 10);
            best_a /= 10;
            best_b /= 10;
        }
        printf("Case #%d: %s %s\n", t, a_s, b_s);
    }

    return 0;
}
