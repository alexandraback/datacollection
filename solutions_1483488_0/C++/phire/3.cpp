#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

static inline int rotate(int c, int shift)
{
    int d = c % 10;
    return c / 10 + d * shift;
}

static int solve(int a, int b)
{
    int ret = 0;
    int t = b;
    int shift = 0;

    while (t) {
        t /= 10;
        if (shift)
            shift *= 10;
        else
            shift = 1;
    }

    for (int c = a; c <= b; c++) {
        t = c;
        do {
            t = rotate(t, shift);
            if (a <= t && t < c)
                ret++;
        } while (t != c);
    }

    return ret;
}

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << solve(a,b) << endl;
    }
    return 0;
}
