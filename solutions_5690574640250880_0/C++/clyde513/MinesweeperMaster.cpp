// MinesweeperMaster.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS 1 
#include "string.h"
#include "stdio.h"
#include "tchar.h"
#include "stdlib.h"

const char cszInputFileLocation[] = "c:\\temp\\GoogleCodeJam\\MinesweeperMaster\\C-small-attempt3.in";
const char cszOutputFileLocation[] = "c:\\temp\\GoogleCodeJam\\MinesweeperMaster\\GoogleOutput.txt";


int _tmain(int argc, _TCHAR* argv[])
{
	int nRows; // R
	int nCols; // C
	int nMines; // M
	int nNumTestCases=0;
	int i, j, nCaseNum, nRowsSolid, nColsSolid, nRemainingMines;
	bool bPossible;
	char szMap[3000]; char szRow[52];
	FILE *pInputFile = NULL;
	FILE *pOutputFile = NULL;

	if (fopen_s( &pOutputFile, cszOutputFileLocation, "w") != 0)
		return false;
	if (fopen_s( &pInputFile, cszInputFileLocation, "r") != 0)
		return false;
	fscanf( pInputFile, "%d\n", &nNumTestCases);

	for (nCaseNum=1; nCaseNum<=nNumTestCases; nCaseNum++)
	{
		fscanf( pInputFile, "%d %d %d\n", &nRows, &nCols, &nMines);
		bPossible = true;

		if (nRows == 1) // Only one row
		{
			for (i=0; i<nMines; i++)
				szMap[i]='*';
			for (i=nMines; i<(nCols-1); i++)
				szMap[i]='.';
			szMap[nCols-1]='c';
			szMap[nCols] = '\0';
		}
		else if (nCols == 1) // Only one col
		{
			szMap[0]='\0';
			for (i=0; i<nMines; i++)
				strcat(szMap,"*\n");
			for (i=nMines; i<(nRows-1); i++)
				strcat(szMap,".\n");
			strcat(szMap,"c");
		}
		else if (nMines == nRows*nCols-1) // Only one blank space
		{
			szMap[0]='\0';
			for (i=0; i<nCols; i++)
				szRow[i]='*';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			for (j=0; j<nRows-1; j++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else if (nMines == nRows*nCols-2) // Only two blank spaces
			bPossible = false;
		else if (nMines == nRows*nCols-3) // Only three blank spaces
			bPossible = false;
		else if ((nMines%nRows==0) && (nMines/nRows <= nCols-2)) // just full cols and 2+ full cols left
		{
			szMap[0]='\0';
			nColsSolid = nMines/nRows;
			for (i=0; i<nColsSolid; i++)
				szRow[i]='*';
			for (i=nColsSolid; i<nCols; i++)
				szRow[i]='.';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			for (j=0; j<nRows-1; j++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else if ((nMines%nCols==0) && (nMines/nCols <= nRows-2)) // just full rows and 2+ full rows left
		{
			szMap[0]='\0';
			nRowsSolid = nMines/nCols;
			for (i=0; i<nCols; i++)
				szRow[i]='*';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			for (j=0; j<nRowsSolid; j++)
				strcat( szMap, szRow);
			for (i=0; i<nCols; i++)
				szRow[i]='.';
			for (i=nRowsSolid; i<nRows-1; i++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else if (((nMines%nCols)%(nRows-nMines/nCols) == 0) && (nRows-nMines/nCols >= 2)) // full rows and then full cols in remaining rows, but 2 rows with blanks
		{
			szMap[0]='\0';
			nRowsSolid = nMines/nCols;
			nColsSolid = (nMines%nCols)/(nRows-nRowsSolid);
			for (i=0; i<nCols; i++)
				szRow[i]='*';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			for (j=0; j<nRowsSolid; j++)
				strcat( szMap, szRow);
			for (i=nColsSolid; i<nCols; i++)
				szRow[i]='.';
			for (i=nRowsSolid; i<nRows-1; i++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else if (((nMines%nRows)%(nCols-nMines/nRows) == 0) && (nCols-nMines/nRows >= 2)) // full cols and then full rows in remaining cols, but 2 cols with blanks
		{
			szMap[0]='\0';
			nColsSolid = nMines/nRows;
			nRowsSolid = (nMines%nRows)/(nCols-nColsSolid);
			for (i=0; i<nCols; i++)
				szRow[i]='*';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			for (j=0; j<nRowsSolid; j++)
				strcat( szMap, szRow);
			for (i=nColsSolid; i<nCols; i++)
				szRow[i]='.';
			for (i=nRowsSolid; i<nRows-1; i++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else if ((nMines%nCols != nCols-1) && (nMines/nCols < nRows-2)) // filled rows, one partial row with at 1+ blank spot, and at least 2 blank rows
		{
			szMap[0]='\0';
			nRowsSolid = nMines/nCols;
			for (i=0; i<nCols; i++)
				szRow[i]='*';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			for (j=0; j<nRowsSolid; j++)
				strcat( szMap, szRow);
			for (i=0; i<nCols; i++)
			{
				if (nMines%nCols > i)
					szRow[i]='*';
				else
					szRow[i]='.';
			}
			strcat( szMap, szRow);
			for (i=0; i<nCols; i++)
				szRow[i]='.';
			for (j=nRowsSolid+1; j<nRows-1; j++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else if ((nMines%nRows != nRows-1) && (nMines/nRows < nCols-2)) // filled cols, one partial col with 1+ blank spot, and at least 2 blank cols
		{
			szMap[0]='\0';
			for (j=0; j<nRows; j++)
			{
				for (i=0; i<(nMines+nRows-j-1)/nRows; i++)
					szRow[i]='*';
				for (i=(nMines+nRows-j-1)/nRows; i<nCols; i++)
					szRow[i]='.';
				szRow[nCols]='\0';
				if (j==nRows-1)
				{
					szRow[nCols-1]='c';
					szRow[nCols]='\0';
				}
				else
				{
					szRow[nCols]='\n';
					szRow[nCols+1]='\0';
				}
				strcat( szMap, szRow);
			}
		}
		else if ((nRows > 2) && (nMines > nCols) && ((nMines-((nMines/nCols-1)*nCols))%(nRows-(nMines/nCols-1)) == 0)) // full rows and then full cols in remaining rows, but 2 rows with blanks (2nd configuration)
		{
			szMap[0]='\0';
			nRowsSolid = nMines/nCols - 1;
			nColsSolid = (nMines-nRowsSolid*nCols)/(nRows-nRowsSolid);
			for (i=0; i<nCols; i++)
				szRow[i]='*';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			for (j=0; j<nRowsSolid; j++)
				strcat( szMap, szRow);
			for (i=nColsSolid; i<nCols; i++)
				szRow[i]='.';
			for (i=nRowsSolid; i<nRows-1; i++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else if ((nRows > 3) && (nCols > 3) && (nMines == nRows-1)) // put two rows in upper corner
		{
			szMap[0]='\0';
			for (i=0; i<(nMines+1)/2; i++)
				szRow[i]='*';
			for (i=(nMines+1)/2; i<nCols; i++)
				szRow[i]='.';
			szRow[nCols]='\n';
			szRow[nCols+1]='\0';
			strcat( szMap, szRow);
			if ((nMines+1)/2 != nMines/2)
				szRow[nMines/2]='.';
			strcat( szMap, szRow);
			for (i=0; i<nCols; i++)
				szRow[i]='.';
			for (j=2; j<nRows-1; j++)
				strcat( szMap, szRow);
			szRow[nCols-1]='c';
			szRow[nCols]='\0';
			strcat( szMap, szRow);
		}
		else
		{
			// One last edge case to try
			nRowsSolid = nMines/nCols;
			nColsSolid = (nMines%nCols)/(nRows-nRowsSolid);
			nRemainingMines = nMines - (nRowsSolid*nCols) - (nColsSolid*(nRows-nRowsSolid));
			if ((nRows-nRowsSolid > 1) && (nCols-nColsSolid > 1) && (nCols-nColsSolid > 2) && (nRows-nRowsSolid-nRemainingMines > 1))
			{
				szMap[0]='\0';
				for (i=0; i<nCols; i++)
					szRow[i]='*';
				szRow[nCols]='\n';
				szRow[nCols+1]='\0';
				for (j=0; j<nRowsSolid; j++)
					strcat( szMap, szRow);
				for (i=nColsSolid; i<nCols; i++)
					szRow[i]='.';
				for (i=0; i<nRows-nRowsSolid-1; i++)
				{
					if (i<nRemainingMines)
						szRow[nColsSolid]='*';
					strcat( szMap, szRow);
					szRow[nColsSolid]='.';
				}
				szRow[nCols-1]='c';
				szRow[nCols]='\0';
				strcat( szMap, szRow);
			}
			else
				bPossible = false;
		}

		if (bPossible)
			fprintf( pOutputFile, "Case #%u:\n%s\n", nCaseNum, szMap);
		else
			fprintf( pOutputFile, "Case #%u:\nImpossible\n", nCaseNum);
	}

	fclose( pInputFile);
	fclose( pOutputFile);
	return 0;
}