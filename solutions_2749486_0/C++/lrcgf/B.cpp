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
    // ifstream in("in");
    //ofstream out("A-large-1.out");
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    int nLines = boost::lexical_cast<int>(line); 

    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
        int x, y;
        in >> x >> y;


        out << "Case #" << caseNo+1 << ": ";

        while (x > 0)
        {
            out << "WE";
            x--;
        }
        while (x < 0)
        {
            out << "EW";
            x++;
        }
        while (y < 0)
        {
            out << "NS";
            y++;
        }
        while (y > 0)
        {
            out << "SN";
            y--;
        }
        out << endl;
    }


    return 0;
}

