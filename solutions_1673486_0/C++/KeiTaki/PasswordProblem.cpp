
#define IN_FILE "PasswordProblem_sm"  // ex, test, sm, lg, 
#define IN_FILE_EXT ".in"
#define OUT_FILE_EXT ".out"

#define READ_BUFSIZE 0x10000

#include <string>

#include <fstream>
#include <iostream>

#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include <conio.h>
#include <direct.h>
#include <tchar.h>

#include "Shared.h"
#include "Limits.h"

// boost
//#include <boost/dynamic_bitset.hpp>

using namespace std;
//using namespace boost;

//-----------------------------------------------------------------------------
struct QUIZ_DATA
{
    unsigned int Typed;
    unsigned int Length;

    vector<double> Probs;
};

//-----------------------------------------------------------------------------
typedef vector<QUIZ_DATA> QUIZ_DATASET;

//-----------------------------------------------------------------------------
void Process(unsigned int iTestCases, vector<string>& rvLines, QUIZ_DATASET& rvQuizData)
{
    unsigned int iLn = 0;
    rvQuizData.resize(iTestCases);

    for (unsigned int i = 0; i < iTestCases; i++)
    {
        vector<unsigned int> vi;
        Split(rvLines[iLn], " ", vi);

        rvQuizData[i].Typed = vi[0];
        rvQuizData[i].Length = vi[1];

        iLn++;

        Split(rvLines[iLn], " ", rvQuizData[i].Probs); 

        iLn++;
    }

}
//-----------------------------------------------------------------------------
void Solve(QUIZ_DATA& rData, ostream& rOutput)
{
    unsigned int tp = rData.Typed;
    unsigned int len = rData.Length;

    vector<double> cum = rData.Probs;

    for (unsigned int i = 1; i < tp; i++)
    {
        cum[i] *= cum[i - 1];
    }

    double dFinish = (len - tp + 1) * cum[tp - 1] + (len - tp + 1 + len + 1) * (1.0 - cum[tp - 1]);
    double dGiveUp = 1 + len + 1;

    double dMin = min(dFinish, dGiveUp);

    for (unsigned int iBack = 1; iBack <= tp; iBack++)
    {
        double dFix;

        if (iBack < tp)
        {
            dFix = (double)(iBack * 2 + len - tp + 1) * cum[tp - 1 - iBack] + (double)(iBack * 2 + len - tp + 1 + len + 1) * (1.0 - cum[tp - 1 - iBack]);
        }
        else
        {
            dFix = (iBack * 2 + len - tp + 1);
        }

        dMin = min(dFix, dMin);
    }

    rOutput.precision(10);
    cout.precision(10);

    rOutput << dMin;
    cout << dMin;
}
//-----------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifs("DataFiles\\" IN_FILE IN_FILE_EXT);
    ofstream ofs("DataFiles\\" IN_FILE OUT_FILE_EXT);

    char* pBuf = new char[READ_BUFSIZE];

    if (ifs.is_open() && ofs.is_open())
    {
        ifs.getline(pBuf, READ_BUFSIZE);

        unsigned int iTestCases = strtoul(pBuf, NULL, 0);

        vector<string> vsLines;
        vsLines.reserve(400); // random guess

        while (!ifs.eof())
        {
            ifs.getline(pBuf, READ_BUFSIZE);

            if (strlen(pBuf) > 0)
            {
                vsLines.push_back(pBuf);
            }
        }

        QUIZ_DATASET dataset;

        Process(iTestCases, vsLines, dataset);

        for (unsigned int i = 0; i < iTestCases; i++)
        {
            ofs << "Case #" << i + 1 << ": ";  
            cout << "Case #" << i + 1 << ": ";  

            Solve(dataset[i], ofs);

            ofs << endl;
            cout << endl;
        }
    }
    else
    {
        _getcwd(pBuf, READ_BUFSIZE);
        cout << "Check file path: " << pBuf << '\\' << IN_FILE << endl;
    }

    ofs.close();
    ifs.close();

    delete[] pBuf;

    getch();

	return 0;
}


