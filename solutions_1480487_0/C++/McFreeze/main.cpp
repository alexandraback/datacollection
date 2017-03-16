// Mike Terranova
// Compiled with MS Visual Studio 2010
// May 5, 2012

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>

using namespace std;
using namespace std::placeholders;

typedef __int64 int64;

int main()
{
    ofstream outfile("out.txt");

    int numCases;
    cin >> numCases;

    for (int i = 1; i <= numCases; i++)
    {
        int numContestants;
        cin >> numContestants;

        vector<int> scores;
        int scoreSum = 0;
        for (int j = 0; j < numContestants; j++)
        {
            int score;
            cin >> score;
            scores.push_back(score);
            scoreSum += score;
        }

        vector<bool> needed;
        int neededCount = 0;
        int neededSum = 0;
        for (int x = 0; x < numContestants; x++)
        {
            // There will be twice as many points in the system at the end
            double currentPercent = scores[x] / (scoreSum * 2.0);

            // You must have at least 1/n to guarantee not losing.
            double targetPercent = 1.0 / scores.size();

            needed.push_back(currentPercent < targetPercent);
            if (needed[x])
            {
                neededCount++;
                neededSum += scores[x];
            }
        }

        vector<double> percentsNeeded;
        for (int y = 0; y < numContestants; y++)
        {
            if (!needed[y])
            {
                percentsNeeded.push_back(0.0);
                continue;
            }

            // There will be twice as many points in the system at the end
            double currentPercent = (double)scores[y] / (scoreSum + neededSum);

            // You must have at least 1/n to guarantee not losing.
            double targetPercent = 1.0 / neededCount;

            double diff = targetPercent - currentPercent;
            if (diff < 0.0)
            {
                diff = 0;
            }

            double multiplier = ((scoreSum + neededSum) / (double)scoreSum) * 100;
            percentsNeeded.push_back(diff * multiplier);
        }
        

        outfile << "Case #" << i << ": "; 
        
        for (int z = 0; z < numContestants; z++)
        {
            outfile << fixed << setprecision(6) << percentsNeeded[z] << " ";
        }
        
        outfile << endl;
    }

    outfile.close();
    return 0;
}

