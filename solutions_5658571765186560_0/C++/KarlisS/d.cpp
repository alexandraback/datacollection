#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
bool solve(int x, int r, int c)
{
    if (((r*c) % x) != 0) return false;
    if (r > c) swap(r, c);
    if (x == 1) return true;
    if (x == 2) return true;
    if (x == 3) return r >= 2;
    if (x == 4) return r >= 3 && c >= 4;
    if (x == 5) return r >= 4 && c >= 5;
    if (x == 6) return r >= 4 && c >= 6;
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        int x,r,c;
        scanf("%d %d %d", &x, &r, &c);
        printf("Case #%d: %s\n", i, solve(x,r,c) ? "GABRIEL" : "RICHARD");
    }
}
