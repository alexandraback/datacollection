#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctype.h>
#include <limits.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#define CLR(a) memset(a, 0, sizeof(a))
#define REP(i, a, b) for(int i = a;i < b;i++)
#define REP_D(i, a, b) for(int i = a;i <= b;i++)

typedef long long ll;

using namespace std;

const int maxn = 1e3 + 100;
int ncase, n, p[maxn];
int check(int t)
{
    int flag = 0;
    for(int fen = 0;fen < t;fen++)
    {
        int must = 0;
        int last = t - fen;
        for(int i = 1;i <= n;i++)
        {
            int tmp = (p[i] + last - 1)/last;
            must += (tmp - 1);
        }
        if(must <= fen)
        {
            flag = 1;
            break;
        }
        else
        {
            ;
        }
    }
    return flag;
//    for(int i = t;i >= 1;i--)
//    {
//        int flag = 0;
//        for(int j = 1;j <= n;j++)
//        {
//            if(p[j] > i)
//            {
//                p[j] -= (i-1);
//                flag = 1;
//                break;
//            }
//        }
//        if(flag == 0)
//        {
//            return 1;
//        }
//    }
    //return 0;
}

void solve()
{
    int l = 1, r = 1000;
    while(l < r)
    {
        int mid = (l + r)/2;
        if(check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d\n", r);
}
int main()
{
    freopen("B-large.in", "r", stdin);
    //freopen("2Bin.txt", "r", stdin);
    freopen("3Bout.txt", "w", stdout);
    scanf("%d", &ncase);
    for(int _ = 1;_ <= ncase;_++)
    {
        scanf("%d", &n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d", &p[i]);
        }
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}
