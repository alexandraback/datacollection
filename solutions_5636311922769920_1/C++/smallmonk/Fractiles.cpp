// Fractiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void GetPosition(unsigned int k, unsigned int c, int s, vector<unsigned long long> &p_vPosition)
{
    p_vPosition.clear();

    if (k==0)
    {
        return;
    }

    unsigned int iMinGroup = k/c;
    if (k%c > 0)
    {
        iMinGroup++;
    }
    if (iMinGroup > (unsigned int) s)
    {
        return;
    }

    unsigned long long iCurrPos=0;
    for (unsigned int i=0; i<iMinGroup; i++)
    {
        iCurrPos++;
        unsigned long long iPos = iCurrPos;

        if (iCurrPos < k)
        {
            for (unsigned int j=1; j<c; j++)
            {
                iCurrPos++;
                iPos = iPos * k - (k-iCurrPos);

                if (iCurrPos>=k)
                {
                    /// No need to continue as all combinations are checked
                    break;
                }
            }
        }

        p_vPosition.push_back(iPos);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	fstream fInput, fOutput;
    fInput.open("in.txt", ios::in);
    fOutput.open("out.txt", ios::out);

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

            int iReadNum = 0;
            int k = 0, c = 0, s=0;
            if (getline(fInput,sLine))
            {
                iReadNum = sscanf_s(sLine.c_str(),"%d %d %d",&k, &c, &s);
            }

            if (iReadNum != 3)
            {
                fOutput<<"Invalid";
            }
            else
            {
                vector<unsigned long long> vPosition;

                GetPosition(k,c,s,vPosition);

                unsigned int iLengthPosition = vPosition.size();
                if (iLengthPosition == 0)
                {
                    fOutput<<"IMPOSSIBLE";
                }
                else
                {
                    for (unsigned int iPos = 0; iPos < iLengthPosition; iPos++)
                    {
                        if (iPos > 0)
                        {
                            fOutput<<" ";
                        }
                        fOutput<<vPosition[iPos];
                    }
                }
            }
            
            fOutput<<"\n";
        }
    }
    
    fOutput.close();
    fInput.close();
	return 0;
}

