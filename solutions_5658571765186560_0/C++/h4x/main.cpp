#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdio>

using namespace std;

bool rwin(int x, int r, int c)
{
    if(x == 1) 
        return false;

    if((c*r) < x)
        return true;
    
    if((c*r) % x != 0) 
        return true;

    if(x == 3 && (c == 1 || r == 1))
        return true;

    if(x == 4 && (c == 1 || r == 1 || c == 2 || r == 2))
        return true;

    return false;
}

int main()
{
    /*
    for(int x=1; x<=4; x++)
    {
        printf("mat for %d:\n", x);
        for(int r=1; r<=4; r++)
        {
            for(int c=1; c<=4; c++)
                printf("%s", gwin(x,r,c) ? "o" : "x");
            printf("\n");
        }
    }
    return 0;*/

    int T;
    cin >> T;

    for(int c=0; c<T; c++)
    {
        int x, r, cc;
        cin >> x >> r >> cc;

        bool rw = rwin(x, r, cc);
    
        printf("Case #%d: %s\n", c+1, rw ? "RICHARD" : "GABRIEL");
    }

    return 0;
}
