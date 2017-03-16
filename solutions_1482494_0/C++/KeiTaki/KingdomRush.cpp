
#define IN_FILE "KingdomRush_sm"  // ex, test, sm, lg, 
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
struct Level
{
    unsigned int LowRating;
    unsigned int HighRating;
    bool LowCompleted;
    bool HighCompleted;
};

//-----------------------------------------------------------------------------
typedef vector<Level*> QUIZ_DATA;

//-----------------------------------------------------------------------------
typedef vector<QUIZ_DATA> QUIZ_DATASET;

//-----------------------------------------------------------------------------
void Process(unsigned int iTestCases, vector<string>& rvLines, QUIZ_DATASET& rvQuizData)
{
    unsigned int iCur = 0;

    for (unsigned int i = 0; i < iTestCases; i++)
    {
        QUIZ_DATA data;

        unsigned int iNumLevels = strtoul(rvLines[iCur].c_str(), NULL, 10);
        iCur++;

        for (unsigned int j = 0; j < iNumLevels; j++)
        {
            Level* pLevel = new Level();

            vector<unsigned int> viRates;
            Split(rvLines[iCur], " ", viRates);

            pLevel->LowRating = viRates[0];
            pLevel->HighRating = viRates[1];
            pLevel->LowCompleted = false;
            pLevel->HighCompleted = false;

            data.push_back(pLevel);

            iCur++;
        }

        rvQuizData.push_back(data);
    }

}

//-----------------------------------------------------------------------------
bool CompareLow(Level* p1, Level* p2)
{
    return p1->LowRating < p2->LowRating;
}
//-----------------------------------------------------------------------------
bool CompareHigh(Level* p1, Level* p2)
{
    return p1->HighRating < p2->HighRating;
}

//-----------------------------------------------------------------------------
void Solve(QUIZ_DATA& rData, ostream& rOutput)
{
    unsigned int iSize = rData.size();

    QUIZ_DATA data1 = rData;
    QUIZ_DATA data2 = rData;

    sort(data1.begin(), data1.end(), CompareLow);
    sort(data2.begin(), data2.end(), CompareHigh);

    unsigned int iCompleted = 0;
    unsigned int iStar = 0;

    bool bGotNext = true;

    while (bGotNext)
    {
        bGotNext = false;

        for (unsigned int i = 0; i < iSize; i++)
        {
            if (!data2[i]->HighCompleted && !data2[i]->LowCompleted && data2[i]->HighRating <= iStar)
            {
                data2[i]->HighCompleted = true;
                data2[i]->LowCompleted = true;
                iStar += 2;
                iCompleted++;
                bGotNext = true;
                break;
            }
        }

        if (!bGotNext)
        {
            for (unsigned int i = 0; i < iSize; i++)
            {
                if (!data2[i]->HighCompleted && data2[i]->LowCompleted && data2[i]->HighRating <= iStar)
                {
                    data2[i]->HighCompleted = true;
                    iStar += 1;
                    iCompleted++;
                    bGotNext = true;
                    break;
                }
            }
        }

        if (!bGotNext)
        {
            int iTry = -1;
            unsigned int iHigh = 0;

            for (unsigned int i = 0; i < iSize; i++)
            {
                if (!data1[i]->LowCompleted && data1[i]->LowRating <= iStar)
                {
                    if (data1[i]->HighRating >= iHigh)
                    {
                        iTry = i;
                        iHigh = data1[i]->HighRating;
                    }
                }
            }

            if (iTry >= 0)
            {
                data1[iTry]->LowCompleted = true;
                iStar += 1;
                iCompleted++;
                bGotNext = true;
            }

        }
    }

    bool bGotAll = true;

    for (unsigned int i = 0; i < iSize; i++)
    {
        if (!data2[i]->HighCompleted)
        {
            bGotAll = false;
            break;
        }
    }

    if (bGotAll)
    {
        rOutput << iCompleted;
        cout << iCompleted;
    }
    else
    {
        rOutput << "Too Bad";
        cout << "Too Bad";
    }

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


