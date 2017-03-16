#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

int K, C, S;

long long finalPosition(long long startPosition, long long currPosition, int steps)
{
    if (steps == 0)
    {
        return currPosition;
    }

    long long nextPosition = currPosition * K + startPosition;
    return finalPosition(startPosition, nextPosition, steps - 1);
}

vector<long long> solve()
{
    cin >> K >> C >> S;

    vector<long long> res(S);
    for (int i = 0; i < S; ++i)
    {
        res[i] = finalPosition(i, i, C - 1);
    }

    return res;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        cout << "Case #" << csIx << ":";
        vector<long long> res = solve();
        for (int i = 0; i < res.size(); ++i)
        {
            cout << " " << res[i] + 1;
        }
        cout << endl;
    }
    
    return 0;
}
