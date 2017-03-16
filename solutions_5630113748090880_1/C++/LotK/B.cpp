#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int tt, n, a;
    scanf("%d", &tt);
    int count[3000];
    int ans[100];
    for (int t=0 ; t<tt ; t++) {
        scanf("%d", &n);
        for (int i=0 ; i<3000 ; i++) {
            count[i] = 0;
        }
        for (int i=0 ; i<2*n-1 ; i++) {
            for (int j=0 ; j<n ; j++) {
                scanf("%d", &a);
                count[a]++;
            }
        }
        int index = 0;
        for (int i=0 ; i<3000 ; i++) {
            if (count[i]%2 == 1) {
                ans[index++] = i;
            }
        }
        sort(ans, ans+index);

        printf("Case #%d:", t+1);
        for (int i=0 ; i<index ; i++) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
}
