#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int c, d, v; // c = 1
        vector<int> a;
        scanf("%d%d%d", &c, &d, &v);
        for (int i = 0; i < d; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (i == 0 && tmp != 1) a.push_back(1);
            a.push_back(tmp);
        }
        for (int k = 2; k <= v; k++) {
            bool flag = true;
            for (int m = 0; m < 1 << a.size(); m++) {
                int x = 0;
                for (int i = 0; i < a.size(); i++)
                    if ((1 << i) & m) x += a[i];
                if (x == k) { flag = false; break; }
            }
            if (flag) a.push_back(k);
        }
        int ans = a.size() - d;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
