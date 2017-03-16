#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int a, b;

int main() {
    /*freopen("D:\\C-small-attempt0.in", "r", stdin);
    freopen("D:\\C-small-attempt0.out", "w", stdout);*/
    int tc, c = 0;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &a, &b);
        int tot = 0;
        for (int i = a; i <= b; i++) {
            static char bit[10];
            int sz = 0, su = i;
            while (su) {
                bit[sz++] = su % 10;
                su /= 10;
            }
            set<int> cont;
            for (int t = 0; t < sz; t++) {
                int arr = 0;
                for (int j = 0; j < sz; j++)
                    arr = (arr << 3)+(arr << 1) + bit[(t + sz - 1 - j) % sz];
                if (arr <= i || arr < a || arr > b)
                    continue;
                if (cont.find(arr) == cont.end()) {
                    cont.insert(arr);
                    ++tot;
                }
            }
        }
        printf("Case #%d: %d\n", ++c, tot);
    }
    return 0;
}