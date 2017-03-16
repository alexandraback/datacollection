#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAXL = 18;
const int INF = 1<<30;

char str[2][MAXL+2];

pair<int, pair<string, string>> ans;

int abs(int n) { return n >= 0 ? n : -n; }

void dfs(int c, int a, int b) {
    int i = c&1;
    int j = c>>1;

    if (str[i][j] == '\0') {
        int d = abs(a-b);
        if (ans.first >= d)
            ans = min(ans, {d, {str[0], str[1]}});
        return;
    }

    if (str[i][j] == '?') {
        for (int k = 0; k < 10; ++k) {
            str[i][j] = k + '0';

            int ap = a, bp = b;
            if (i == 0)
                ap = ap*10 + k;
            else
                bp = bp*10 + k;

            dfs(c+1, ap, bp);
        }

        str[i][j] = '?';
    } else {
        int ap = a, bp = b;
        if (i == 0)
            ap = ap*10 + str[i][j]-'0';
        else
            bp = bp*10 + str[i][j]-'0';

        dfs(c+1, ap, bp);
    }
}

void jizz() {
    scanf("%s%s", str[0], str[1]);

    char strp[2][MAXL+2];
    strcpy(strp[0], str[0]);
    strcpy(strp[1], str[1]);

    ans.first = INF;
    dfs(0, 0, 0);

    printf("%s %s", ans.second.first.c_str(), ans.second.second.c_str());
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        jizz();
        puts("");
    }
}
