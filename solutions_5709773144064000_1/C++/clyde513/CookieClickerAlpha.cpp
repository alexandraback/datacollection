// CookieClickerAlpha.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

const char cszInputFileLocation[] = "c:\\temp\\GoogleCodeJam\\CookieClickerAlpha\\B-large.in";
const char cszOutputFileLocation[] = "c:\\temp\\GoogleCodeJam\\CookieClickerAlpha\\GoogleOutput.txt";


int _tmain(int argc, _TCHAR* argv[])
{
	double fRate, fBestTime, fAltBestTime, fFarmPurchaseTime; 
	double fFarmCost; //C
	double fFarmRate; //F
	double fWinningCookies; //X
	int nNumTestCases=0;
	int nCaseNum;
	bool bKeepBuying;
	FILE *pInputFile = NULL;
	FILE *pOutputFile = NULL;

	if (fopen_s( &pOutputFile, cszOutputFileLocation, "w") != 0)
		return false;
	if (fopen_s( &pInputFile, cszInputFileLocation, "r") != 0)
		return false;
	fscanf(pInputFile, "%d\n", &nNumTestCases);

	for (nCaseNum=1; nCaseNum<=nNumTestCases; nCaseNum++)
	{
		fRate=2.0;
		fscanf(pInputFile, "%lf %lf %lf\n", &fFarmCost, &fFarmRate, &fWinningCookies);
		fBestTime = fWinningCookies/fRate;
		fFarmPurchaseTime = 0.0;
		bKeepBuying=true;

		while (bKeepBuying)
		{
			fFarmPurchaseTime += fFarmCost/fRate;
			fRate += fFarmRate;
			fAltBestTime = fFarmPurchaseTime + (fWinningCookies/fRate);
			if (fAltBestTime < fBestTime)
				fBestTime = fAltBestTime;
			else
				bKeepBuying=false;
		}

		fprintf( pOutputFile, "Case #%u: %1.7f\n", nCaseNum, fBestTime);
	}

	fclose( pInputFile);
	fclose( pOutputFile);
	return 0;
}