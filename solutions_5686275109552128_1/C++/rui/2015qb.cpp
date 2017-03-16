#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int tt, d, p[1100], mi[1100], b[1100], w[1100];
int main() {
    mi[1] = 1;
    for (int i = 2; i <= 1000; ++i) {
        mi[i] = i;
        for (int j = 1; j < i; ++j) {
            int tmp = i - j + w[j];
            if (mi[j] > tmp)
                tmp = mi[j];
            if (tmp + 1 < mi[i]) {
                mi[i] = tmp + 1;
                b[i] = j;
                w[i] = w[j] + 1;
            }
        }
        for (int j = 1; j < i; ++j) {
            if (j + mi[i-j] < mi[i]) {
                mi[i] = j + mi[i-j];
                printf("%d\n", i);
            }
        }
    }
    //printf("%d %d %d %d\n", mi[9], b[9], mi[5], b[5]);
    scanf("%d", &tt);
    for (int t = 1; t <= tt; ++t) {
        scanf("%d", &d);
        int ans = 1000;
        //priority_queue<int, vector<int>, greater<int> > pp;
        int mm = 0;
        for (int i = 0; i < d; ++i) {
            scanf("%d", &p[i]);
            if (mm < p[i])
                mm = p[i];
        }
        for (int ww = 1; ww <= mm; ++ww) {
            priority_queue<int> pp;
            for (int i = 0; i < d; ++i)
                pp.push(p[i]);
            int mark = false;
            int j = 0;
            for (; j < mm; ++j) {
                int top = pp.top();
                //printf("j %d top %d %d %d\n", j, top, mi[top], b[top]);
                pp.pop();
                if (top + j < ans)
                    ans = top + j;
                if (top <= 1) {
                    mark = true;
                    break;
                }
                //if (ww - j - 1 <= 0)
                //    break;
                int tmp = b[top];
                tmp = ww - j -1;
                tmp = ww;
                pp.push(top-tmp);
                pp.push(tmp);
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
