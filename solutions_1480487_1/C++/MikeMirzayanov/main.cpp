#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#if defined LOCAL_RUN || defined _DEBUG
#   define DEBUG_OUTPUT
#   include "local_run.h"
#else
#   define _(x) void(0)
#endif

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;
typedef long double ld;

using namespace std;

const int N = 1000;
const int INF = 1000000000;

int n, m;
double s[N];
double sum;
int result;

void readTestCase(int testCase)
{
    cin >> n;
    sum = 0;
    forn(i, n)
    {
        cin >> s[i];
        sum += s[i];
    }
}

bool can(int idx, double a)
{
    double pts = s[idx] + a * sum;
    double others = 0;
    forn(i, n)
        if (i != idx)
        {
            if (s[i] >= pts)
                continue;
            double delta = pts - s[i];
            others += delta / sum;
        }
    return others > 1.0 - a;
}

void solveTestCase(int testCase)
{
    cout << "Case #" << testCase << ":";

    forn(i, n)
    {
        double lf = 0.0;
        double rg = 1.0;

        forn(tt, 200)
        {
            double mid = (lf + rg) / 2.0;

            if (can(i, mid))
                rg = mid;
            else
                lf = mid;
        }

        printf(" %.10lf", 100.0 * (lf + rg) / 2.0);
    }


    cout << endl;
}

int main(int argc, char* argv[])
{
    freopen("input.txt", "rt", stdin);

    if (argc != 1 && argc != 3)
    {
        cout << "Usage: solution.exe [<first-test> <last-test>] (1-based)" << endl;
        return 1;
    }

    int testCount;
    string line;
    getline(cin, line);
    sscanf(line.c_str(), "%d", &testCount);

    int beginTestCase = 1;
    int endTestCase = testCount;

    if (argc == 3)
    {
        beginTestCase = max(beginTestCase, atoi(argv[1]));
        endTestCase = min(endTestCase, atoi(argv[2]));
    }

    for (int testCase = 1; testCase <= testCount; testCase++)
    {
        readTestCase(testCase);

        if (beginTestCase <= testCase && testCase <= endTestCase) {
            solveTestCase(testCase);
        }
    }

    return 0;
}
