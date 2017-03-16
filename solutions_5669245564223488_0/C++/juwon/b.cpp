#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

int n;
vector<string> t;

int chk(string& s) {
    int c[26] = {0};
    int i = 0;
    int len = sz(s);
    while (i < len) {
        int ch = s[i] - 'a';
        if (c[ch]) {
            return 0;
        }
        c[ch] = 1;
        while (i < len && s[i] - 'a' == ch) {
            i++;
        }
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ", cs);
        scanf("%d", &n);
        t.clear();
        int p[100];
        for (int i = 0; i < n; ++i) {
            char tmp[200];
            scanf("%s", tmp);
            t.push_back(tmp);
            p[i] = i;
        }
        int ans = 0;
        do {
            string tmp;
            for (int i = 0; i < n; ++i) {
                tmp += t[p[i]];
            }
            if (chk(tmp)) {
                ans++;
            }
        } while(next_permutation(p, p + n));
        printf("%d\n", ans);

    }
    return 0;
}


