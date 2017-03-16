/*
ID: CUGB-wwj
PROG:
LANG: C++
*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define INF 1LL<<60
#define MAXN 1005
#define MAXM 1005
#define L(x) x<<1
#define R(x) x<<1|1
#define eps 1e-4
using namespace std;
int t[111];
int main()
{
    freopen("D:/B-small-attempt0.in","r",stdin);
    freopen("D:/B-small-attempt0.out","w",stdout);
    int T, s, p, n;
    int cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        printf("Case #%d: ", ++cas);
        scanf("%d%d%d", &n, &s, &p);
        for(int i = 0; i < n; i++) scanf("%d", &t[i]);
        int ans = 0;
        sort(t, t + n);
        for(int i = n - 1; i >= 0; i--)
        {
            if((t[i] + 2) / 3 >= p) {ans ++; continue;}
            else if(t[i] == 1) {if(p <= 1) ans++; continue;}
            else if(t[i] == 0) {if(p <= 0) ans++; continue;}
            if(s == 0) break;
            if(t[i] >= 3 * (p - 1) - 1) {ans++; s--;}
        }
        printf("%d\n", ans);
    }
    return 0;
}
