#define LARGE
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

int t, T, K, C, S, i;
long long int X, Y, Z;

int main()
{
#if defined(LARGE)
    freopen("../D-large.in", "r", stdin);
    freopen("../D-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../D-small-attempt1.in", "r", stdin);
    freopen("../D-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for(t = 0; t < T; ++t)
    {
        cin >> K >> C >> S;
        if ((K + C - 1) / C > S)
        {
            cout << "Case #" << t+1 << ": IMPOSSIBLE\n";
            continue;
        }
        X = 0;
        Y = 1;
        Z = 1;
        for (i = C-1; i != -1; --i)
        {
            Z += i*Y; 
            X += Y;
            Y *= K;
        }
        X *= C;
        cout << "Case #" << t+1 << ":";
        for (i = 0; i < (K + C - 1) / C - 1; ++i) cout << " " << (i * X + Z);
        X = 1;
        Y = 1;
        for (i = 0; i < C; ++i)
        {
            if (K-i < 1) break;
            X += (K-i-1)*Y;
            Y *= K;
        }
        cout << " " << X << "\n";
    }

    return 0;
}
