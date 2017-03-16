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

	int iLevels;
	int iStar1[1000];
	int iStar2[1000];
	int iComplete[1000];

	int j;
	int iStars;
	int iGames;
	int iCase;
	for (int i=0; i<iCountCases; i++)
	{
		iCase = i+1;

		if (iCase==6)
			iCase = 6;
		if (fgets(strLine, MAX_LEN_LINE, fInput) == NULL)
			return 0;
		
		int ipos = 0;
		int ilen;
		bool bEndLine;
		// x1
		iLevels = GetInt(&strLine[ipos], &ilen, &bEndLine);
		ipos += (ilen+1);
		for (j=0; j<iLevels; j++)
		{
			if (fgets(strLine, MAX_LEN_LINE, fInput) == NULL)
				return 0;
			ipos = 0;
			iStar1[j] = GetInt(&strLine[ipos], &ilen, &bEndLine);
			ipos += (ilen+1);
			iStar2[j] = GetInt(&strLine[ipos], &ilen, &bEndLine);
			ipos += (ilen+1);
		}

		
		// algorithm
		for (j=0; j<iLevels; j++)
			iComplete[j] = 0;
		iStars = 0;
		iGames = 0;
		bool bBad = false;
		while (!bBad && (iStars<2*iLevels))
		{
			int iGamesBefore = iGames;
			for (j=0; j<iLevels; j++)
			{
				if ((iComplete[j]==0) && (iStars>=iStar2[j]))
				{
					iStars += 2;
					iComplete[j] = 2;
					iGames++;
				}
				else if ((iComplete[j]==1) && (iStars>=iStar2[j]))
				{
					iStars++;
					iComplete[j] = 2;
					iGames++;
				}
			}
			if ((iGames<2*iLevels) && (iGamesBefore==iGames))
			{
				iGamesBefore = iGames;
				int iMax = 0;
				int iIndexMax;
				for (j=0; j<iLevels; j++)
				{
					if ((iComplete[j]==0) && (iStars>=iStar1[j]))
					{
						if (iStar2[j]>iMax)
						{
							iMax = iStar2[j];
							iIndexMax = j;
						}
					}
				}
				if (iMax>0)
				{
					iStars++;
					iComplete[iIndexMax] = 1;
					iGames++;
				}

				if (iGamesBefore==iGames)
					bBad = true;
			}
		}
		
		printf("Nr. %d\n", iCase);
		// Ausgabe
		if (bBad)
			fprintf(fOutput, "Case #%d: Too Bad\n", iCase);
		else
			fprintf(fOutput, "Case #%d: %d\n", iCase, iGames);


		iCase++;
	}

	fclose(fInput);
	fclose(fOutput);

	return 0;
}