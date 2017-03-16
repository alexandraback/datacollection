#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
#define INF 0x73737373
#define EPS 1e-8
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
bool isps[10000005];
bool isp(long long num)
{
    char strnum[20];
    memset(strnum, 0, sizeof(strnum));
    int len = 0;
    while(num)
    {
        strnum[len++] = num % 10 + '0';
        num /= 10;
    }
    for(int i = 0; i < len / 2; i++)
        if(strnum[i] != strnum[len - i - 1]) return false;
    return true;
}
void init()
{
    memset(isps, false, sizeof(isps));
    for(long long i = 1; i <= 10000000; i++)
    {
        if(isp(i) && isp(i * i)) isps[i] = true;
    }
}
int main()
{
    int t;
    init();
    freopen("C-large-1.in.", "r", stdin);
    freopen("cans.out", "w", stdout);
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++)
    {
        long long a, b, ret = 0;
        scanf("%lld%lld", &a, &b);
        int str = ceil(sqrt(a));
        int end = floor(sqrt(b));
        for(int i = str; i <= end; i++)
            if(isps[i])ret++;
        printf("Case #%d: %d\n", ca, ret);
    }
	return 0;
}
