#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 128;

int solve() {
    int size[maxn];
    bool mark[maxn];
    int A, n;

    scanf("%d%d", &A, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &size[i]);
    }

    sort(size, size + n);

    int ans = 1 << 29;

    for (int j = 0; j <= n; ++j) {
        int cnt = n - j;
        long long current = A;
        for (int i = 0; i < j; ++i) {
            mark[i] = false;
        }
        for (int i = 0; i < j; ++i) {
            int k = j - 1;
            while (k >= 0) {
                if (!mark[k] && size[k] < current) {
                    break;
                }
                k--;
            }
            if (k < 0) {
                if (current == 1) {
                    cnt = 1 << 30;
                    break;
                }
                current += current - 1;
                cnt++;
                i--;
            } else {
                mark[k] = true;
                current += size[k];
            }
        }
        ans = min(ans, cnt);
    }
    
    return ans;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testID = 1; testID <= testCount; testID++) {
        cerr << testID << endl;
        printf("Case #%d: %d\n", testID, solve());
        fflush(stdout);
    }
    fclose(stdout);
}
