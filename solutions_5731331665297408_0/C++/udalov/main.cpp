#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)

char tmp[100];
int p[8];

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        int n, m;
        scanf("%d%d\n", &n, &m);
        vector<string> zip;
        forn(i, n) scanf("%s\n", tmp), zip.push_back(tmp);
        vector<vector<int>> a;
        forn(i, n) a.push_back(vector<int>(n));
        forn(___, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            a[x][y] = 1;
            a[y][x] = 1;
        }

        forn(i, n) p[i] = i;
        string ans = ":(";
        vector<int> st;
        st.reserve(10);
        do {
            /*
            printf("try");
            forn(i, n) printf(" %d", p[i]); printf("\n");
            forn(i, n) printf("%s\n", zip[p[i]].c_str());
            */
            st.clear();
            st.push_back(p[0]);
            bool bad = false;
            for (int i = 1; i < n; i++) {
                while (!st.empty() && !a[st.back()][p[i]]) st.pop_back();
                if (st.empty()) { bad = true; break; }
                st.push_back(p[i]);
            }
            if (bad) continue;
            string cur = "";
            forn(i, n) cur += zip[p[i]];
            if (cur < ans) ans = cur;
            // printf("cur %s\n", cur.c_str());
        } while (next_permutation(p, p + n));

        printf("Case #%d: %s\n", _+1, ans.c_str());
    }
}
