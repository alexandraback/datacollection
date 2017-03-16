#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
char s[120];

void flip(int n)
{
    reverse(s, s + n);
    for (int i = 0; i < n; ++i) s[i] = "+-"[s[i] == '+'];
}

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        scanf("%s", s);
        n = strlen(s);
        int ans = 0;
        for (;;) {
            int i = n - 1;
            while (s[i] == '+') --i;
            if (i == -1) break;
            if (s[0] == '+') {
                ++ans;
                for (int i = 0; s[i] == '+'; ++i) s[i] = '-';
            }
            ++ans;
            flip(i + 1);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
