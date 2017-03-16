#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;


int main(int argc, char** argv)
{
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    int nLines = boost::lexical_cast<int>(line); 

    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
        int nBlocks;
        in >> nBlocks;

        list<double> blocksKen;
        list<double> blocksNaomi;

        for (int i = 0; i<nBlocks; ++i)
        {
            double block;
            in >> block;
            blocksNaomi.push_back(block);
        }
        for (int i = 0; i<nBlocks; ++i)
        {
            double block;
            in >> block;
            blocksKen.push_back(block);
        }

        blocksKen.sort();
        blocksNaomi.sort();

        int deceitWins = 0;
        auto naomiIter = blocksNaomi.rbegin();
        for (auto kenIter = blocksKen.rbegin(); kenIter != blocksKen.rend(); ++kenIter)
        {
            if (*naomiIter > *kenIter)
            {
                ++deceitWins;
                ++naomiIter;
            }
        }

        int warWins = 0;
        auto kenIter = blocksKen.rbegin();
        for (auto naomiIter = blocksNaomi.rbegin(); naomiIter != blocksNaomi.rend(); ++naomiIter)
        {
            if (*naomiIter > *kenIter)
            {
                ++warWins;
            }
            else
            {
                ++kenIter;
            }
        }


        out << "Case #" << caseNo+1 << ": ";
        out << deceitWins << " " << warWins;
        out << endl;
    }


    return 0;
}

