#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

int n;
int x, y;
int h[200];
double ans;

void go(int pos, int currX, int currY, double prob)
{

    if (pos == n)
    {
        if (h[x] >= y)
            ans += prob;
        return;
    }

    currY = h[currX] + 2;
    currY = max(currY, h[currX - 1] + 1);
    currY = max(currY, h[currX + 1] + 1);

    bool freeL = true;
    bool freeR = true;
    if (h[currX - 1] >= currY - 1)
        freeL = false;
    if (h[currX + 1] >= currY - 1)
        freeR = false;
    if (currY == 0)
        freeL = freeR = false;

    if (freeL)
        go(pos, currX - 1, currY - 1, prob * (freeR ? 0.5 : 1.0));
    if (freeR)
        go(pos, currX + 1, currY - 1, prob * (freeL ? 0.5 : 1.0));

    if (!freeL && !freeR)
    {
        int temp = h[currX];
        h[currX] = currY;
        go(pos + 1, 100, 10000, prob);
        h[currX] = temp;
    }
}

void solve(int test)
{
    cin >> n >> x >> y;

    x += 100;
    fill(h, h + 200, -2);
    ans = 0;

    if (x >= 0 && x < 200)
        go(0, 100, 10000, 1.0);

    cout << "Case #" << test << ": ";
    cout << ans;
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    cout.setf(ios::fixed);
    cout.precision(10);

    int T;
    cin >> T;
    for (int test = 1; test <= T; test++)
        solve(test);


    fclose(stdin);
    fclose(stdout);

    return 0;
}
