#include<cstdio>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<unordered_map>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

const int nmax = 1005;
const int inf = (1LL << 31) - 1;

int t, i, j, c, r, n, flc, sol, a[nmax];

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &t);
    for(int I = 1; I <= t; I++)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        sol = inf;
        for(i = 1; i <= 1000; i++)
        {
            flc = 0;
            for(j = 1; j <= n; j++)
            {
                if(a[j] <= i)
                    continue;

                c = a[j] / i;
                r = a[j] % i;

                flc += c;
                if(!r)
                    flc--;
            }

            sol = min(sol, i + flc);
        }

        printf("Case #%d: %d\n", I, sol);
    }

    return 0;
}
