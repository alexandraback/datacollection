#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<vector<string> > S =
{
    {
        "....",
        "....",
        "....",
        "....",
    },
    {
        "R.R.",
        "....",
        "R.R.",
        "....",
    },
    {
        "RRRR",
        "RR.R",
        "R...",
        "RR.R",
    },
    {
        "RRRR",
        "RRRR",
        "RRR.",
        "RR..",
    },
};

bool solve(int X, int R, int C)
{
    assert(X <= 4 && R <= 4 && C <= 4 && X >= 1 && R >= 1 && C >= 1);
    return S[X-1][R-1][C-1] == 'R';
}

int main()
{
    int caseCount = 0;
    cin >> caseCount;

    for (int i = 0; i < caseCount; ++i)
    {
        int X, R, C;
        cin >> X >> R >> C;
        bool res = solve(X, R, C);
        cout << "Case #" << i + 1 << ": " << (res ? "RICHARD" : "GABRIEL") << endl;
    }
    return 0;
}

