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
#include <climits>
#define INF 1000000007
#define MP make_pair
const int NUM = 1000100;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int num[NUM];
int reverse(int x)
{
    int s[10];
    int i = 0, j;
    while(x)
    {
        s[i++] = x % 10;
        x /= 10;
    }
    int num = 0;
    for(j = 0; j < i; j++)
    {
        num = num * 10 + s[j];
    }
    return num;
}
int n;
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
    num[1] = 1;
    for(i = 2; i <= 1000000; i++)
    {
        if(num[i] == 0) num[i] = num[i - 1] + 1;
        else
            num[i] = min(num[i], num[i - 1] + 1);
        j = reverse(i);
        if(num[j] == 0) num[j] = num[i] + 1;
        else num[j] = min(num[j], num[i] + 1);
    }
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        scanf("%d", &n);
        printf("Case #%d: %d\n", cas++, num[n]);
    }
    return 0;
}
