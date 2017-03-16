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
const int NUM = 10000100;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
LL num10[20];
void init()
{
    num10[1] = 1;
    num10[2] = 10;
    LL j = 9;
    for(int i = 3; i < 16; i++)
    {
        num10[i] = num10[i - 1] + 1LL + j;
        if(~i & 1)
            j = j * 10LL + 9LL;
        num10[i] += j;
    }
}

LL reverse(LL x)
{
    int s[20];
    LL i = 0, j;
    while(x)
    {
        s[i++] = x % 10;
        x /= 10;
    }
    LL num = 0;
    for(j = 0; j < i; j++)
    {
        num = num * 10 + s[j];
    }
    return num;
}
LL get(LL N)
{
    LL bit = 0, i, x = N, y = 1, z, w;
    LL s[20];
    while(x)
    {
        s[bit++] = x % 10LL;
        x /= 10LL;
        y *= 10LL;
    }
    y /= 10LL;
    LL res = num10[bit];
    if(N == y)
        return res;
    if(s[0] == 0)
        return get(N - 1) + 1LL;
    x = 0;

    for(i = bit / 2; i < bit; i++)
    {
        x = x * 10LL + s[i];
    }
    z = x;
    x = reverse(x + y);
    z += N - x + 1LL;
    w = N - y;
    return res + min(z, w);
}
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
	init();
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
    	LL n;
        cin >> n;
        cout << "Case #" << cas ++ << ": " << get(n) << endl;
    }
    return 0;
}
