#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("myAnswer_A.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int smax;
        string str;
        cin >> smax >> str;
        int cnt = 0, ans = 0;
        for (int i = 0; i <= smax; ++i)
        {
            if (cnt >= i)
                cnt += str[i] - '0';
            else
            {
                int tmp = i - cnt;
                ans += tmp;
                cnt += tmp + str[i] - '0' ;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
