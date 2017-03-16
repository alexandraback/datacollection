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

int t, x, r, c, sol;

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &t);
    for(int I = 1; I <= t; I++)
    {
        scanf("%d%d%d", &x, &r, &c);

        if(r > c)
            swap(r, c);

        if((r * c) % x)
            sol = 1;
        else
        {
            if(x == 1 || x == 2)
                sol = 2;
            else if(x == 3)
            {
                if(r == 1)
                    sol = 1;
                else
                    sol = 2;
            }
            else if(x == 4)
            {
                if(r <= 2)
                    sol = 1;
                else
                    sol = 2;
            }
            else if(x == 5)
            {
                if(r <= 2)
                    sol = 1;
                else if(r == 3 && c == 5)
                    sol = 1;
                else
                    sol = 2;
            }
            else if(x == 6)
            {
                if(r <= 3)
                    sol = 1;
                else
                    sol = 2;
            }
            else
                sol = 1;
        }

        if(sol == 2)
            printf("Case #%d: GABRIEL\n", I);
        else
            printf("Case #%d: RICHARD\n", I);
    }

    return 0;
}
