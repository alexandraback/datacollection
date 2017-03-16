// DeceitfulWar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const char cszInputFileLocation[] = "c:\\temp\\GoogleCodeJam\\DeceitfulWar\\D-small-attempt0.in";
const char cszOutputFileLocation[] = "c:\\temp\\GoogleCodeJam\\DeceitfulWar\\GoogleOutput.txt";
CArray<double,double> listNaomiBlocks;
CArray<double,double> listKenBlocks;

CWinApp theApp;
using namespace std;

int FindBestDeceitfulScore()
{
	int nBestScore = 0;
	int i, nPlayBlockNaomi;

	while (listNaomiBlocks.GetCount() > 0)
	{
		nPlayBlockNaomi = -1;
		for (i=0; (i<listNaomiBlocks.GetCount()) && (nPlayBlockNaomi == -1); i++)
		{
			if (listNaomiBlocks[i] > listKenBlocks[0])
				nPlayBlockNaomi = i;
		}
		if (nPlayBlockNaomi == -1)
		{
			// Naomi loses, but she'll force Ken to play best block on her worst block
			nPlayBlockNaomi = 0;
			listNaomiBlocks.RemoveAt(0);
			listKenBlocks.RemoveAt(listKenBlocks.GetCount()-1);
		}
		else
		{
			// Naomi lies and wins the round. Ken plays worst block.
			nBestScore++;
			listNaomiBlocks.RemoveAt(nPlayBlockNaomi);
			listKenBlocks.RemoveAt(0);
		}
	}

	return nBestScore;}

int FindBestWarScore()
{
	// Make a copy of the two lists because I'll need to use the list again in War routine
	CArray<double,double> listNaomiBlocks2;
	CArray<double,double> listKenBlocks2;
	listNaomiBlocks2.Copy(listNaomiBlocks);
	listKenBlocks2.Copy(listKenBlocks);

	int nBestScore = 0;
	int i, nPlayBlock;

	while (listNaomiBlocks2.GetCount() > 0)
	{
		nPlayBlock = -1;
		for (i=0; (i< listKenBlocks2.GetCount()) && (nPlayBlock == -1); i++)
		{
			if (listNaomiBlocks2[0] < listKenBlocks2[i])
				nPlayBlock = i;
		}

		if (nPlayBlock == -1)
		{
			nBestScore++;
			listKenBlocks2.RemoveAt(0);
		}
		else
			listKenBlocks2.RemoveAt(nPlayBlock);
		listNaomiBlocks2.RemoveAt(0);
	}

	return nBestScore;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nNumTestCases=0; int nNumBlocks=0;
	int i, j, nCaseNum, nInsertAfter, nBestDeceitfulScore, nBestWarScore;
	double fTemp;
	FILE *pInputFile = NULL;
	FILE *pOutputFile = NULL;
	//double fJunk1[9]; double fJunk2[9];

	HMODULE hModule = ::GetModuleHandle(NULL);
	AfxWinInit(hModule, NULL, ::GetCommandLine(), 0);

	if (fopen_s( &pOutputFile, cszOutputFileLocation, "w") != 0)
		return false;
	if (fopen_s( &pInputFile, cszInputFileLocation, "r") != 0)
		return false;
	fscanf_s(pInputFile, "%d\n", &nNumTestCases);

	for (nCaseNum=1; nCaseNum<=nNumTestCases; nCaseNum++)
	{
		fscanf_s(pInputFile, "%d\n", &nNumBlocks);
		for (i=1; i <= nNumBlocks; i++)
		{
			if (i == nNumBlocks)
				fscanf_s(pInputFile, "%lf\n", &fTemp);
			else
				fscanf_s(pInputFile, "%lf ", &fTemp);
			if (i==1)
				listNaomiBlocks.Add(fTemp);
			else
			{
				nInsertAfter = -1;
				for (j=listNaomiBlocks.GetCount()-1; (j>=0) && (nInsertAfter==-1); j--)
				{
					if (listNaomiBlocks[j] < fTemp)
						nInsertAfter = j;
				}
				listNaomiBlocks.InsertAt( (nInsertAfter+1), fTemp);
			}
		}
		for (i=1; i <= nNumBlocks; i++)
		{
			if (i == nNumBlocks)
				fscanf_s(pInputFile, "%lf\n", &fTemp);
			else
				fscanf_s(pInputFile, "%lf ", &fTemp);
			if (i==1)
				listKenBlocks.Add(fTemp);
			else
			{
				nInsertAfter = -1;
				for (j=listKenBlocks.GetCount()-1; (j>=0) && (nInsertAfter==-1); j--)
				{
					if (listKenBlocks[j] < fTemp)
						nInsertAfter = j;
				}
				listKenBlocks.InsertAt( (nInsertAfter+1), fTemp);
			}
		}

		nBestWarScore = FindBestWarScore();
		nBestDeceitfulScore = FindBestDeceitfulScore();
		//		for (j=listKenBlocks.GetCount(); j>0; j--)
		//			fJunk1[j-1]=listKenBlocks[j-1];
		//		for (j=listNaomiBlocks.GetCount(); j>0; j--)
		//			fJunk2[j-1]=listNaomiBlocks[j-1];

		fprintf( pOutputFile, "Case #%u: %u %u\n", nCaseNum, nBestDeceitfulScore, nBestWarScore);
		listNaomiBlocks.RemoveAll();
		listKenBlocks.RemoveAll();
	}

	fclose( pInputFile);
	fclose( pOutputFile);
	return 0;
}
