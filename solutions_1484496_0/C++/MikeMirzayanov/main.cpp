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
int result;
int a[N];

void readTestCase(int testCase)
{
    cin >> n;
    forn(i, n)
        cin >> a[i];
}

void solveTestCase(int testCase)
{
    cout << "Case #" << testCase << ":" << endl;

    map<int, vector<int> > z;

    forn(mask, 1 << n)
        if (mask)
        {
            int sum = 0;
            forn(i, n)
                if (mask & (1 << i))
                    sum += a[i];
            z[sum].push_back(mask);
        }

    for (map<int,vector<int> > :: iterator i = z.begin(); i != z.end(); i++)
        if (i->second.size() > 1)
        {
            forn(tt, 2)
            {
                int mask = i->second[tt];
                bool first = true;
                forn(j, n)
                    if (mask & (1 << j))
                    {
                        if (!first)
                            cout << " ";
                        first = false;
                        cout << a[j];
                    }
                cout << endl;
            }
            return;
        }

    cout << "Impossible" << endl;
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
