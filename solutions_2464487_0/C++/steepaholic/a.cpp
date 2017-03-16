#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

inline long long paint(long long radius)
{
    return radius * radius;
}

void testcase(int tst)
{
    long long r, t;
    cin >> r >> t;
    long long result = 0;
    for(;;)
    {
        long long needed = paint(r+1) - paint(r);
        if(needed > t)
        {
            break;
        }
        ++result;
        t -= needed;
        r += 2;
    }
    cout << "Case #" << tst << ": " << result << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
    return 0;
}
