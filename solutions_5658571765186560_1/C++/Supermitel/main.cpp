#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int lat, n, m;

bool solve()
{
    if((n*m)%lat != 0) return 0;

    if(lat == 1 || lat == 2)
        return 1;

    if(lat == 3)
        if(n >= 2 && m >= 2)
            return true;
        else return false;

    if(lat == 4)
        if(n >= 3 && m >= 3)
            return true;
        else return false;


    if(lat == 6 || lat == 5)
        if(n >= 4 && m >= 4)
            return true;
        else return false;

    if(lat > 7)
        return false;
}

int main()
{
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int q = 1; q <= t; q++)
    {
        scanf("%d%d%d\n", &lat, &n, &m);
        printf("Case #%d: ", q);
        if(solve())
            printf("GABRIEL\n");
        else printf("RICHARD\n");
    }

    return 0;
}
