#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


//#define ONLINE_JUDGE
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int smax;
        string s;
        cin >> smax >> s;
        int cur = 0, ans = 0;
        for (int j = 0; j <= smax; ++j)
        {
            if (cur < j) {
                ans += j - cur;
                cur = j;
            }
            cur += s[j] - '0';
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
