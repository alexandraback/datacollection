#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int divideTime[1001][1001];

void calcDivideTime()
{
    for (int et = 1; et <= 1000; ++et)
    {
        for (int i = 0; i <= et; ++i) divideTime[et][i] = 0;
        for (int i = et + 1; i <= min(1000, 2 * et); ++i) divideTime[et][i] = 1;

        for (int i = 2 * et + 1; i <= 1000; ++i) divideTime[et][i] = (i - 1) / et + 1;

        for (int i = 2 * et + 1; i <= 1000; ++i)
            for (int j = et; j <= i / 2; ++j)
                divideTime[et][i] = min(divideTime[et][i], 1 + divideTime[et][i-j] + divideTime[et][j]);
    }
}

int solveForEatingTime(vector<int> const & P, int et)
{
    int res = et;
    for (auto p : P) res += divideTime[et][p];
    return res;
}

int solve0(vector<int> const & P)
{
    int res = 100000000;
    for (int et = 1; et <= 1000; ++et)
        res = min(res, solveForEatingTime(P, et));
    return res;
}

int main()
{
    calcDivideTime();

    assert(divideTime[3][1] == 0);
    assert(divideTime[3][2] == 0);
    assert(divideTime[3][3] == 0);
    assert(divideTime[3][4] == 1);
    assert(divideTime[3][5] == 1);
    assert(divideTime[3][6] == 1);
    assert(divideTime[3][7] == 2);
    assert(divideTime[3][8] == 2);
    assert(divideTime[3][9] == 2);
    assert(divideTime[3][10] == 3);
    assert(divideTime[3][11] == 3);
    assert(divideTime[3][12] == 3);

    int caseCount = 0;
    cin >> caseCount;

    for (int i = 0; i < caseCount; ++i)
    {
        int d;
        cin >> d;
        vector<int> P(d);
        for (int j = 0; j < d; ++j)
            cin >> P[j];

        cout << "Case #" << i + 1 << ": " << solve0(P) << endl;
    }
    return 0;
}

