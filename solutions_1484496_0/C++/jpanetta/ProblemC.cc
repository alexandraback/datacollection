////////////////////////////////////////////////////////////////////////////////
// ProblemC.cc
////////////////////////////////////////////////////////////////////////////////
/*! @file
//        Solves Google Code Jam 2012 Round 1B Problem C
//        Brute-force subset sum :(
*/ 
//  Author:  Julian Panetta (jpanetta), julian.panetta@gmail.com
//  Company:  New York University
//  Created:  05/05/2012 11:58:59
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <tr1/unordered_map>
#include <list>
#include <vector>

typedef unsigned int uint;
using namespace std;
using namespace std::tr1;

uint getSum(uint s, vector<uint> &S)
{
    uint sum = 0;
    for (int i = 0; i < 20; ++i) {
        if (s & (1 << i)) {
            sum += S[i];
        }
    }
    return sum;
}

void printSubset(uint s, vector<uint> &S)
{
    bool first = true;
    for (int i = 0; i < 20; ++i) {
        if (s & (1 << i)) {
            cout << (first ? "" : " ") << S[i];
            first = false;
        }
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////
/*! Program entry pouint
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on sucess)
*///////////////////////////////////////////////////////////////////////////////
int main(uint argc, const char *argv[])
{
    uint T; cin >> T;
    for (uint test = 1; test <= T; ++test)  {
        uint N;
        cin >> N;
        vector<uint> S(N);
        for (uint i = 0; i < N; ++i)
            cin >> S[i];

        typedef unordered_map<uint, uint> Hashtable;
        typedef Hashtable::iterator Hit;

        cout << "Case #" << test << ":" << endl;

        Hashtable subsetTable;

        bool success = false;
        for (uint s = 0; s < (1 << 20); ++s) {
            uint sum = getSum(s, S);
            Hit loc = subsetTable.find(sum);
            if (loc != subsetTable.end()) {
                printSubset(loc->second, S);
                printSubset(s, S);
                success = true;
                break;
            }
            else {
                subsetTable.insert(make_pair(sum, s));
            }
        }

        if (!success)
        cout << "Impossible" << endl;

    }

    return 0;
}
