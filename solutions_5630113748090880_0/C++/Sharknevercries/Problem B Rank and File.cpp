#include<bits\stdc++.h>
using namespace std;
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        int n, Q[2505] = { 0 };
        vector<int> ans;
        scanf("%d", &n);
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int num;
                scanf("%d", &num);
                Q[num]++;
            }
        }
        printf("Case #%d:", c++);
        for (int i = 0; i <= 2500; i++)
            if (Q[i] % 2 == 1)
                printf(" %d", i);
        putchar('\n');        
    }
    return 0;
}