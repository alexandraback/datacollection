#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[2005], ans[2005];
int cnt[300], tot;
string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string prt = "0123456789";

void init() {
    int n = strlen(s);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) cnt[s[i]]++;
}

bool gao(string &str, int pos, int cur) {
    for (int i = 0; i < str.size(); ++i) if (cnt[str[i]] == 0) return false;
    for (int i = 0; i < str.size(); ++i) cnt[str[i]]--;
    ans[cur] = prt[pos];
    tot -= str.size();
    return true;
}

void back(string &str, int pos) {
    for (int i = 0; i < str.size(); ++i) cnt[str[i]]++;
    tot += str.size();
}

bool found;

void dfs(int dep, int pos) {
    if (found) return ;
    if (tot == 0) {
        ans[dep] = '\0';
        found = true;
        return ;
    }
    for (int i = pos; i <= 9; ++i) {
        if (gao(num[i], i, dep)) {
            dfs(dep + 1, i);
            if (found) return ;
            back(num[i], i);
        }
    }
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("b_out.txt", "w", stdout);

    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        init();
        found = false;
        tot = strlen(s);
        dfs(0, 0);
        printf("Case #%d: %s\n", ++cas, ans);
    }
    return 0;
}
