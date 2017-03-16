#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPEQ(i, n) for (int i = 0; i <= (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define FOREQ(i, a, b) for (int i = (a); i <= (int)(b); ++i)

const double EPS = 1e-10;
const double PI = 3.14159265358979323846264338;

int main()
{
    int T; cin >> T;
    REP(testcase, T) {
        cout << "Case #" << testcase + 1 << ": ";
        int r, t; cin >> r >> t;

        int count = 0;
        int sum = 0;
        for ( ; ; ++count) {
            sum += count * 4 + 2 * r + 1;
            if (sum > t)
                break;
        }
        cout << count << endl;
    }
}
