#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int times = 0; times < t; times++) {
        int n;
        scanf("%d", &n);

        char sa[21];
        char sb[21];

        map<string,int> mf;
        map<string,int> ms;
        vector<pair<string,string>> vct;
        for (int i = 0; i < n; i++) {
            scanf("%s%s", sa, sb);
            vct.emplace_back(sa, sb);
            mf[sa] += 1;
            ms[sb] += 1;
        }

        vector<bool> used(n, false);
        set<string> sf;
        set<string> ss;
        for (int i = 0; i < n; i++) {
            if (mf[vct[i].first] == 1 or ms[vct[i].second] == 1) {
                sf.emplace(vct[i].first);
                ss.emplace(vct[i].second);
                used[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (sf.count(vct[i].first) == 0 and ss.count(vct[i].second) == 0) {
                sf.emplace(vct[i].first);
                ss.emplace(vct[i].second);
                used[i] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (used[i] == false) {
                if (sf.count(vct[i].first) == 1 and ss.count(vct[i].second) == 1) {
                    cnt += 1;
                }
                sf.emplace(vct[i].first);
                ss.emplace(vct[i].second);
            }
        }
        printf("Case #%d: %d\n", times+1, cnt);
    }
}
