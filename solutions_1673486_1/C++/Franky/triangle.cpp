#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN_LINE	1000000	//200

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


	//char strLine[MAX_LEN_LINE];
	char* strLine = new char[MAX_LEN_LINE];

	// read first line
	if (fgets(strLine, MAX_LEN_LINE, fInput)==NULL)
	{
		// Fehler beim Lesen
		return -1;
	}

	iCountCases = atoi(strLine);

	int iLenPassword;
	int iTyped;
	double dP[100000];

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
		iTyped = GetInt(&strLine[ipos], &ilen, &bEndLine);
		ipos += (ilen+1);
		iLenPassword = GetInt(&strLine[ipos], &ilen, &bEndLine);
		ipos = 0;
		if (fgets(strLine, MAX_LEN_LINE, fInput) == NULL)
			return 0;
		for (int j=0; j<iTyped; j++)
		{
			dP[j] = GetDouble(&strLine[ipos], &ilen, &bEndLine);
			ipos += (ilen+1);
		}
		
		// algorithm
		double dMinKeys = (double)(2+iLenPassword);	// gleich Enter
		for (int j=0; j<iTyped; j++)
		{
			double dRight = 1.0;
			for (int k=0; k<iTyped-j; k++)
			{
				dRight *= dP[k];
			}
			double dKeys = dRight * (double)(iLenPassword-iTyped+1 + 2*j)
							+ (1.0-dRight) * (double)(iLenPassword-iTyped+1+2*j + iLenPassword + 1);
			if (dKeys<dMinKeys)
				dMinKeys = dKeys;
		}
		
		// Ausgabe
		fprintf(fOutput, "Case #%d: %.6f\n", iCase, dMinKeys);
		printf("%d\n", iCase);

		iCase++;
	}

	fclose(fInput);
	fclose(fOutput);

	delete[] strLine;
	return 0;
}