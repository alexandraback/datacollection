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

int n;
li a[N];

void readTestCase(int testCase)
{
    cin >> n;
    forn(i, n)
        cin >> a[i];
}

void out(li m1, li m2)
{
    li s1 = 0, s2 = 0;
    {
        bool first = true;
        forn(i, n)
            if (m1 & (1LL << i))
            {
                if (!first)
                    cout << " ";
                cout << a[i];
                s1 += a[i];
                first = false;
            }
        cout << endl;
    }
    {
        bool first = true;
        forn(i, n)
            if (m2 & (1LL << i))
            {
                if (!first)
                    cout << " ";
                cout << a[i];
                s2 += a[i];
                first = false;
            }
        cout << endl;
    }
    if (s1 != s2)
    {
        cerr << m1 << endl;
        cerr << m2 << endl;
        throw;
    }
    assert(s1 == s2);
}

void solveTestCase(int testCase)
{
    cout << "Case #" << testCase << ":" << endl;

    sort(a, a + n);

    li sum = 0;
    int m = -1;
    forn(i, n)
    {
        sum += a[i];
        li lim = (1LL << (i + 1)) - 1;
        if (sum < lim)
        {
            m = i + 1;
            break;
        }
    }

    if (m >= 1)
        n = m;

    cerr << "n=" << n << endl;

    int cc = clock();
    while (clock() - cc <= 30000)
    {
        random_shuffle(a, a + n);
        m = n / 2;
        map<li,pair<int,int> > z;
        forn(i, 1 << m) if (i)
        {
            li sum = 0;
            forn(j, m)
                if (i & (1 << j))
                    sum += a[j];
            pair<int,int>& p = z[sum];
            if (p.first == 0)
                p.first = i;
            else
            {
                out(p.first, i);
                return;
            }
        }

        forn(i, 1 << (n - m)) if (i)
        {
            li mask = i;
            mask = mask << m;

            li sum = 0;
            forn(j, n - m)
                if (i & (1 << j))
                    sum += a[m + j];

            pair<int,int>& p = z[sum];
            if (p.first == 0)
                p.first = mask;
            else
            {
                out(p.first, mask);
                return;
            }
        }
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
