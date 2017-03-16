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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;

#define MX 1000

long long T, N, M;
long long a[MX], b[MX] ,A[MX], B[MX];
long long ans, tmp;

void dfs(long long i, int j)
{
    if(i >= N || j >= M) return ;
    long long k;
    for(k = j;k < M;k++)
        if(B[k] == A[i]) break;

    if(k < M)
    {

        long long mn = min(a[i], b[k]);
        tmp += mn;
        if(ans < tmp) ans = tmp;

        a[i] -= mn;
        b[k] -= mn;
        long long l1 = i,l2 = k;
        if(!a[l1]) l1++;
        if(!b[l2]) l2++;
        dfs(l1, l2);
        a[i] += mn;
        b[k] += mn;

        tmp -= mn;
    }

    dfs(i+1, j);
}

//#define HOME
//#define SMALL
//#define LARGE
int main() 
{
#ifdef HOME
    freopen("1.txt", "r", stdin);
#endif
#ifdef SMALL
    freopen("out", "w", stdout);
    freopen("C-small-attempt0.in", "r", stdin);
#endif
#ifdef LARGE
    freopen("out", "w", stdout);
    freopen("C-large.in", "r", stdin);
#endif
    scanf("%lld", &T);
    for(long long c = 1; c <= T;c++)
    {
        tmp = 0;
        scanf("%lld %lld", &N ,& M);

        for(long long i = 0;i < N;i++)
            scanf("%lld %lld", a+i, A+i);
        for(long long j = 0;j < M;j++)
            scanf("%lld %lld", b+j, B+j);

        ans = 0;
        dfs(0, 0);

        printf("Case #%lld: %lld\n", c, ans );
    }
}
