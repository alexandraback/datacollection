#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
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
    
    // lossy
    long long best = (0.25l * (sqrt(4.0l * r * r - 4.0l * r + 8.0l * t + 1.0l) - 2.0l * r + 1.0l));
    //cerr << "Case #" << tst << ": " << fixed << best << endl;
    
    long long result = max(0ll, best - 1000000ll);
    t -= 2 * (result * result + result) + result * (2 * r - 3);
    
    for(;;)
    {
        long long needed = 4 * (result+1) + 2 * (r) - 3;
        if(needed > t)
        {
            break;
        }
        //cerr << "Ring " << result << " needed " << needed << endl;
        ++result;
        t -= needed;
        //r += 2;
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
