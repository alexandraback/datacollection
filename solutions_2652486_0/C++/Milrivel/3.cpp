#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int mul[10];
int r, n, m, k;

int judge(int a, int b, int c) {
    set<int> mp;
    mp.insert(1);
    mp.insert(a);
    mp.insert(b);
    mp.insert(c);
    mp.insert(a * b);
    mp.insert(b * c);
    mp.insert(c * a);
    mp.insert(a * b * c);
    for (int i = 0; i < k; i++) {
        if (mp.find(mul[i]) == mp.end()) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("dataout.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #%d:\n", cases);
        for (int cas = 0; cas < r; cas++) {
            for (int i = 0; i < k; i++) {
                scanf("%d", &mul[i]);
            }
            int mark = 0;
            for (int a = 2; a <= m; a++) {
                for (int b = 2; b <= m; b++) {
                    for (int c = 2; c <= m; c++) {
                        if (judge(a, b, c)) {
                            printf("%d%d%d\n", a, b, c);
                            mark = 1;
                            break;
                        }
                    }
                    if (mark) break;
                }
                if (mark) break;
            }
            if (!mark) {
                printf("222\n");
            }
        }
    }
    return 0;
}
