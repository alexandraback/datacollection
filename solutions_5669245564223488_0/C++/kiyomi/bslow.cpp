#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

#define sz(A) (int) A.size()

using namespace std;

int T, n, dp[1 << 11][11], msk[1 << 20];
char str[110][110];

vector < pair <char, int> > bip(int idx) {
    int len = strlen(str[idx]);
    vector < pair <char, int> > vv;
    for (int i = 0; i < len;) {
        int ci = 0;
        char c = str[idx][i];
        while (i < len && c == str[idx][i]) {
            i++;
            ci++;
        }
        vv.push_back(make_pair(c, ci));
    }
    //if (vv.size() > 2)
      //  vv.clear();
    return vv;
}

int solve() {
    //sort(str, str + n);
    memset(dp, 0, sizeof dp);
    vector < vector < pair <char, int> > > vi;
    for (int i = 0; i < n; i++)
        vi.push_back(bip(i));
    for (int i = 0; i < n; i++)
        if (vi[i].size() != 0)
            dp[1 << i][i] = 1;
    for (int i = 0; i < (1 << n); i++) {
        msk[i] = 0;
        for (int j = 0; j < n; j++)
            if ((i & (1 << j)) != 0)
                for (int k = 0; str[j][k] != '\0'; k++)
                    msk[i] |= 1 << (str[j][k] - 'a');
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int last = 0; last < n; last++) {
            if (dp[i][last] != 0) {
                //printf("%d %d %d\n", i, last, dp[i][last]);
                for (int next = 0; next < n; next++) {
                    if ((i & (1 << next)) == 0 && vi[next].size() != 0) {
                        char c1 = vi[last][sz(vi[last]) - 1].first;
                        char c2 = vi[next][0].first;
                        int msk2 = msk[i];
                        int msk3 = msk[1 << next];
                        if ((msk2 & msk3) == 0)
                            dp[i | (1 << next)][next] += dp[i][last];
                        else {
                            msk3 ^= (1 << (c2-'a'));
                            if (c1 == c2 && (msk2 & msk3) == 0)
                                dp[i | (1 << next)][next] += dp[i][last];
                        }
                    }
                }
            }
        }
    }
    int lim = (1 << n) - 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += dp[lim][i];
    return ans;
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%s", str[i]);
        printf("Case #%d: %d\n", t, solve());
    }

    return 0;

}
