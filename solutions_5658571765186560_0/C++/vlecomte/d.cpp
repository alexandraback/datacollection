#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

// Obtained through case separation...
// ...although not very rigorous once I got bored.

bool gab(int x, int r, int c)
{
    if ((r*c)%x != 0)
        return false;
    int m = min(r,c);
    switch (x)
    {
        case 1:
        case 2:
            return true;
        case 3:
            return m >= 2;
        case 4:
            return m >= 3;
        case 5:
        case 6:
            return m >= 4;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        int x,r,c;
        cin >> x >> r >> c;
         
        if (gab(x,r,c))
            printf("Case #%d: GABRIEL\n", t);
        else
            printf("Case #%d: RICHARD\n", t);
    }
}
