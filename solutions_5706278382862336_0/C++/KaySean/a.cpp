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
typedef unsigned long long ull;
typedef unsigned int uint;

int calc(ull son, ull mom)
{
    int tmpminone = 0, minone = -1;
    for (int i = 0; i < 40; ++i)
    {
        if (mom == son)
        {
            return minone;
        }
        else if (mom > son) // less 1;
        {
            ull left = mom % 2;
            // can't divide by 2;
            if (left != 0)
            {
                return -1;
            }
            tmpminone++;
            mom /= 2;
            if (mom == son)
            {
                if (minone == -1)
                {
                    minone = tmpminone;
                }
            }
        }
        else // more 1;
        {
            son -= mom;
            if (minone == -1)
            {
                minone = tmpminone;
            }
        }
    }
    return minone;
}

void split(std::vector<std::string> & stringVector, std::string & inputString, char splitor)
{
    std::string::size_type start, end;
    end = inputString.find(splitor);
    start = 0;
    while (std::string::npos != end)
    {
        stringVector.push_back(inputString.substr(start, end - start));
        start = end + 1;
        end = inputString.find(splitor, start);
    }
    stringVector.push_back(inputString.substr(start));
}

void testClickera()
{
    // read case number
    std::ifstream fin("E:/1C/A/A-small-attempt0.in");
    std::string line;
    getline(fin, line);
    std::stringstream ss(line);
    int caseNumber;
    ss >> caseNumber;
    if (caseNumber <= 0)
    {
        return;
    }

    std::ofstream fout("E:/1C/A/A-small-attempt0.out");
    for (int i = 1; i <= caseNumber; ++i)
    {
        // for one case.
        getline(fin, line);
        if (line.empty())
        {
            continue;
        }
        std::vector<std::string> svec;
        split(svec, line, '/');
        std::stringstream son(svec[0]);
        std::stringstream mom(svec[1]);
        ull llson, llmom;
        son >> llson;
        mom >> llmom;

        int result = calc(llson, llmom);
        if (result <= 0)
        {
            fout << "Case #" << i << ": " << "impossible"<< std::endl;
        }
        else
        {
            fout << "Case #" << i << ": " << result << std::endl;
        }
    }
    fin.close();
    fout.close();
}

int main()
{
    testClickera();
    return 0;
}