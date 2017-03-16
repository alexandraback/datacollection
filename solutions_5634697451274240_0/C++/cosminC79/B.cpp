#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int NMAX = 12;
int tests, result, N;
bool taken[NMAX], A[NMAX];
string s;
vector<int> currSol, sol;

inline void update(int k) {
    bool allOk = true;
    for (int i = 1; i <= N; i++) {
        allOk &= A[i];
    }

    if (allOk) {
        result = min(result, k);
        sol = currSol;
    }
}

inline void reverse(int k) {
    for (int i = 1; i <= k; i++) {
        A[i] ^= 1;
    }
    for (int i = 1; i <= k / 2; i++) {
        swap(A[i], A[k + 1 - i]);
    }
}

void back(int k) {
    update(k);

    if (k == N + 1 || k > result) {
        return ;
    }

    bool copyA[NMAX];
    for (int i = 1; i <= N; i++) {
        if (!taken[i]) {
            memcpy(copyA, A, sizeof(A));
            reverse(i);
            taken[i] = true;
            currSol.push_back(i);

            back(k + 1);
            
            memcpy(A, copyA, sizeof(copyA));
            taken[i] = false;
            currSol.pop_back();
        }
    }
}

void debugSol(string& s, vector<int>& sol) {
    for (int i = 1; i <= N; i++) {
        A[i] = (s[i - 1] == '+');
        printf("%d ", A[i]);
    }
    printf("\n");

    for (auto x: sol) {
        printf("APPLY %d\n", x);
        reverse(x);
        for (int i = 1; i <= N; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);

        cin >> s;
        N = s.size();
        result = NMAX;
        for (int i = 1; i <= N; i++) {
            A[i] = s[i - 1] == '+';
        }

        back(1);
        memset(taken, false, sizeof(taken));
        currSol.clear();

        printf("%d\n", result - 1);
        //debugSol(s, sol);
    }
    return 0;
}