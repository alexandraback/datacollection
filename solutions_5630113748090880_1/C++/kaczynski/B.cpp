#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

int T, n, a, cnt[3000];
vector <int> ans;

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int x = 1; x <= 2500; x++) {
            cnt[x] = 0;
        }
        for (int i = 1; i < 2 * n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a);
                cnt[a]++;
            }
        }
        for (int x = 1; x <= 2500; x++) {
            if (cnt[x] % 2 == 1) {
                ans.push_back(x);
            }
        }
        printf("Case #%d:", t);
        for (int i = 0; i < ans.size(); i++) {
            printf(" %d", ans[i]);
        }
        puts("");
        ans.clear();
    }

    return 0;

}
