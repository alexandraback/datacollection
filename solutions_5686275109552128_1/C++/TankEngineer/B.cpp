#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n, a[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans = 1001;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            ans = max(ans, a[i]);
        }
        for (int i = 1; i <= ans; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                cnt += (a[j] - 1) / i;
            }
            ans = min(ans, cnt + i);
        }
        static int id = 0;
        printf("Case #%d: %d\n", ++id, ans);
    }
    return 0;
}
