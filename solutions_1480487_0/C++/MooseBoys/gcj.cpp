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

    if(getProblemIO(input,output)) return -1;
    cout<<fixed<<setprecision(16);
    output<<fixed<<setprecision(16);

	int T;
    input>>T;
    for(int caseNum=0;caseNum<T;caseNum++)
    {
        // For each Ji, find Yi such that it brings the score to "even" i.e. 2 * X / N.
        // Solve: Ji + X * Yi = 2 * X / N
        // Yi = 2 / N - Ji / X

        int N;
        input>>N;
        ImportantMessage("N="<<N);

        vector<unsigned long long> scores(N);
        unsigned long long X = 0;
        for(int i=0;i<N;i++)
        {
            unsigned long long j;
            input>>j;
            X += j;
            scores[i] = j;
        }


        vector<double> ans(N);
        for(int i=0;i<N;i++)
        {
            ans[i] = 100.0 * (2.0 / (double)N - (double)scores[i] / (double)X);
        }

        // propagate negative probabilities
        int positiveN = N;
        bool madeAdjustment = true;
        vector<bool> cantFail(N);
        for(int i=0;i<N;i++) cantFail[i] = false;
        while(madeAdjustment)
        {
            double sum = 0.0;
            for(int i=0;i<N;i++) sum += ans[i] / 100.0;
            ImportantMessage("SUM = "<<sum);

            madeAdjustment = false;
            double adjustment = 0.0;
            for(int i=0;i<N&&!madeAdjustment;i++)
            {
                if(ans[i] < 0.0)
                {
                    madeAdjustment = true;
                    cantFail[i] = true;
                    positiveN--;
                    adjustment = ans[i] / (double)positiveN;
                    ans[i] = 0.0;
                }
            }
            if(madeAdjustment)
            {
                for(int i=0;i<N;i++)
                {
                    if(!cantFail[i]) ans[i] += adjustment;
                }
            }
        }

        output<<"Case #"<<caseNum+1<<": ";
        for(int i=0;i<N;i++)
        {
            output<<ans[i];
            if(i<N-1) output<<" ";
        }
        output<<endl;
        GoodMessage("Case #"<<caseNum+1<<": "<<"-done-");
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
