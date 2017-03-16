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
bool isps[1005];
bool isp(int num)
{
    char strnum[20];
    itoa(num, strnum, 10);
    int len = strlen(strnum);
    for(int i = 0; i < len / 2; i++)
        if(strnum[i] != strnum[len - i - 1]) return false;
    return true;
}
void init()
{
    memset(isps, false, sizeof(isps));
    for(int i = 1; i <= 1000; i++)
    {
        if(sqrt(i) * sqrt(i) != i)continue;
        if(isp(i) && isp(sqrt(i))) isps[i] = true;
    }
}
int main()
{
    int t;
    init();
    freopen("C-small-attempt0.in.", "r", stdin);
    freopen("cans.out", "w", stdout);
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++)
    {
        int a, b, ret = 0;
        scanf("%d%d", &a, &b);
        for(int i = a; i <= b; i++)
            if(isps[i]) ret++;
        printf("Case #%d: %d\n", ca, ret);
    }
	return 0;
}
