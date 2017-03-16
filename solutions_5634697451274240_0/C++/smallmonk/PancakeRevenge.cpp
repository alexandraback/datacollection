// PancakeRevenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int Process(vector<bool> p_vStatus)
{
    int iStep = 0;
    unsigned int iLength = p_vStatus.size();

    if (iLength == 0)
    {
        return iStep;
    }

    for (unsigned int i=1; i<iLength; i++)
    {
        if (p_vStatus[i-1] != p_vStatus[i])
        {
            iStep++;
        }
    }

    if(!p_vStatus[iLength-1])
    {
        iStep++;
    }

    return iStep;
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

            bool bSuccess = false;
            vector<bool> vPancakeStatus;
            int iLength = 0;
            if (getline(fInput,sLine))
            {
                int iLength = sLine.length();
                if (iLength > 0)
                {
                    bSuccess = true;
                }

                for (int i=0; i<iLength; i++)
                {
                    switch(sLine[i])
                    {
                    case '+':
                        {
                            vPancakeStatus.push_back(true);
                            break;
                        }
                    case '-':
                        {
                            vPancakeStatus.push_back(false);
                            break;
                        }
                    default:
                        bSuccess = false;
                        break;
                    }
                }
                
            }

            if (bSuccess)
            {
                int iStep = Process(vPancakeStatus);

                fOutput << iStep;
            }
            else
            {
                fOutput << "Invalid";
            }

            fOutput<<"\n";
        }
    }
    
    fOutput.close();
    fInput.close();
	return 0;
}

