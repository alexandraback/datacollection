#include <stdio.h>

#include <algorithm>

using namespace std;

const int N = 101;
int score[N];
int n, s, p;

int main() {
    int cas;
    scanf("%d", &cas);
    for (int ic = 1;ic <= cas;ic++) {
        scanf("%d%d%d", &n, &s, &p);
        for (int i = 0;i < n;i++) {
            scanf("%d", &score[i]);
        }
        sort(score, score+n);
        int ans = 0;
        for (int i = 0;i < n;i++) {
            if (score[i] >= 3*p) ans++;
            else if (score[i] >= 3*p-2 && p-1 >= 0) ans++;
            else if (score[i] >= 3*p-4 && p-2 >= 0) {
                if (s > 0) {
                    ans++;
                    s--;
                }
            }
        }
        printf("Case #%d: %d\n", ic, ans);
    }
    return 0;
}
