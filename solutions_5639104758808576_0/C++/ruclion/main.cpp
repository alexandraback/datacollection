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

const int maxn = 1000 + 10;
int sum;
char s[maxn];
int n;
int check(int key)
{
    int have = key;
    for(int i = 0;i <= n;i++)
    {
        int t = s[i]-'0';
        if(t > 0 && have >= i)
        {
            have += t;
        }
    }
    if(have == key + sum)
    {
        return 1;
    }
    return 0;
}
void solve()
{
    int l = 0, r = 1000;
    while(l<r)
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
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("1Ain.txt", "r", stdin);
    freopen("1Aout.txt", "w", stdout);
    int ncase;
    scanf("%d", &ncase);
    for(int _ = 1;_ <= ncase;_++)
    {
        scanf("%d", &n);
        scanf("%s", s);
        sum = 0;
        for(int i = 0;i <= n;i++)
        {
            sum += (s[i]-'0');
        }
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}
