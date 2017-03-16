#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define BARSUK_ALEXEY_PSKOV

int tests;

int main()
{
#ifdef BARSUK_ALEXEY_PSKOV
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> tests;
    for (int t = 1; t <= tests; t++)
    {
        int r, c, w;
        cin >> r >> c >> w;

        int answer = (c/w)*(r - 1);

        c += w - 1;
        answer += c/w + w - 1;

        cout << "Case #" << t << ": " << answer << endl;
    }

    return 0;
}

