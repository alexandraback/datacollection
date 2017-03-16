#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define piii pair<pair<int,int>,int>
#define pii pair<int,int>
#define pdd pair<double,double>

int X, R, C;

void Debug()
{
}

void Read()
{
    cin >> X >> R >> C;
}

bool Solve()
{
    if(X==1)
        return true;
    if(X > 6)
        return false;
    if(R > C)
        swap(R, C);

    if(C < X)
        return false;
    if(R*C < X)
        return false;

    if(R < 2 && X == 3)
        return false;
    if(R < 3 && X == 4)
        return false;
    if(R < 4 && X == 5)
        return false;
    if(R < 5 && X == 6)
        return false;

    R = R % X;
    C = C % X;
    if(C < R)
        swap(C, R);

    if(C==0 || R == 0)
        return true;

    if(X==4 && R==2 && C==2)
        return true;

    return false;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        Read();
        if(Solve())
            printf("Case #%d: GABRIEL\n", i);
        else
            printf("Case #%d: RICHARD\n", i);
        Debug();
    }
    return 0;
}
