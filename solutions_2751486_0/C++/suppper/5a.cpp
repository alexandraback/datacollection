#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX = 1000008;

char str[MAX];
typedef long long LL;
LL ans;
int n;

inline bool check(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

void work()
{
    int len = strlen(str);
    int cnt = 0;
    int left = 0;
    int ls = 0;
    int i = 0;
    while (i != len) {
        if (!check(str[i]))
            cnt++;
        else {
            cnt = 0;
            ls = i + 1;
        }
        if (cnt == n) {
        //   printf("i %d ls %d left %d ", i, ls, left);
            ans += (LL)(ls - left + 1) * (LL)(len - i);
            left = ls + 1;
            ls++;
         //   printf("ans %I64d\n", ans);
            cnt--;
        }
        i++;
    }


}


int main()
{
    freopen("5a0.in", "r", stdin);
    freopen("5a0.out", "w", stdout);

    int cas;
    scanf("%d", &cas);
    for (int icase = 1; icase <= cas; ++icase) {
        scanf("%s%d", str, &n);
        ans = 0LL;
       work();
       printf("Case #%d: %I64d\n", icase, ans);
    }

}
