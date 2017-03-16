////////////////////////////////////////////////////////////////
//                                                            //
//  Google Code Jam Template                                  //
//  by MooseBoys                                              //
//                                                            //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////
//                                            //
//  Generic Code                              //
//                                            //
////////////////////////////////////////////////

////////////////////////////////
//  Standard Includes         //
////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <map>
#include <functional>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
//#include "BigInteger\\BigIntegerLibrary.hh"         // from http://mattmccutchen.net/bigint/
//#include "boost/math/common_factor.hpp" // from http://www.boost.org/


////////////////////////////////
//  Typedefs and Macros       //
////////////////////////////////

typedef long long           LL;
typedef unsigned long long  ULL;


////////////////////////////////
//  Debug Helpers             //
////////////////////////////////

// colored console messages
#define GoodMessage(message) {setColor(GOOD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define BadMessage(message) {setColor(BAD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define ImportantMessage(message) {setColor(IMPORTANT);std::cout<<message<<std::endl;setColor(NORMAL);}
enum consoleColor{ NORMAL, GOOD, BAD, IMPORTANT };
inline void setColor(consoleColor c)
{
    WORD wAttributes = 0x07;
    if (c == GOOD) wAttributes = 0x0A;
    if (c == BAD) wAttributes = 0x0C;
    if (c == IMPORTANT) wAttributes = 0xF9;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
}


////////////////////////////////
//  Common Functions          //
////////////////////////////////

// find and open a problem input
int loadProblemFile(std::ifstream &inputFile, std::string &inputFileName)
{
    for (char cProblem = 'A'; cProblem <= 'Z'; cProblem++)
    {
        inputFileName = std::string(1, cProblem) + "-test";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        inputFileName = std::string(1, cProblem) + "-large";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        for (char cAttempt = '9'; cAttempt >= '0'; cAttempt--)
        {
            inputFileName = std::string(1, cProblem) + "-small-attempt" + cAttempt;
            inputFile.open(inputFileName + ".in", std::ifstream::in);
            if (inputFile.is_open()) return 0;
        }
    }
    return -1;
}

// load and create problem input and output streams
int getProblemIO(std::ifstream &input, std::ofstream &output)
{
    std::string fileName;
    if (loadProblemFile(input, fileName)){ BadMessage("could not find any input files to load"); return -1; }
    else{ GoodMessage("successfully loaded input file \"" << fileName << ".in\""); }
    output.open(fileName + ".out", std::ofstream::out);
    if (output.is_open()){ GoodMessage("successfully created output file \"" << fileName << ".out\""); }
    else{ BadMessage("could not create output file \"" << fileName << ".out\""); return -1; }
    return 0;
}

// Big Integer class


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

#define TEST FALSE

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

#if TEST
    for(int R = 1; R <= 5; R++)
    {
        for(int C = 1; C <=5; C++)
        {
            for (int M = 0; M < R * C; M++)
            {
#else
    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        int R, C, M;
        input >> R >> C >> M;
#endif

        // looking at non-mine space, 1x1 is clearly solveable
        // otherwise, solution exists if space can form MxN rectangle where M>1 and N>1, or any extra 2..N or 2..M space requirements
        // assuming room in the other direction; examples:

        // 1:
        // c

        // 4:
        // c .
        // . .

        // 6:
        // c 0 .
        // . . .

        // 8:
        // c 0 .
        // 0 . .
        // . .

        // 9:
        // c 0 .
        // 0 0 .
        // . . .

        // proposed solution looks for each open space row span M in 2..R-1, and appropriate N to get close to but not exceed space requirements
        // if N > 1 && N <= C && remainder >= 2, there is a solution and it is trivial to generate (example above). seems like this should cover all solutions

        int spaceRequired = R * C - M;

        string gridRow(C, '*');
        vector<string> grid(R, gridRow);

        bool solved = false;

        if (spaceRequired == 1)
        {
            solved = true;
        }
        else if (R == 1)
        {
            for (int i = 1; i < spaceRequired; i++) grid[0][i] = '.';
            solved = true;
        }
        else if (C == 1)
        {
            for (int i = 1; i < spaceRequired; i++) grid[i][0] = '.';
            solved = true;
        }
        else
        {
            // note: reversing search order from description above
            for (int width = 2; width <= C && !solved; width++)
            {
                int height = spaceRequired / width;
                int remainder = spaceRequired - width * height;
                // input of 4x4 with 3 mines broke this; need to allow for remainder == 1 if height > 2, so we can pull the corner piece to reach the new row
                if ((remainder != 1 || remainder == 1 && height > 2 && width > 2) && height >= 2 && (height < R || height == R && remainder == 0))
                {
                    for (int i = 0; i < height; i++)
                    {
                        for (int j = 0; j < width; j++)
                        {
                            grid[i][j] = '.';
                        }
                    }
                    if (remainder == 1)
                    {
                        grid[height - 1][width - 1] = '*';
                        grid[height][0] = '.';
                        grid[height][1] = '.';
                    }
                    else
                    {
                        for (int i = 0; i < remainder; i++)
                        {
                            grid[height][i] = '.';
                        }
                    }
                    solved = true;
                }
            }
        }

        // always click in top-left corner
        grid[0][0] = 'c';

#if TEST
        output << "TEST CASE: " << R << "x" << C << " + " << M << endl;
#else
        output << "Case #" << caseNum + 1 << ":" << endl;
#endif
        if (solved)
        {
            for (auto row : grid)
            {
                output << row << endl;
            }
        }
        else
        {
            output << "Impossible" << endl;
        }
#if TEST
    }}}
#else
        // TODO - really need to make this an object that directs to both stdout and the file
        GoodMessage("Case #" << caseNum + 1 << ": " << "[complete]");
    }
#endif

    return 0;
}

////////////////////////////////////////////////
//                                            //
//  Generic Entrypoint                        //
//                                            //
////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    int ret = CodeJamMain();
    if (ret == 0){ GoodMessage(">>>> SUCCESS <<<<"); }
    else{ BadMessage(">>>> FAILURE <<<<"); }
    system("pause");
    return ret;
}
