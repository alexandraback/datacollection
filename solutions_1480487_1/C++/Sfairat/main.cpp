#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
typedef pair <int, int> pii;

void test(int testNo)
{
    int pc;
    scanf("%d", &pc);
    vector<pii> participants;
    double totalPointsCount = 0;
    for (int i = 0; i < pc; i++)
    {
        int cpc;
        scanf("%d", &cpc);
        participants.push_back(pii(cpc, i));
        totalPointsCount += cpc;
    }
    vector<double> results(pc);
    
    sort(participants.begin(), participants.end());
    
    for (int i = 0; i < pc; i++)
    {
        results[participants[i].second] = participants[i].first;
    }
    
    double usedPoints = totalPointsCount;
    double lowValue = results[participants[0].second];
    
    for(int i = 0, iEnd = pc - 1; i < iEnd; i++)
    {
        double inc = results[participants[i+1].second] - lowValue;
        if (inc * (i+1) > usedPoints)
            inc = usedPoints / (i+1);
        usedPoints -= inc * (i+1);
        lowValue += inc;
    }
    
    lowValue += usedPoints / pc;
    
    printf("Case #%d:", testNo+1);
    
    for (int i = 0; i < pc; i++)
    {
        double valToPrint = lowValue - results[i];
        valToPrint /= totalPointsCount;
        valToPrint *= 100;
        if (valToPrint < 0.000000001)
            valToPrint = 0.0;
        printf(" %.6lf", valToPrint);
    }
    printf("\n");
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    
    for (int i = 0; i < TC; i++)
        test(i);
    
    return 0;
}

