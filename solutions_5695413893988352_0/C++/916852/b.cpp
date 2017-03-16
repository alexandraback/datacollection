#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long

char C[100], J[100];
vector<LL> A, B;
int n;

void dfs(char *s, vector<LL> &v, int pos, LL val) {
    if (pos == n) {
        v.push_back(val);
        return ;
    }
    if (s[pos] == '?') {
        for (int i = 0; i <= 9; ++i) {
            dfs(s, v, pos + 1, val * 10 + i);
        }
    } else dfs(s, v, pos + 1, val * 10 + s[pos] - '0');
}

void init() {
    A.clear();
    B.clear();
    n = strlen(C);
    dfs(C, A, 0, 0);
    dfs(J, B, 0, 0);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

string get(LL x) {
    char s[100];
    string ret;
    snprintf(s, sizeof(s), "%lld", x);
    ret = s;
    while (ret.size() != n) ret = "0" + ret;
    return ret;
}

void solve(string &a, string &b) {
    LL ans = -1;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            LL cur = A[i] - B[j];
            if (cur < 0) cur = -cur;
            if (ans == -1 || ans > cur) {
                ans = cur;
                a = get(A[i]);
                b = get(B[j]);
            }
        }
    }
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b_out.txt", "w", stdout);

    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", C, J);
        init();
        string a, b;
        solve(a, b);
        printf("Case #%d: %s %s\n", ++cas, a.c_str(), b.c_str());
    }
    return 0;
}
