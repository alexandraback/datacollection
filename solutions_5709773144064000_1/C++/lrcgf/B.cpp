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

    out << setprecision(14);

    string line;
    getline(in, line);
    int nLines = boost::lexical_cast<int>(line); 

    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
        long double C, F, X;
        in >> C >> F >> X;

        long double production = 2;

        long double timeToReturnOfInvestment = C / F;

        long double time = 0.0;

        while (true)
        {
            long double timeToX = X / production;
            long double timeToC = C / production;
            if (timeToX <= timeToC + timeToReturnOfInvestment)
            {
                time += timeToX;
                break;
                // finished
            }
            else
            {
                time += timeToC;
                production += F;
            }
        }

        out << "Case #" << caseNo+1 << ": ";
        out << time;
        out << endl;
    }


    return 0;
}

