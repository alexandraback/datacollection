#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN_LINE	1100000

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

bool CheckKonsonants(char* str, int iLen, int ipos, int iAnz)
{
	int iCount = 0;
	for (int i=ipos; i<ipos+iLen; i++)
	{
		if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
			iCount = 0;
		else
		{
			iCount++;
			if (iCount>=iAnz)
				return true;
		}
	}
	return false;
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


	char* strLine = new char[MAX_LEN_LINE];
	// read first line
	if (fgets(strLine, MAX_LEN_LINE, fInput)==NULL)
	{
		// Fehler beim Lesen
		return -1;
	}

	iCountCases = atoi(strLine);

	int iN;

	int iCase;
	for (int i=0; i<iCountCases; i++)
	{
		iCase = i+1;

		if (fgets(strLine, MAX_LEN_LINE, fInput) == NULL)
			return 0;
	
		int iNameLen;
		int ipos = 0;
		int ilen;
		bool bEndLine;
		while (strLine[ipos]!=' ')
			ipos++;
		iNameLen = ipos;
		ipos++;
		// x1
		iN = GetInt(&strLine[ipos], &ilen, &bEndLine);
		ipos += (ilen+1);
		
		int iResult = 0;
		// algorithm
		for (int i1=iNameLen; i1>=iN; i1--)
		{
			for (int i2=0; i2<iNameLen-i1+1; i2++)
			{
				if (CheckKonsonants(strLine, i1, i2, iN))
				{
					iResult++;
					//break;
				}
			}
		}
		
		
		// Ausgabe
		fprintf(fOutput, "Case #%d: %d\n", iCase, iResult);

		iCase++;
	}

	fclose(fInput);
	fclose(fOutput);

	delete strLine;
	return 0;
}