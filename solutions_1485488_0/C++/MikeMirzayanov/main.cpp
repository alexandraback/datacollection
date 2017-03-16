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

const int N = 300;
const int INF = 1000000000;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
int result;

int t10[N][N];
int f[N][N];
int c[N][N];
int H;

void readTestCase(int testCase)
{
    cin >> H >> n >> m;
    forn(i, n)
        forn(j, m)
            cin >> c[i][j];
    forn(i, n)
        forn(j, m)
            cin >> f[i][j];
}

void solveTestCase(int testCase)
{
    cout << "Case #" << testCase << ": ";

    forn(i, n)
        forn(j, m)
            t10[i][j] = INF;
    t10[0][0] = 0;

    queue<pair<int,int> > q;
    set<pair<int,int> > inq;

    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        inq.erase(p);
        int x = p.first;
        int y = p.second;

        forn(d, 4)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (c[nx][ny] - f[x][y] < 50 || c[nx][ny] - f[nx][ny] < 50)
                continue;

            if (c[x][y] - f[nx][ny] < 50)
                continue;

            int w = max(0, H - t10[x][y]);

            int lw = c[nx][ny] - 50;
            if (lw < 0)
                continue;

            if (lw >= w && w == H)
            {
                if (t10[nx][ny] > 0)
                {
                    t10[nx][ny] = 0;
                    if (!inq.count(make_pair(nx, ny)))
                    {
                        inq.insert(make_pair(nx, ny));
                        q.push(make_pair(nx, ny));
                    }
                }
                continue;
            }

            int t = t10[x][y];

            if (lw < w)
            { 
                t += w - lw;
                w = lw;
            }

            if (w - f[x][y] >= 20)
                t += 10;
            else
                t += 100;

            if (t10[nx][ny] > t)
            {
                t10[nx][ny] = t;
                if (!inq.count(make_pair(nx, ny)))
                {
                    inq.insert(make_pair(nx, ny));
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    printf("%.1lf", t10[n - 1][m - 1] / 10.0);

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
