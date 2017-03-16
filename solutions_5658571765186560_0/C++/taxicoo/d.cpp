#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back



int main()
{
    freopen("inputd.txt", "r", stdin);
    freopen("outputd.txt", "w", stdout);
    int T, x, r, c;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        cin >> x >> r >> c;
        if (x==1)
        {
            printf("Case #%d: GABRIEL\n", t);
            continue;
        }
        if (x>6)
        {
            printf("Case #%d: RICHARD\n", t);
            continue;
        }
        if ((r*c)%x!=0)
        {
            printf("Case #%d: RICHARD\n", t);
            continue;
        }
        if (max(r, c) < x)
        {
            printf("Case #%d: RICHARD\n", t);
            continue;
        }
        if (min(r, c) < (x/2)+(x%2))
        {
            printf("Case #%d: RICHARD\n", t);
            continue;
        }
        if ((x>3) && (min(r, c) == (x/2)+(x%2)) && (r*c/x < 3))
        {
            printf("Case #%d: RICHARD\n", t);
            continue;
        }
        printf("Case #%d: GABRIEL\n", t);
    }


    return 0;
}

