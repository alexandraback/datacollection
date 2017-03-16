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

long long calcPosition(const vector<int> & seq)
{
    long long res = 0;
    for (int i = 0; i < seq.size(); ++i)
    {
        res = res * K + seq[i];
    }
    return res;
}

vector<long long> solve()
{
    vector< vector<int> > checks(S, vector<int>(C));
    int ix = 0;
    for (int s = 0; s < S; ++s)
    {
        for (int c = 0; c < C; ++c)
        {
            checks[s][c] = ix % K;
            ++ix;
        }
    }

    vector<long long> res(S);
    for (int i = 0; i < S; ++i)
    {
        res[i] = calcPosition(checks[i]);
    }

    return res;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        cin >> K >> C >> S;
        if (S * C < K)
        {
            cout << "Case #" << csIx << ": IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << csIx << ":";
            vector<long long> res = solve();
            set<long long> resSet(res.begin(), res.end());
            vector<long long> resUnique(resSet.begin(), resSet.end());
            for (int i = 0; i < resUnique.size(); ++i)
            {
                cout << " " << resUnique[i] + 1;
            }
            cout << endl;
        }
    }
    
    return 0;
}
