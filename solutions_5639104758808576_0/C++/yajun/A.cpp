# include <stdio.h>

const int maxn = 1005;

int S;
char s[maxn];

# define testin freopen("A-small-attempt0.in", "r", stdin)
# define testout freopen("out.txt", "w", stdout)

int main()
{
    testin;
    testout;

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%d%s", &S, s);
        int ans = 0;
        int sum = 0;
        for (int i = 0; s[i]; ++i) {
            int t = s[i] - '0';
            if (t != 0) {
                if (sum < i) {
                    ans += i - sum;
                    sum = i;
                }
                sum += t;
            }
        }
        printf("Case #%d: %d\n", ica, ans);
    }

    return 0;
}
