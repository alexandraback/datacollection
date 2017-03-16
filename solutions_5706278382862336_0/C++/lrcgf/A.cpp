#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

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
        out << "Case #" << caseNo+1 << ": ";

        unsigned long long int p, q;
        char slash;
        in >> p >> slash >> q;

        unsigned long long int max = ((long long int)1) << 40;


        bool isIllegal = false;
        
        unsigned long long int test = max * p;
        isIllegal = test % q != 0;


        if (isIllegal)
        {
            out << "impossible";
        }
        else
        {
            unsigned int count = 1;
            unsigned long long int divider = (q-1) / p;
            while (divider >>= 1) {
                count++;
            }
            out << count;
        }
         
        
        out << endl;
    }


    return 0;
}

