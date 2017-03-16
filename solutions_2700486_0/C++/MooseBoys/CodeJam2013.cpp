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
#include <algorithm>
#include <cassert>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
#include "BigInteger\\BigIntegerLibrary.hh"         // from http://mattmccutchen.net/bigint/
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
enum consoleColor{NORMAL,GOOD,BAD,IMPORTANT};
inline void setColor(consoleColor c)
{
    WORD wAttributes = 0x07;
    if(c==GOOD) wAttributes = 0x0A;
    if(c==BAD) wAttributes = 0x0C;
    if(c==IMPORTANT) wAttributes = 0xF9;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wAttributes);
}


////////////////////////////////
//  Common Functions          //
////////////////////////////////

// find and open a problem input
int loadProblemFile(std::ifstream &inputFile, std::string &inputFileName)
{
    for(char cProblem='A';cProblem<='Z';cProblem++)
    {
        inputFileName = std::string(1,cProblem)+"-test";
        inputFile.open(inputFileName+".in",std::ifstream::in);
        if(inputFile.is_open()) return 0;
        inputFileName = std::string(1,cProblem)+"-large";
        inputFile.open(inputFileName+".in",std::ifstream::in);
        if(inputFile.is_open()) return 0;
        for(char cAttempt='9';cAttempt>='0';cAttempt--)
        {
            inputFileName = std::string(1,cProblem)+"-small-attempt"+cAttempt;
            inputFile.open(inputFileName+".in",std::ifstream::in);
            if(inputFile.is_open()) return 0;
        }
    }
    return -1;
}

// load and create problem input and output streams
int getProblemIO(std::ifstream &input, std::ofstream &output)
{
    std::string fileName;
    if(loadProblemFile(input,fileName)){BadMessage("could not find any input files to load");return -1;}
    else{GoodMessage("successfully loaded input file \""<<fileName<<".in\"");}
    output.open(fileName+".out",std::ofstream::out);
    if(output.is_open()){GoodMessage("successfully created output file \""<<fileName<<".out\"");}
    else{BadMessage("could not create output file \""<<fileName<<".out\"");return -1;}
    return 0;
}

// Big Integer class


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

ULL ncr(ULL n, ULL r)
{
    if(r == 0) return 1;
    if(n == 0) return 0;
    return ncr(n-1,r-1) + ncr(n-1,r);
}

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if(getProblemIO(input,output)) return -1;
    cout<<fixed<<setprecision(16);
    output<<fixed<<setprecision(16);

	int T;
    input>>T;
    for(int caseNum=0;caseNum<T;caseNum++)
    {
        int N,X,Y;
        input>>N>>X>>Y;

        double answer = -1.0;

        int pyramidBase = 1;
        int pyramidSize = 1;
        while(pyramidSize + pyramidBase * 2 + 3 <= N)
        {
            pyramidSize += pyramidBase * 2 + 3;
            pyramidBase += 2;
        }

        if(abs(X)+abs(Y) <= pyramidBase - 1)
        {
            answer = 1.0; // inside the pyramid
        }
        else if(abs(X) + abs(Y) > pyramidBase + 1)
        {
            answer = 0.0; // outside the partial edges
        }
        else
        {
            // on a partially covered edge
            int partialDiamonds = N - pyramidSize;
            if(Y >= partialDiamonds)
            {
                answer = 0.0; // can't reach this high
            }
            else if(Y == pyramidBase + 1)
            {
                // would have been in a full pyramid if it's possible
                answer = 0.0;
            }
            else if(partialDiamonds - pyramidBase - 2 >= Y)
            {
                // guaranteed to spill over
                answer = 1.0;
            }
            else
            {
                // answer = CDF(binomial((Y+1) of partialDiamonds trials)
                answer = 0.0;
                for(int i = Y; i < partialDiamonds; i++)
                {
                    answer += ncr(partialDiamonds,i+1) * pow(0.5,partialDiamonds);
                }
            }
        }

        output<<"Case #"<<caseNum+1<<": ";
        output<<answer<<endl;
        GoodMessage("Case #"<<caseNum+1<<": "<<answer);
    }

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
    if(ret==0){GoodMessage(">>>> SUCCESS <<<<");}
    else{BadMessage(">>>> FAILURE <<<<");}
    system("pause");
    return ret;
}
