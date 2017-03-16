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

int R, C, W;

void Debug()
{
}

void Read()
{
    scanf("%d %d %d", &R, &C, &W);
}

void Solve()
{
    if(C%W != 0)
        printf("%d\n", ((C-(C%W))/W)*R+W);
    else
        printf("%d\n", (C/W)*R+W-1);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; ++i)
    {
        Read();
        printf("Case #%d: ", i);
        Solve();
        Debug();
    }
    return 0;
}
