#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void Solved()
{
    double C, F, X;
    cin >> C >> F >> X;

    double preFrame = 2.0f;
    double baseCostTime = 0.0f;
    double result = X / preFrame;
    
    for (int i = 0; baseCostTime < result; ++i)
    {
        baseCostTime += C / preFrame;
        preFrame += F;
        result = min(result, baseCostTime + X / preFrame);
    }
    printf("%.12lf\n", result);
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int nT = 1;
    scanf("%d", &nT);
    for (int nCase = 1; nCase <= nT; ++nCase)
    {
        printf("Case #%d: ", nCase);
        Solved();
    }

    return 0;
}