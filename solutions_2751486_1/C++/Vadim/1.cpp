#include <cstdio>
#include <memory.h>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int ttt, k, ss[1111111];
long long ans;
string s;

        inline bool isvowel(char a)
        {
                if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
                return false;
        }

int main()
{
        freopen("1.in", "r", stdin);
        freopen("1.txt", "w", stdout);
        scanf("%d\n", &ttt);
        for (int test = 1; test<=ttt; test++)
        {
                printf("Case #%d: ", test);
                cin >> s >> k;
                int n = s.length();
                memset(ss, 0, sizeof(ss));
                for (int i = 0; i<n; i++)
                {
                        if (i) ss[i] = ss[i-1];
                        if (!isvowel(s[i])) ss[i]++; else ss[i] = 0;
                }
                int j = -1;
                ans = 0;
                for (int i = 0; i<n; i++)
                {
                        if (ss[i] >= k) j = i-k+1;
                        ans += j+1;
                }
                cout << ans << endl;
        }
        return 0;
}
