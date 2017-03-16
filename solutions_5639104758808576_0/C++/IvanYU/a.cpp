#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int T, n, ans, now;
    char s[2000];
    scanf("%d", &T);

    for (int _T = 1; _T <= T; _T++)
    {
        scanf("%d", &n);
        scanf("%s", s);

        ans = 0;
        now = s[0] - '0';

        for (int i = 1; i < n + 1; ++i)
        {
            if (s[i] == '0')
                continue;

            if (now < i)
            {
                ans += i - now;
                now = i;
            }
            now += s[i] - '0';
        }

        printf("Case #%d: %d\n", _T, ans);
    }



}