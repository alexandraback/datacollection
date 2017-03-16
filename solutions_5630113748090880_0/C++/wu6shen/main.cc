#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> ans;
int cnt[2501];
int main() {
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d:", ca++);
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        ans.clear();
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);
                cnt[x]++;
            }
        }
        for (int i = 1; i <= 2500; i++) if (cnt[i] & 1) ans.push_back(i);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
}
