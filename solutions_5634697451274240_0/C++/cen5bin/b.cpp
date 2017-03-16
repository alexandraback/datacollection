#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define esp 1e-9
typedef long long LL;
const int MOD = 1e9+7;
char s[310];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int ans = 0;
        char last = '\0';
        for (int i = 0; s[i]; ++i) {
            if (s[i] != last) {
                last = s[i];
                ans++;
            }
        }
        if (last == '+') ans--;
        //int down = strlen(s) - 1;
        //int up = 0;
        //int ans = 0;
        //while (up <= down) {
        //    while (~down && s[down] == '+') down--;
        //    while (up <= down && s[up] == '+') up++;
        //    if (up <= down) {
        //        if (up > 0) {
        //            ans++;
        //            for (int i = 0; i < up; ++i) s[i] = '-';
        //        }
        //        for (int i = 0; i <= down / 2; ++i) {
        //            char tmp = s[i];
        //            s[i] = s[down-i] == '+' ? '-' : '+';
        //            s[down-i] = tmp == '+' ? '-' : '+';
        //        }
        //        ans++;
        //    }
        //}
        static int cas = 1;
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}

