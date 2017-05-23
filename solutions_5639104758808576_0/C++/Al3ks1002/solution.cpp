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

int t, n, now, sol, i;
char s[1005];

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &t);
    for(int I = 1; I <= t; I++)
    {
        scanf("%d", &n);
        scanf("%s", s);

        now = s[0] - '0';
        sol = 0;
        for(i = 1; i <= n; i++)
        {
            if(now < i)
                sol += i - now, now = i;
            now += s[i] - '0';
        }

        printf("Case #%d: %d\n", I, sol);
    }

    return 0;
}
