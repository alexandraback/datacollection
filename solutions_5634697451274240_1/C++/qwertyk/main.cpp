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

int t, T, L, i, R;
string s;

int main()
{
#if defined(LARGE)
    freopen("../B-large.in", "r", stdin);
    freopen("../B-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../B-small-attempt0.in", "r", stdin);
    freopen("../B-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for(t = 0; t < T; ++t)
    {
        cin >> s;
        L = s.length();
        R = 0;
        for (i = 1; i < L; ++i)
            if (s[i] != s[i-1]) ++R;
        if (s[L-1] == '-') ++R;
        cout << "Case #" << t+1 << ": " << R << "\n";
    }

    return 0;
}
