#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN_LINE	100

int GetInt(char *str, int *len, bool *bEndLine)
{
	int ipos = 0;
	while (str[ipos] != ' ' && str[ipos] != '\n')
		ipos++;
	char strZahl[20];
	strncpy(strZahl, str, ipos);
	strZahl[ipos] = 0;
	int iResult = atoi(strZahl);
	*len = ipos;
	if (str[ipos]=='\n')
		*bEndLine = true;
	else
		*bEndLine = false;
	return iResult;
}
double GetDouble(char *str, int *len, bool *bEndLine)
{
	int ipos = 0;
	while (str[ipos] != ' ' && str[ipos] != '\n')
		ipos++;
	char strZahl[50];
	strncpy(strZahl, str, ipos);
	strZahl[ipos] = 0;
	double dResult = atof(strZahl);
	*len = ipos;
	if (str[ipos]=='\n')
		*bEndLine = true;
	else
		*bEndLine = false;
	return dResult;
}
void GetString(char *str,char *strOut, int *len, bool *bEndLine)
{
	int ipos = 0;
	while (str[ipos] != ' ' && str[ipos] != '\n')
		ipos++;
	strncpy(strOut, str, ipos);
	strOut[ipos] = 0;
	*len = ipos;
	if (str[ipos]=='\n')
		*bEndLine = true;
	else
		*bEndLine = false;
}



int main(int argv, char *argc[])
{
	if (argv < 2)
		return -1;
	

	int iCountCases = 0;
	
	// read Input
	FILE *fInput = fopen(argc[1], "r");
	if (fInput == NULL)
		return -1;

	// output
	FILE *fOutput = fopen("output.txt", "w");
	if (fOutput == NULL)
	{
		fclose(fInput);
		return -1;
	}


	char strLine[MAX_LEN_LINE];
	// read first line
	if (fgets(strLine, MAX_LEN_LINE, fInput)==NULL)
	{
		// Fehler beim Lesen
		return -1;
	}

	iCountCases = atoi(strLine);

	int iX;
	int iY;
	char strOut[2000];

	int iCase;
	for (int i=0; i<iCountCases; i++)
	{
		iCase = i+1;

		if (fgets(strLine, MAX_LEN_LINE, fInput) == NULL)
			return 0;
		
		int ipos = 0;
		int ilen;
		bool bEndLine;
		// x1
		iX = GetInt(&strLine[ipos], &ilen, &bEndLine);
		ipos += (ilen+1);
		iY = GetInt(&strLine[ipos], &ilen, &bEndLine);
		
		for (int j=0; j<2000; j++)
			strOut[j] = '\0';
		// algorithm
		int iWay = abs(iX) + abs(iY);
		double dN = sqrt((double)iWay*2.0+0.25) - 0.5 + 0.000000001;
		int iN = (int)dN;
		
		int iWX = abs(iX);
		int iPosX = 0;
		int iPosY;
		int iM = iN;
		while (iPosX!=iWX && iM>0)
		{
			if (iM<=iWX-iPosX)
			{
				iPosX += iM;
				if (iX<0)
					strOut[iM-1] = 'W';
				else
					strOut[iM-1] = 'E';
			}
			iM--;
		}
		iPosX = 0;
		iPosY = 0;
		for (int j=0; j<iN; j++)
		{
			if (strOut[j]==0)
			{
				if (iY<0)
					strOut[j] = 'S';
				else
					strOut[j] = 'N';
			}
			if (strOut[j]=='N')
				iPosY += j+1;
			else if (strOut[j]=='S')
				iPosY -= j+1;
			else if (strOut[j]=='E')
				iPosX += j+1;
			else if (strOut[j]=='W')
				iPosX -= j+1;
		}

		ipos = iN;
		while (iPosX!=iX)
		{
			if (iPosX<iX)
			{
				strOut[ipos] = 'W';
				strOut[ipos+1] = 'E';
				iPosX++;
			}
			else
			{
				strOut[ipos] = 'E';
				strOut[ipos+1] = 'W';
				iPosX--;
			}
			ipos += 2;
		}
		while (iPosY!=iY)
		{
			if (iPosY<iY)
			{
				strOut[ipos] = 'S';
				strOut[ipos+1] = 'N';
				iPosY++;
			}
			else
			{
				strOut[ipos] = 'N';
				strOut[ipos+1] = 'S';
				iPosY--;
			}
			ipos += 2;
		}
		// Ausgabe
		fprintf(fOutput, "Case #%d: %s\n", iCase, strOut);

		iCase++;
	}

	fclose(fInput);
	fclose(fOutput);

	return 0;
}