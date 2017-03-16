#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#define maxn 2000010

int range[maxn], len[maxn];
int power10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, maxn}, x[200];
int res[200][200], n, a[200], b[200];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", & n);
    
    x[0] = 1;
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%d %d", a + i, b + i);
        x[i] = a[i];
        x[i + n] = b[i] + 1;
    }
    sort(x, x + n + n + 1);
    
    for (int i = 0; i < n + n; ++ i)
        for (int j = x[i]; j < x[i + 1]; ++ j)
            range[j] = i;
    for (int i = 0; i < 7; ++ i)
        for (int j = power10[i]; j < power10[i + 1]; ++ j)
            len[j] = i + 1;
    
    memset(res, 0, sizeof(res));
    for (int i = x[1]; i < x[n + n]; ++ i)
    {
        int tmp[10];
        for (int j = 1; j < len[i]; ++ j)
        {
            int p = i / power10[j], q = i % power10[j];
            int jj = len[i] - j;
            int ii = q * power10[jj] + p;
            
            tmp[j] = ii;
            for (int t = 1; t < j; ++ t)
                if (tmp[t] == ii)
                    ii = 0;
            
            if (ii > i && ii < x[n + n])
                res[range[i]][range[ii]] ++;
        }
    }
    for (int i = 1; i <= n; ++ i)
    {
        int ans = 0;
        for (int j = 0; j <= n + n; ++ j)
            for (int k = j; k <= n + n; ++ k)
                if (a[i] <= x[j] && x[k + 1] <= b[i] + 1)
                    ans += res[j][k];
        printf("Case #%d: %d\n", i, ans);
    }
//    fclose(stdout);
}


