// Fractiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Intersect(const vector<bool> &p_v1, const vector<bool> &p_v2, vector<bool> &p_vResult)
{
    unsigned int iL1 = p_v1.size();
    unsigned int iL2 = p_v2.size();
    if (iL1 != iL2)
    {
        return;
    }

    for (unsigned int i=0; i<iL1; i++)
    {
        if (p_v1[i] && p_v2[i])
        {
            p_vResult.push_back(true);
        }
        else
        {
            p_vResult.push_back(false);
        }
    }
}

void EvolveLeftOnly(const vector<bool> &p_vCheck, int c, vector<bool> &p_vResult)
{
    unsigned int iLengthCheck = p_vCheck.size();
    p_vResult = p_vCheck;
    for (int i=1; i<c; i++)
    {
        unsigned int iSizeCheck = p_vResult.size();
        vector<bool> vResult;
        
        {
            bool bValue = p_vResult[0];
            if (!bValue)
            {
                for (unsigned int push=0; push<iLengthCheck; push++)
                {
                    vResult.push_back(p_vCheck[push]);
                }
            }
            else
            {
                for (unsigned int push=0; push<iLengthCheck; push++)
                {
                    vResult.push_back(true);
                }
            }
        }

        p_vResult.swap(vResult);
    }

}

bool IsAllInvalid(const vector<bool> &p_vCheck)
{
    unsigned int iSize = p_vCheck.size();
    for (unsigned int i=0; i<iSize; i++)
    {
        if (p_vCheck[i])
        {
            return false;
        }
    }
    return true;
}

void GetPosition(unsigned int k, unsigned int c, int s, vector<int> &p_vPosition)
{
    p_vPosition.clear();

    if (k==0)
    {
        return;
    }

    vector<vector<bool>> vCheckCombination;

    vector<bool> vCopy;
    for (unsigned int i=0; i<k; i++)
    {
        vCopy.push_back(false);
    }

    for (unsigned int i=0; i<k; i++)
    {
        vector<bool> vCheck = vCopy;
        vCheck[i] = true;
        vector<bool> vResult;

        EvolveLeftOnly(vCheck,c,vResult);
        vCheckCombination.push_back(vResult);        
    }

    vector<bool> vIntersect = vCheckCombination[0];
    for (unsigned int i=1; i<k; i++)
    {
        vector<bool> vResult;
        Intersect(vIntersect,vCheckCombination[i],vResult);

        bool bInvalid = IsAllInvalid(vResult);
        if (bInvalid)
        {
            unsigned int iLengthIntersect = vIntersect.size();
            for (unsigned int iPos=0; iPos<iLengthIntersect; iPos++)
            {
                if (vIntersect[iPos])
                {
                    p_vPosition.push_back(iPos+1);
                    break;
                }
            }

            if(p_vPosition.size() > (unsigned int) s)
            {
                break;
            }

            vIntersect = vCheckCombination[i];
        }
        else
        {
            vIntersect.swap(vResult);
        }
    }

    
    if (p_vPosition.size() >= (unsigned int) s)
    {
        /// Impossible case
        p_vPosition.clear();
        return;
    }
    
    unsigned int iLengthIntersect = vIntersect.size();
    for (unsigned int i=0; i<iLengthIntersect; i++)
    {
        if (vIntersect[i])
        {
            p_vPosition.push_back(i+1);
            break;
        }
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
                vector<int> vPosition;

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

