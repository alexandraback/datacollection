#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1100000;
typedef long long ll;

char line[MAXN];
int n, m;
ll dp[MAXN];
bool vowels[256];

int main()
{
    int T;
    int cn = 0;

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    memset(vowels, false, sizeof(vowels));
    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;

    scanf("%d", &T);

    while (T--) {
        scanf("%s%d", line + 1, &m);
        n = strlen(line + 1);

        dp[0] = 0;

        int m_len = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vowels[line[i]]) {
                m_len = 0;
            } else {
                m_len++;
            }
            if (m_len >= m) {
                dp[i] = i - m + 1;
            } else {
                dp[i] = dp[i - 1];
            }
            ans += dp[i];
        }
        printf("Case #%d: %I64d\n", ++cn, ans);

    }

    return 0;
}
