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
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cassert>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include "Windows.h"
//#include "BigIntegerLibrary.hh"         // from http://mattmccutchen.net/bigint/
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


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    // small dataset small enough for slow algorithm

    if(getProblemIO(input,output)) return -1;

	int T;
    input>>T;
    for(int caseNum=0;caseNum<T;caseNum++)
    {
        int N;
        input>>N;
        ImportantMessage("N="<<N);

        vector<int> r1(N);
        vector<int> r2(N);
        vector<int> s(N);

        for(int i=0;i<N;i++)
        {
            input>>r1[i];
            input>>r2[i];
            s[i] = 0;
        }

        int stars = 0;
        int plays = 0;

        if(caseNum+1==68)
        {
            ImportantMessage("BUG!");
        }

        bool stuck = false;
        while(stars < 2 * N && !stuck)
        {
            bool madePlay = false;

            int bestI;
            int bestS;
            int bestSb;

            // largest completable 2-star with 1 star
            bestI = -1;
            bestS = -1;
            bestSb = -1;
            for(int i=0;i<N;i++)
            {
                if(r2[i]<=stars && r2[i]>=bestS && s[i]==1)
                {
                    bestS = r2[i];
                    bestI = i;
                }
            }
            if(bestI != -1)
            {
                stars += 1;
                s[bestI] = 2;
                ImportantMessage("Earned 2 stars (+1) on level "<<bestI);
                plays++;
                madePlay = true;
                continue;
            }

            // largest completable 2-star with 0 stars
            bestI = -1;
            bestS = -1;
            bestSb = -1;
            for(int i=0;i<N;i++)
            {
                if(r2[i]<=stars && (r2[i]>bestS || r2[i]==bestS && r1[i]>=bestSb) && s[i]==0)
                {
                    bestS = r2[i];
                    bestSb = r1[i];
                    bestI = i;
                }
            }
            if(bestI != -1)
            {
                stars += 2;
                s[bestI] = 2;
                ImportantMessage("Earned 2 stars (+2) on level "<<bestI);
                plays++;
                madePlay = true;
                continue;
            }

            // completable 1-star with 0 stars with largest 2-star required
            bestI = -1;
            bestS = -1;
            bestSb = -1;
            for(int i=0;i<N;i++)
            {
                if(r1[i]<=stars && (r2[i]>bestS || r2[i]==bestS && r1[i]>bestSb) && s[i]==0)
                {
                    bestS = r2[i];
                    bestSb = r1[i];
                    bestI = i;
                }
            }
            if(bestI != -1)
            {
                stars += 1;
                s[bestI] = 1;
                ImportantMessage("Earned 1 star (+1) on level "<<bestI);
                plays++;
                madePlay = true;
                continue;
            }

            if(!madePlay) stuck = true;
        }
        if(stuck)
        {
            output<<"Case #"<<caseNum+1<<": "<<"Too Bad"<<endl;
            GoodMessage("Case #"<<caseNum+1<<": "<<"Too Bad");
        }
        else
        {
            output<<"Case #"<<caseNum+1<<": "<<plays<<endl;
            GoodMessage("Case #"<<caseNum+1<<": "<<plays);
        }
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
