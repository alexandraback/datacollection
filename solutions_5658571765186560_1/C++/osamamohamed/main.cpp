#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    freopen("D-large.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , c = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++c;
        int X , R , C;
        scanf("%d%d%d" , &X , &R , &C);

        bool ok = false;

        if(X < 7 && (!((R * C) % X)))
        {
            if(R > C)
                swap(R , C);

            if(X < 3)
                ok = true;

            else if(X == 3)
                ok = R > 1 ? true : false;

            else if(X == 4)
                ok = R > 2 ? true : false;

            else
                ok = R >= X - 2 ? true : false;
        }
        if(ok)
            printf("Case #%d: GABRIEL\n" , c);

        else
            printf("Case #%d: RICHARD\n" , c);
    }
}
