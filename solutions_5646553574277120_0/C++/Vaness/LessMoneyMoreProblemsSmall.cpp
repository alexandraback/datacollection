#include <bits/stdc++.h>
using namespace std;

int T;
int C, D, V;

bool can(vector<int> denominations, int maxValue)
{
    vector<int> values(maxValue + 1, 0);
    values[0] = 1;
    for (int &denominationValue : denominations)
    {
        for (int j = maxValue; j >= 0; j--)
        {
            if (values[j] && j + denominationValue <= maxValue)
                values[j + denominationValue] = 1;
        }
    }
    for (int &value : values)
        if (!value)
            return false;
    return true;
}

int res;

int go(vector<int> denominations, int start = 1)
{
    if (can(denominations, V))
        return denominations.size();

    if (denominations.size() >= res)
        return V;

    int best = V;
    for (int addDenomination = start; addDenomination <= V; addDenomination++)
    {
        bool contains = false;
        for (int &denomination : denominations)
            if (denomination == addDenomination)
                contains = true;
        if (!contains)
        {
            denominations.push_back(addDenomination);
            best = min(best, go(denominations, start));
            if (best < res)
            {
                //cerr << best << endl;
                res = best;
            }
            denominations.pop_back();
        }
    }
    return best;
}

int solve()
{
    scanf("%d%d%d", &C, &D, &V);
    res = V;
    vector<int> denominations(D);
    for (int i = 0; i < D; i++)
        scanf("%d", &denominations[i]);
    
    return go(denominations) - (int)denominations.size();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int testNumber = 1; testNumber <= T; testNumber++)
        printf("Case #%d: %d\n", testNumber, solve());
}
