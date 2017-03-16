#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int t;
char s[1000 * 1000 + 100];
int n;

bool check(char c)
{
    if (c != 'a' && c != 'e' && c != 'o' && c != 'i' && c != 'u')
        return true;
    else
        return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long ans = 0;
        scanf("%s %d\n", &s, &n);
        int len = strlen(s);
        int l = 0, r = -1, now = 0;
        while(l < len)
        {
            while(r < len && now < n)
            {
                if (check(s[r + 1]))
                    now++;
                else
                    now = 0;
                r++;
            }

            if (now >= n)
                ans += (len - r);

            if (r - l + 1 <= n)
                now = min(now, now - 1);
            l++;
        }

        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
