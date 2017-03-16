#include <cstdio>

int n, s, p, t, ans;

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int test_cases;
    scanf("%d", &test_cases);
    for (int test_num = 1; test_num <= test_cases; test_num++) {
        ans = 0;
        scanf("%d%d%d", &n, &s, &p);
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            if (t < 2) {
                if (p > t) continue;
                else ans++;
            } else if (t >= p*3-2) {
                ans++;
            } else if (s && t >= p*3-4) {
                ans++;
                s--;
            }
        }
        
        printf("Case #%d: %d\n", test_num, ans);
    }
}