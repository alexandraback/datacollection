////////////////////////////////////////////////////////////////////////////////
// ProblemC.cc
////////////////////////////////////////////////////////////////////////////////
/*! @file
//        Solves Google Code Jam 2012 Round 1C Problem C
*/ 
//  Author:  Julian Panetta (jpanetta), julian.panetta@gmail.com
//  Company:  New York University
//  Created:  05/06/2012 5:00:00
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <vector>
#include <cfloat>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long int uli;

////////////////////////////////////////////////////////////////////////////////
/*! Program entry point
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on sucess)
*///////////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[])
{
    int T; cin >> T;
    for (int test = 1; test <= T; ++test)  {
        uint N, M;
        cin >> N >> M;
        vector<uli> ToyCount(N), ToyType(N), BoxCount(M), BoxType(M);
        
        for (unsigned int i = 0; i < N; ++i) {
            cin >> ToyCount[i];
            cin >> ToyType[i];
        }

        for (unsigned int i = 0; i < M; ++i) {
            cin >> BoxCount[i];
            cin >> BoxType[i];
        }

        // Brute force for small:
        // check all possible M possible places for switching toys
        uli maxBoxed = 0;
        for (uint i = 0; i <= M; ++i) {
            for (uint j = i; j <= M; ++j) {
                vector<uli> TmpToyCount(ToyCount), TmpBoxCount(BoxCount);
                uli numBoxed = 0;
                for (uint b = 0; b < M; ++b) {
                    if (b <= i) {
                        if (ToyType[0] == BoxType[b]) {
                            uli numToBox = min(TmpToyCount[0], TmpBoxCount[b]);
                            numBoxed += numToBox;
                            TmpToyCount[0] -= numToBox;
                            TmpBoxCount[b] -= numToBox;
                        }
                    }
                    if ((b >= i) && (b <= j)) {
                        if (ToyType[1] == BoxType[b]) {
                            uli numToBox = min(TmpToyCount[1], TmpBoxCount[b]);
                            numBoxed += numToBox;
                            TmpToyCount[1] -= numToBox;
                            TmpBoxCount[b] -= numToBox;
                        }
                    }
                    if (b >= j) {
                        if (ToyType[2] == BoxType[b]) {
                            uli numToBox = min(TmpToyCount[2], TmpBoxCount[b]);
                            numBoxed += numToBox;
                            TmpToyCount[2] -= numToBox;
                            TmpBoxCount[b] -= numToBox;
                        }
                    }
                }

                maxBoxed = max(maxBoxed, numBoxed);
            }
        }

        cout << "Case #" << test << ": " << maxBoxed << endl;
    }
    return 0;
}
