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

typedef std::vector<double> StonesVec;

void readOnePileOfStones(std::ifstream& fin, StonesVec& stones, int stoneNumber)
{
    std::string line;
    // read stones;
    getline(fin, line);
    if (line.empty())
    {
        return;
    }

    std::stringstream sss(line);
    stones.resize(stoneNumber);
    double stoneWeight;
    for (int i = 0; i < stoneNumber; ++i)
    {
        sss >> stoneWeight;
        stones[i] = stoneWeight;
    }
}

// calculate how many element in left is bigger than in right.
int calcBiggerElemCount(const StonesVec& left, const StonesVec& right)
{
    size_t length = left.size();
    int biggerCount = 0;
    for (auto v : left)
    {
        if (v > right[biggerCount])
        {
            biggerCount++;
        }
    }
    return biggerCount;
}

void testWar()
{
    // read case number
    std::ifstream fin("E:/testdata/war/D-small-attempt0.in");
    std::string line;
    getline(fin, line);
    std::stringstream ss(line);
    int caseNumber;
    ss >> caseNumber;
    if (caseNumber <= 0)
    {
        return;
    }

    std::ofstream fout("E:/testdata/war/D-small-attempt0.in.out");
    for (int i = 1; i <= caseNumber; ++i)
    {
        // for one case.

        // read stone number;
        std::string line;
        getline(fin, line);
        if (line.empty())
        {
            return;;
        }
        int stoneNumber;
        std::stringstream ss(line);
        ss >> stoneNumber;
        if (stoneNumber <= 0)
        {
            return;
        }

        // read stones;
        StonesVec naomi, ken;
        readOnePileOfStones(fin, naomi, stoneNumber);
        readOnePileOfStones(fin, ken, stoneNumber);
        std::sort(naomi.begin(), naomi.end());
        std::sort(ken.begin(), ken.end());

        fout << "Case #" << i << ": " << calcBiggerElemCount(naomi, ken) << " " << stoneNumber - calcBiggerElemCount(ken, naomi) << std::endl;
    }
    fin.close();
    fout.close();
}

int main()
{
    testWar();
    return 0;
}