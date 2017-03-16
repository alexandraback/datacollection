#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

#define PI 3.1415926535898
#define MAX 1000000000LL
#define eps 1e-3

int
main ()
{
    int T;
    long long k;
    long long r, t, len, val;

    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> r >> t;

        k = 0;
        len = 1;
        while (1) {
            val = k + len;
            if (2 * val * r + val * (2 * val - 1) <= t) {
                k = val;
                len <<= 1;
            } else {
                len /= 2;
                if (len == 0) break;
            }
        }
        cout << "Case #" << i << ": " << k + len << endl;
    }
    return 0;
}
