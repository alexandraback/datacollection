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

ll t, i, j, unde, now, poz, rest;
ll a[10][10], b[10][10];
ll l, x;
char s[10005], where[150];

ll neg(ll x)
{
    if(x <= 4)
        x += 4;
    else
        x -= 4;

    return x;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    for(i = 1; i <= 4; i++)
        b[1][i] = b[i][1] = i;

    b[2][2] = 5;
    b[2][3] = 4;
    b[2][4] = 7;

    b[3][2] = 8;
    b[3][3] = 5;
    b[3][4] = 2;

    b[4][2] = 3;
    b[4][3] = 6;
    b[4][4] = 5;

    where['i'] = 2;
    where['j'] = 3;
    where['k'] = 4;

    for(i = 1; i <= 8; i++)
        for(j = 1; j <= 8; j++)
        {
            if(i <= 4 && j <= 4)
                a[i][j] = b[i][j];
            else if(i <= 4 && j > 4)
                a[i][j] = neg(b[i][j - 4]);
            else if(i > 4 && j <= 4)
                a[i][j] = neg(b[i - 4][j]);
            else
                a[i][j] = b[i - 4][j - 4];
        }

    scanf("%lld", &t);
    for(int I = 1; I <= t; I++)
    {
        scanf("%lld%lld", &l, &x);
        scanf("%s", s + 1);

        now = 1;
        for(i = 1; i <= l; i++)
            now = a[now][where[s[i]]];

        ll r = 1;
        for(i = 1; i <= x; i <<= 1)
        {
            if(i & x)
                r = a[r][now];
            now = a[now][now];
        }

        if(r != 5)
        {
            printf("Case #%d: NO\n", I);
            continue;
        }

        int ok = 0;

        now = 1;
        for(i = 1; i <= l * x && i <= 100000LL; i++)
        {
            unde = i % l;
            if(!unde)
                unde = l;

            now = a[now][where[s[unde]]];

            if(now == 2)
            {
                i++;
                ok++;
                break;
            }
        }

        now = 1;
        for(; i <= l * x && i <= 100000LL; i++)
        {
            unde = i % l;
            if(!unde)
                unde = l;

            now = a[now][where[s[unde]]];

            if(now == 3)
            {
                i++;
                ok++;
                break;
            }
        }

        now = 1;
        for(; i <= l * x && i <= 100000LL; i++)
        {
            unde = i % l;
            if(!unde)
                unde = l;

            now = a[now][where[s[unde]]];

            if(now == 4)
            {
                ok++;
                break;
            }
        }

        if(ok == 3)
            printf("Case #%d: YES\n", I);
        else
            printf("Case #%d: NO\n", I);
    }

    return 0;
}
