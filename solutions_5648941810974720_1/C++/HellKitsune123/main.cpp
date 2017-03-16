#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt;
const string s[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const char z[11] = "ZWXSGTROVI";
const int ord[10] = {0, 2, 6, 7, 8, 3, 4, 1, 5, 9};
int cnt[26];
char q[2005];
int ans[10];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        printf("Case #%d: ", test);
        scanf("%s", q);
        int len = strlen(q);
        REP(i, 26) cnt[i] = 0;
        REP(i, len) ++cnt[q[i] - 'A'];
        REP(i, 10) ans[i] = 0;
        REP(i, 10) {
            int ind = ord[i];
            ans[ind] = cnt[z[i] - 'A'];
            for (char c : s[ind]) {
                cnt[c - 'A'] -= ans[ind];
            }
        }
        REP(i, 26) assert(cnt[i] == 0);
        REP(i, 10) REP(j, ans[i]) printf("%d", i);
        printf("\n");
    }
    return 0;
}
