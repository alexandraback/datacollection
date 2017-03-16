// CountingSheep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
using namespace std;

const int TICKALL = (1 << 10) - 1;

void TickSheep(int p_iBit, int &p_iSheep)
{
    if (p_iBit == 0)
    {
        p_iSheep |= 1;
        return;
    }

    p_iSheep |= 1 << p_iBit;
}

void CheckSheep(int p_iNum, int &p_iSheep)
{
    while(p_iNum > 0)
    {
        int iRemainder = p_iNum % 10;
        TickSheep(iRemainder,p_iSheep);
        p_iNum -= iRemainder;
        p_iNum /= 10;
    }
}

int CountingSheep(int p_iStart)
{
    if (p_iStart == 0)
    {
        return 0;
    }

    int iCurrNum = 0;
    int iCountSheep = 0;

    while(iCountSheep != TICKALL)
    {
        iCurrNum += p_iStart;
        CheckSheep(iCurrNum,iCountSheep);
    }

    return iCurrNum;
}


int _tmain(int argc, _TCHAR* argv[])
{
    fstream fInput, fOutput;
    fInput.open("input.txt", ios::in);
    fOutput.open("output.txt", ios::out);

    if (fInput.good() && fOutput.good())
    {
        int iNumLine = 0;
        string sLine;
        if (getline(fInput,sLine))
        {
            sscanf_s(sLine.c_str(),"%d",&iNumLine);
        }

        if (iNumLine > 100 || iNumLine < 1)
        {
            return 1;
        }
        
        for (int i=1; i<=iNumLine; i++)
        {
            fOutput<<"Case #";
            fOutput<<i;
            fOutput<<": ";

            int iSheep = 0;
            if (getline(fInput,sLine))
            {
                sscanf_s(sLine.c_str(),"%d",&iSheep);
            }

            int iNum = CountingSheep(iSheep);
            if (iNum == 0)
            {
                fOutput << "INSOMNIA";
            }
            else
            {
                fOutput << iNum;
            }

            fOutput<<"\n";
        }
    }
    
    fOutput.close();
    fInput.close();
	return 0;
}

