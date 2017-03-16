#include <iostream>
#include <fstream>
#include <sstream>
#include<iomanip>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

#include <algorithm>

double getMinCost(double CmileStone, double Fstep, double Xtarget)
{
    double speed = 2.0, mileStoneCost = 0;
    double lastCost = Xtarget / speed;
    double waitForMore = lastCost;
    while (waitForMore <= lastCost)
    {
        lastCost = waitForMore;
        mileStoneCost += CmileStone / speed;
        speed += Fstep;
        waitForMore = mileStoneCost + Xtarget / speed;
    }

    return lastCost;
}

void testClicker()
{
    // read case number
    std::ifstream fin("E:/testdata/clicker/B-large.in");
    std::string line;
    getline(fin, line);
    std::stringstream ss(line);
    int caseNumber;
    ss >> caseNumber;
    if (caseNumber <= 0)
    {
        return;
    }

    std::ofstream fout("E:/testdata/clicker/B-large.out");
    for (int i = 1; i <= caseNumber; ++i)
    {
        // for one case.
        getline(fin, line);
        if (line.empty())
        {
            continue;
        }
        double C, F, X;
        std::stringstream ss(line);
        ss >> C >> F >> X;

        fout << std::fixed <<std::setprecision(7) << "Case #" << i << ": " << getMinCost(C, F, X) << std::endl;
    }
    fin.close();
    fout.close();
}

int main()
{
    testClicker();
    return 0;
}