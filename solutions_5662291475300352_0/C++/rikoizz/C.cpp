#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <queue>

using namespace std;
#define FOR(i,x,y) for (int i = (x);i < (y);i++)
const int N = 1010;
int n;
int a[N],h[N],m[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int _ = 1;_ <= T;_++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d %d %d",&a[i],&h[i],&m[i]);
        if (n == 1 && h[1] == 1)
        {
            if (a[1] == 0) printf("Case #%d: 1\n",_);
            else
                printf("Case #%d: 0\n",_);
            continue;
        }
        if (n == 1 && h[1] == 2)
        {
            if (a[1] == 0) printf("Case #%d: 2\n",_);
            else
                printf("Case #%d: 0\n",_);
            continue;
        }
        if (n == 2)
        {
            if (m[1] > m[2])
            {
                swap(m[1],m[2]);
                swap(a[1],a[2]);
                swap(h[1],h[2]);
            }
            if (a[1] == a[2] && a[1] == 0)
            {
                printf("Case #%d: 2\n",_);
                continue;
            }
            if (a[2] == 0)
            {
                printf("Case #%d: 1\n",_);
                continue;
            }
            int tmp = 0;
            if (a[1] == 0) tmp ++;
            if ((1.0 * (360 - a[2]) * m[2] / m[1]) >= 720 - a[1]) printf("Case #%d: %d\n",_,tmp+1);
            else
                printf("Case #%d: %d\n",_,tmp);
        }
    }
}
