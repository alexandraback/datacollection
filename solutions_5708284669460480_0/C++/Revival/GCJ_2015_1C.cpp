// GCJ_2015_1C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *pFileIn, *pFileOut;
	pFileIn = fopen("data.in", "rb");
	pFileOut = fopen("data.out", "wb");
	char abBuf[256], abLetters[101], abTarget[101], isSymm;
	int nCases = 0, nLetters = 0, nTarget = 0, nPrint = 0, nOffset = 0, nMin = 0, nDoubl, nSymm;
	float fResult = 0.0, fTmp = 0.0;
	fgets(abBuf, 10, pFileIn);
	nCases = atoi(abBuf);
	for (int i = 0; i < nCases; i++)
	{
		fgets(abBuf, 15, pFileIn);
		nLetters = atoi(abBuf);
		if (nLetters == 100)
			nOffset = 4;
		else
			if (nLetters > 9)
				nOffset = 3;
			else
				nOffset = 2;
		nTarget = atoi(abBuf + nOffset);
		if (nTarget == 100)
			nOffset += 4;
		else
			if (nTarget > 9)
				nOffset += 3;
			else
				nOffset += 2;
		nPrint = atoi(abBuf + nOffset);
		nMin = nPrint / nTarget;
		fgets(abLetters, 101, pFileIn);
		fgets(abTarget, 101, pFileIn);
		fResult = 1;
		isSymm = 1;
		nSymm = 0;
		nDoubl = 0;		
		for (int j = 0; j < nTarget; j++)
		{
			if (j+1 <= (nTarget / 2.0))
			{
				if ((abTarget[j] == abTarget[nTarget - 1 - j]) && isSymm)				
				{
					if (j != (nTarget - 1 - j))
						nSymm++;
				}
				else
					isSymm = 0;
				abBuf[j] = abTarget[j];
				abBuf[j+1] = 0;
				if (strstr(abTarget + nTarget - j - 1, abBuf) != NULL)
					nDoubl = j + 1;
			}
			fTmp = 0;
			for (int k = 0; k < nLetters; k++)
				if (abLetters[k] == abTarget[j])
					fTmp += (1.0 / nLetters);
			fResult *= fTmp;
			if (fTmp == 0)
			{
				nMin = 0;
				break;
			}
		}
		if ((nMin != 0) && (nPrint != nTarget))
			if (nDoubl < nSymm)
				nMin += nSymm;
			else
				nMin += nDoubl;
		if (fResult < 1e-6)
			fResult = 0;
		fResult = nMin - nMin * fResult;
		fprintf(pFileOut, "Case #%d: %3.7f\n", i+1, fResult);
	}
	fcloseall();
	return 0;
}

