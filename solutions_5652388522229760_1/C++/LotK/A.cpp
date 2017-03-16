#include <cstdio>

int sol(int input) {
    if (input == 0) return 0;
    int used[10] = {0}, count = 0;
    long long run = 1;
    while(count < 10) {
        long long temp = run*input;
        while(temp > 0) {
            if (used[temp%10] == 0) {
                used[temp%10] = 1;
                count++;
                if (count == 10) return run*input;
            }
            temp /= 10;
        }
        run++;
    }
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int tt;
    scanf("%d", &tt);
    for (int t=0 ; t<tt ; t++) {
        int input, ans = 0;
        scanf("%d", &input);
        ans = sol(input);
        if (ans == 0) {
            printf("Case #%d: INSOMNIA\n", t+1);
        }
        else {
            printf("Case #%d: %d\n", t+1, ans);
        }
    }
}
