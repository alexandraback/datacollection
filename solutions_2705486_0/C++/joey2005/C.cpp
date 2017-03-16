#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 521196 + 10;
const int tooManyWrong = -1;
const int perfectMatched = -2;
const int inf = 1 << 29;

struct State {
    int st, en, cnt;

    State(int st, int en, int cnt): st(st), en(en), cnt(cnt) { }
    State() {
    }
} wrongPos[maxn][52];

string words[maxn]; 
int wordCount = 0;

char s[4005];
int dp[4005][4005];

void solve() {
    scanf("%s", s);
    int L = strlen(s);

    for (int j = 0; j < wordCount; ++j) {
        int len = words[j].size();
        for (int i = 0; i + len <= L; ++i) {
            int st = -2, en = -2, cnt = 0;
            for (int at = 0; at < len; ++at) {
                if (words[j][at] != s[i + at]) {
                    if (st == -2) {
                        st = at;
                    } else if (at - en < 5) {
                        st = -1;
                        break;
                    }
                    en = at;
                    cnt++;
                }
            }
            wrongPos[j][i] = State(st, en, cnt);
        }
    }

    for (int i = 1; i <= L + 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[1][0] = 0;
    for (int i = 1; i <= L; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] < inf) {
                for (int k = 0; k < wordCount; ++k) {
                    int ni = i + words[k].size();
                    State &current = wrongPos[k][i - 1];
                    if (ni <= L + 1 && current.st != tooManyWrong) {
                        if (j != 0 && current.st != perfectMatched && current.st + i - j < 5) {
                            continue;
                        }
                        int nj = j;
                        if (current.st != perfectMatched) {
                            nj = current.st + i;
                        }
                        dp[ni][nj] = min(dp[ni][nj], dp[i][j] + current.cnt);
                    }
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= L + 1; ++i) {
        ans = min(ans, dp[L + 1][i]);
    }

    printf("%d\n", ans);
}

int main() {
    freopen("garbled_email_dictionary.txt", "r", stdin);
    char buf[30];
    while (gets(buf)) {
        words[wordCount++] = buf;
    }
    fclose(stdin);
    cerr << wordCount << endl;

    freopen("C-small-attempt2.in", "r", stdin);
    //freopen("C-small-attempt1.in", "r", stdin);
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testID = 1; testID <= testCount; ++testID) {
        cerr << testID << endl;
        printf("Case #%d: ", testID);
        solve();
        fflush(stdout);
    }

    fclose(stdout);
}
