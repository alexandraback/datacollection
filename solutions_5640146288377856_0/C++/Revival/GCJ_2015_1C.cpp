// GCJ_2015_1C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *pFileIn, *pFileOut;
	pFileIn = fopen("data.in", "rb");
	pFileOut = fopen("data.out", "wb");
	char abBuf[256];
	int nCases = 0, nCols = 0, nRows = 0, nWidth = 0, nOffset = 0, nResult = 0;
	fgets(abBuf, 10, pFileIn);
	nCases = atoi(abBuf);
	for (int i = 0; i < nCases; i++)
	{
		fgets(abBuf, 10, pFileIn);
		nRows = atoi(abBuf);
		if (nRows > 9)
			nOffset = 3;
		else
			nOffset = 2;
		nCols = atoi(abBuf + nOffset);
		if (nCols > 9)
			nOffset += 3;
		else
			nOffset += 2;
		nWidth = atoi(abBuf + nOffset);
		nResult = nCols % nWidth;
		if (nResult == 0)
			nResult = (nCols / nWidth) * nRows + nWidth - 1;
		else
			nResult = (nCols / nWidth) * nRows + nWidth;
		fprintf(pFileOut, "Case #%d: %d\n", i+1, nResult);
	}
	fcloseall();
	return 0;
}

