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
#define INF 2000000000
#define MAXN 1111
#define MAXM 1005
#define L(x) x<<1
#define R(x) x<<1|1
#define eps 1e-4

using namespace std;

double a[1111] , b[1111] ;
bool used[1111];
int n;
int main()
{
    freopen("C:/D-large.in", "r", stdin) ;
    freopen("C:/dlarge.out" , "w" , stdout) ;
    int T, cas = 0;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)
            scanf("%lf", &a[i]);
        for (int i = 0; i < n; i ++)
            scanf("%lf", &b[i]);
        sort(a , a + n) ;
        sort(b , b + n) ;
        memset(used , 0 , sizeof(used)) ;
        for (int i = 0 ; i < n ; i ++ )
        {
            for (int j = 0 ; j < n ; j ++ )
            {
                if(!used[j] && b[j] > a[i])
                {
                    used[j] = 1 ;
                    break ;
                }
            }
        }
        int res1 = 0 ;
        for (int i = 0 ; i < n ; i ++ )
            if(used[i] == 0) res1++;
        int res2 = 0 ;
        memset(used , 0 , sizeof(used)) ;
        for (int i = 0 ; i < n ; i ++ )
        {
            bool flag = 0 ;
            for (int j = 0 ; j < n ; j ++ )
            {
                if(!used[j] && a[i] > b[j])
                {
                    used[j] = 1 ;
                    flag = 1 ;
                    break ;
                }
            }
            if(flag) res2++;
        }
        printf("Case #%d: %d %d\n", ++ cas, res2  , res1) ;
    }
    return 0 ;
}


