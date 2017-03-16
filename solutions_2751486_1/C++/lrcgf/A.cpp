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
    // ifstream in("in");
    //ofstream out("A-large-1.out");
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    int nLines = boost::lexical_cast<int>(line); 

    char text[1000000];

    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
        out << "Case #" << caseNo+1 << ": ";
        int textCount = 0;
        int inText;
        while ((inText = in.get()) != ' ')
        {
            if (inText == 'a' || inText == 'e' || inText == 'u' || inText == 'i' || inText == 'o')
            {
                text[textCount] = 0;
            }
            else
            {
                text[textCount] = 1;
            }
            textCount++;
        }

        int n;
        in >> n;
        getline(in, line);

        long totalCount = 0;

        int lastmatch = -1;
        int numberOfOnes = 0;
        for (int i=0; i < textCount; ++i)
        {
            if (text[i] == 1)
            {
                numberOfOnes++;
                if (numberOfOnes >= n)
                {
                    long extra = (i - lastmatch - n + 1) * (textCount - i);
                    totalCount += extra;
                    lastmatch = i - n + 1;
                }
            }
            else
            {
                numberOfOnes = 0;
            }
        }

        out << totalCount;

        out << endl;
    }


    return 0;
}

