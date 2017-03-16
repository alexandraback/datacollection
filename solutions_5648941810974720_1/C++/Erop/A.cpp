#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


char keyLetter[] = "ZOWTUFXSGI";
int order[] = {0, 2, 4, 5, 6, 7, 8, 9, 1, 3};
char spell[10][10] = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
};

char buff[50000];
int cnt[2500];
int ans[100];
void solve() {
    scanf("%s", &buff);
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; buff[i]; ++i) {
        ++cnt[buff[i]];
    }
    for (int i = 0; i < 10; ++i) {
        int d = order[i];
        char key = keyLetter[d];
        ans[d] = cnt[key];
        for (int j = 0; spell[d][j]; ++j) {
            char c = spell[d][j];
            cnt[c] -= ans[d];
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < ans[i]; ++j) {
            printf("%d", i);
        }
    }
    puts("");
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}