#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int NMAX = 112;
int tests, result, N;
bool A[NMAX];
string s;

bool allSolved() {
    for (int i = 1; i <= N; i++) {
        if (!A[i]) {
            return false;
        }
    }

    return true;
}

void reverse(int pos) {
    for (int i = 1; i <= pos; i++) {
        A[i] ^= 1;
    }

    for (int i = 1; i <= pos / 2; i++) {
        swap(A[i], A[pos + 1 - i]);
    }
}

void go(int pos) {
    if (A[1]) {
        // will stop before 1 given condition above
        int revPos = pos;
        while (!A[revPos]) {
            revPos--;
        }

        reverse(revPos);
        result++;
    }

    reverse(pos);
    result++;
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);

        cin >> s;
        N = s.size();
        for (int i = 1; i <= N; i++) {
            A[i] = s[i - 1] == '+';
        }

        result = 0;
        while (!allSolved()) {
            int lastBad = N;
            while (A[lastBad]) {
                lastBad--;
            }

            go(lastBad);
        }

        printf("%d\n", result);
    }
    return 0;
}