#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



int doit(int c, int w)
{
    if (c == w) return w;
    if (w == 1) return c;
    if (c / w == 1) return w + 1;
    if (c == 0) return 0;
    return doit(c - w, w) + 1;
}

void _main(int cases)
{
    int R, C, W;
    scanf("%d%d%d", &R, &C, &W);

    printf("%d\n", doit(C, W));
   
}


int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        printf("Case #%d: ", cases);
        _main(cases);
    }
}