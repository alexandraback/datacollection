#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int X, R, C;
int T, cas = 1;
void pr(int i)
{
    if(i)
        printf("Case #%d: GABRIEL\n", cas++);
    else
        printf("Case #%d: RICHARD\n", cas++);
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int i, j;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &X, &R, &C);
        if(R * C % X == 0)
        {
            if(X == 1 || X == 2)
                pr(1);
            else if(X == 3 && ((R % X == 0 && C >= 2) || (C % X == 0 && R >= 2)))
                pr(1);
            else if(X == 4 && ((R == 4 && C >= 3) || (C == 4 && R >= 3)))
                pr(1);
            else
                pr(0);
        }
        else
            pr(0);
    }
    return 0;
}
