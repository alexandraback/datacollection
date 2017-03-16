#include <bits/stdc++.h>

using namespace std;

const int N = 18;

char scoreC[N + 5], bestScoreC[N + 5], diffC[N + 5];
char scoreJ[N + 5], bestScoreJ[N + 5], diffJ[N + 5];
int l;

bool bigger(char *a, char *b) {
    for (int i = 1; i <= l; i++) {
        if (a[i] > b[i]) {
            return true;
        } else if (a[i] < b[i]) {
            return false;
        }
    }
    return false;
}

void getDiff() {
    if (bigger(scoreC, scoreJ)) {
        int c = 0;
        for (int i = l; i >= 1; i--) {
            diffC[i] = scoreC[i] - scoreJ[i] - c;
            c = 0;
            if (diffC[i] < 0) {
                diffC[i] += 10;
                c = 1;
            }
        }
    } else {
        int c = 0;
        for (int i = l; i >= 1; i--) {
            diffC[i] = scoreJ[i] - scoreC[i] - c;
            c = 0;
            if (diffC[i] < 0) {
                diffC[i] += 10;
                c = 1;
            }
        }
    }

    if (bigger(bestScoreC, bestScoreJ)) {
        int c = 0;
        for (int i = l; i >= 1; i--) {
            diffJ[i] = bestScoreC[i] - bestScoreJ[i] - c;
            c = 0;
            if (diffJ[i] < 0) {
                diffJ[i] += 10;
                c = 1;
            }
        }
    } else {
        int c = 0;
        for (int i = l; i >= 1; i--) {
            diffJ[i] = bestScoreJ[i] - bestScoreC[i] - c;
            c = 0;
            if (diffJ[i] < 0) {
                diffJ[i] += 10;
                c = 1;
            }
        }
    }
}

bool isBetter() {

    getDiff();

    for (int i = 1; i <= l; i++) {
        if (diffC[i] < diffJ[i]) {
            return true;
        } else if (diffC[i] > diffJ[i]) {
            return false;
        }
    }

    for (int i = 1; i <= l; i++) {
        if (scoreC[i] < bestScoreC[i] || (scoreC[i] == bestScoreC[i] && scoreJ[i] < bestScoreJ[i])) {
            return true;
        }
        if (scoreC[i] > bestScoreC[i] || (scoreC[i] == bestScoreC[i] && scoreJ[i] > bestScoreJ[i])) {
            return false;
        }

    }
    return false;
}

void updateResult() {
    if (isBetter()) {
        for (int i = 1; i <= l; i++) {
            bestScoreC[i] = scoreC[i];
            bestScoreJ[i] = scoreJ[i];
        }
    }
}

void backtrack(int pos, int cmp) {
    if (pos == l + 1) {
        updateResult();
        return;
    }

    if (scoreC[pos] != '?' && scoreJ[pos] != '?') {
        if (cmp == 0) {
            if (scoreC[pos] < scoreJ[pos]) {
                cmp = -1;
            } else if (scoreC[pos] > scoreJ[pos]) {
                cmp = 1;
            }
        }
        backtrack(pos + 1, cmp);
        return;
    }
    if (scoreC[pos] == '?' && scoreJ[pos] != '?') {
        if (cmp < 0) {
            scoreC[pos] = '9';
            backtrack(pos + 1, cmp);
            scoreC[pos] = '?';
        } else if (cmp > 0) {
            scoreC[pos] = '0';
            backtrack(pos + 1, cmp);
            scoreC[pos] = '?';
        } else {
            if (scoreJ[pos] > '0') {
                scoreC[pos] = scoreJ[pos] - 1;
                backtrack(pos + 1, -1);
                scoreC[pos] = '?';
            }
            if (scoreJ[pos] < '9') {
                scoreC[pos] = scoreJ[pos] + 1;
                backtrack(pos + 1, 1);
                scoreC[pos] = '?';
            }
            scoreC[pos] = scoreJ[pos];
            backtrack(pos + 1, 0);
            scoreC[pos] = '?';
        }
        return;
    }
    if (scoreC[pos] != '?' && scoreJ[pos] == '?') {
        if (cmp < 0) {
            scoreJ[pos] = '0';
            backtrack(pos + 1, cmp);
            scoreJ[pos] = '?';
        } else if (cmp > 0) {
            scoreJ[pos] = '9';
            backtrack(pos + 1, cmp);
            scoreJ[pos] = '?';
        } else {
            if (scoreC[pos] > '0') {
                scoreJ[pos] = scoreC[pos] - 1;
                backtrack(pos + 1, 1);
                scoreJ[pos] = '?';
            }
            if (scoreC[pos] < '9') {
                scoreJ[pos] = scoreC[pos] + 1;
                backtrack(pos + 1, -1);
                scoreJ[pos] = '?';
            }
            scoreJ[pos] = scoreC[pos];
            backtrack(pos + 1, 0);
            scoreJ[pos] = '?';
        }
        return;
    }
    if (scoreC[pos] == '?' && scoreJ[pos] == '?') {
        if (cmp < 0) {
            scoreC[pos] = '9';
            scoreJ[pos] = '0';
            backtrack(pos + 1, cmp);
            scoreC[pos] = '?';
            scoreJ[pos] = '?';
        } else if (cmp > 0) {
            scoreC[pos] = '0';
            scoreJ[pos] = '9';
            backtrack(pos + 1, cmp);
            scoreC[pos] = '?';
            scoreJ[pos] = '?';
        } else {
            scoreC[pos] = '0';
            scoreJ[pos] = '1';
            backtrack(pos + 1, -1);
            scoreC[pos] = '?';
            scoreJ[pos] = '?';

            scoreC[pos] = '1';
            scoreJ[pos] = '0';
            backtrack(pos + 1, 1);
            scoreC[pos] = '?';
            scoreJ[pos] = '?';

            scoreC[pos] = '0';
            scoreJ[pos] = '0';
            backtrack(pos + 1, 0);
            scoreC[pos] = '?';
            scoreJ[pos] = '?';
        }
    }

}

void test() {
    scanf("%s %s", scoreC + 1, scoreJ + 1);
    l = strlen(scoreC + 1);
    for (int i = 1; i <= l; i++) {
        bestScoreC[i] = '0';
        bestScoreJ[i] = '9';
    }
    bestScoreC[l + 1] = bestScoreJ[l + 1] = 0;
    backtrack(1, 0);
    printf("%s %s\n", bestScoreC + 1, bestScoreJ + 1);
}

int main() {

    int tests;
    scanf("%d", &tests);
    for (int t = 1; t <= tests; t++) {
        printf("Case #%d: ", t);
        test();
    }

    return 0;
}