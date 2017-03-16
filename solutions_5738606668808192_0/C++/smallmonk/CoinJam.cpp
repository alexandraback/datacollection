// CoinJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

unsigned long long GetSmallestFactor(unsigned long long p_iNum)
{
    if (p_iNum <= 3)
    {
        /// Return 0 if the number is prime
        return 0;
    }

    unsigned long long iFactor = 2;
    if (p_iNum % iFactor == 0)
    {
        return iFactor;
    }

    if (p_iNum < 9)
    {
        /// Return 0 if the number is prime
        return 0;
    }

    iFactor = 3;
    if (p_iNum % iFactor == 0)
    {
        return iFactor;
    }

    if (p_iNum < 25)
    {
        /// Return 0 if the number is prime
        return 0;
    }

    iFactor = 5;
    while(iFactor*iFactor < p_iNum)
    {
        unsigned long long iRemainder = p_iNum % iFactor;
        if (iRemainder == 0)
        {
            return iFactor;
        }

        iFactor+=2;
    }
    
    /// Return 0 if the number is prime
    return 0;
}

unsigned long long GetNum(unsigned long long iNum, unsigned int iBase)
{
    if (iBase <2)
    {
        return 0;
    }

    if (iBase == 2)
    {
        return iNum;
    }

    unsigned long long iCheck = 0;
    unsigned long long iFactor = 1;
    while (iNum > 0)
    {
        unsigned long long iBitExist = (iNum & 1);
        if (iBitExist)
        {
            iCheck += iFactor;
        }

        iNum = (iNum >> 1);

        if (iNum > 0)
        {
            iFactor *= iBase;
        }
    }

    return iCheck;
}

void GetCoins(int p_iLength, int p_iNumCoin, vector<unsigned long long> &p_vCoin)
{
    unsigned long long iBase = (1<<(p_iLength-1) | 1);
    unsigned long long iShift = p_iLength-2;
    unsigned long long iMaxCheck = (1<<iShift) - 1;

    int iPending = p_iNumCoin;
    for (unsigned long long i=0; i<iMaxCheck; i++)
    {
        vector<unsigned long long> vCurr;
        unsigned long long iNum = iBase | (i << 1);

        unsigned long long iCoinVar = iNum;
        for (unsigned int iBase = 2; iBase <= 10; iBase++)
        {
            unsigned long long iFactor = 0;
            if (iBase == 2)
            {
                iFactor = GetSmallestFactor(iCoinVar);
            }
            else
            {
                iCoinVar = GetNum(iNum,iBase);
                iFactor = GetSmallestFactor(iCoinVar);
            }

            if (iFactor == 0)
            {
                /// The number is prime
                break;
            }
            vCurr.push_back(iFactor);
        }

        if (vCurr.size() == 9)
        {
            p_vCoin.push_back(iNum);
            for (unsigned int iCoin = 0; iCoin<9; iCoin++)
            {
                p_vCoin.push_back(vCurr[iCoin]);
            }
            iPending--;
        }

        if (iPending <= 0)
        {
            break;
        }
    }
}

string GetBinaryString(unsigned long long p_iBinary)
{
    string sBinary;
    unsigned long long iNum = p_iBinary;
    while (iNum > 0)
    {
        unsigned long long iBitExist = (iNum & 1);
        if (iBitExist)
        {
            sBinary = '1' + sBinary;
        }
        else
        {
            sBinary = '0' + sBinary;
        }

        iNum = (iNum >> 1);
    }

    return sBinary;
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
            fOutput<<":\n";

            int iReadNum = 0;
            int iCoinLength = 0, iNumCoin = 0;
            if (getline(fInput,sLine))
            {
                iReadNum = sscanf_s(sLine.c_str(),"%d %d",&iCoinLength, &iNumCoin);
            }


            if (iReadNum != 2)
            {
                fOutput << "Invalid";
            }
            else
            {
                vector<unsigned long long> vCoin;
                GetCoins(iCoinLength, iNumCoin, vCoin);
                unsigned int iLengthVector = vCoin.size();
                for (unsigned int iItem = 0; iItem < iLengthVector; iItem++)
                {
                    if (iItem % 10 == 0)
                    {
                        string sBinary = GetBinaryString(vCoin[iItem]);
                        fOutput<<sBinary;
                    }
                    else
                    {
                        fOutput<<vCoin[iItem];
                    }
                    if((iItem+1) % 10 == 0)
                    {
                        fOutput<<"\n";
                    }
                    else
                    {
                        fOutput<<" ";
                    }
                }
                
            }
        }
    }
    
    fOutput.close();
    fInput.close();
	return 0;
}

