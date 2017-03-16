#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 1000000005
#define eps 1e-10
#define PI acos(-1.0)
#define LL long long

using namespace std;

int main()
{
    int T, cas = 0;
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &T);
    while(T--)
    {
        int r, c, w, temp, ans;
        scanf("%d%d%d", &r, &c, &w);
        if (c == w)
        {
            ans = w;
        }
        else
        {
            temp = c - w;
            if (temp % w == 0) ans = temp / w + w; else ans = temp / w + w + 1;
        }
        if (c % w == 0) temp = c / w; else temp = c / w + 1;
        ans = ans + (r - 1) * temp;
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
