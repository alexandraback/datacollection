//#define LARGE
//#define SMALL

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>

using namespace std;

int t, T, R, C, W;

int main()
{
#if defined(LARGE)
    freopen("../A-large.in", "r", stdin);
    freopen("../A-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../A-small-attempt0.in", "r", stdin);
    freopen("../A-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for(t = 0; t < T; ++t)
    {
        cin >> R >> C >> W;
        if (C % W == 0) cout << "Case #" << t+1 << ": " << R * (C/W) + W - 1 << "\n";
        else cout << "Case #" << t+1 << ": " << R * (C/W) + W << "\n";
    }

    return 0;
}
