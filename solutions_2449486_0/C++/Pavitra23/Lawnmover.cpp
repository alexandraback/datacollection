#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<cmath>

using namespace std;

#define MAX_M 100
#define MAX_N 100

int LAWN[MAX_N][MAX_M];

void clearLawn()
{
	memset(LAWN, 0, MAX_N*MAX_M*sizeof(int));
}

static inline int MIN(int X, int Y)
{
	return ((X)<(Y)?(X):(Y));
}

static inline int MAX(int X, int Y)
{
	return abs(MIN(-1*X, -1*Y));
}

int storeNumbers(char *aRow, int len, int index, int *colMax, int cols)
{
	char *aNum=strtok(aRow, " \n");
	int max = 0, j=0;
	
	while(aNum != NULL)
	{
		LAWN[index][j] = atoi(aNum);
		colMax[j] = MAX(colMax[j], LAWN[index][j]);
		aNum = strtok(NULL, " \n");
		if(max < LAWN[index][j])
			max = LAWN[index][j];
		j++;
	}
	return max;
}

struct rowCol
{
public:
	bool row;
	bool col;
};

bool checkLawnPossible(int *rMax, int rows, int *cMax, int cols)
{
	for(int r =0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			if(LAWN[r][c] < MIN(rMax[r], cMax[c]))
				return false;
		}
	}
	return true;
}

void  lawnmover()
{
#if 1
	char *inFile = "C://InputOutput//Lawnmover//B-small-attempt0.in";
#else
	char *inFile = "C://InputOutput//Lawnmover//sampleInputLarge.txt";
	FILE *fp = fopen(inFile, "w");
	void LawnmoverGenerateSmallerInput(FILE *ofp);
	LawnmoverGenerateSmallerInput(fp);
	fclose(fp);
#endif
	char *outFile = "C://InputOutput//Lawnmover//sampleOutput.txt";
	
	FILE *ifp = fopen(inFile, "r");
	FILE *ofp = fopen(outFile, "w");
	assert(ifp);
	assert(ofp);

	int tcases=0;

	fscanf(ifp, "%d\n", &tcases);

	for(int i = 0; i < tcases; i++)
	{
		int rows=0, cols=0;
		int rowMax[MAX_N] = {0}, colMax[MAX_M] = {0};

		fscanf(ifp, "%d %d\n", &rows, &cols);
		const int newLine = 1, nullChar =1;
		const int totalLineLength = 3*100 + 100 + newLine + nullChar;
		char aRow[totalLineLength] = {0};
		for(int n = 0; n < rows; n++)
		{
			fgets(aRow, totalLineLength, ifp); 
			rowMax[n] = storeNumbers(aRow, cols, n, colMax, cols);
		}
		bool isPoss = checkLawnPossible(rowMax, rows, colMax, cols);
		fprintf(ofp, "Case #%d: %s\n", i+1, (isPoss? "YES": "NO"));
		clearLawn();
	}

	fclose(ifp);
	fclose(ofp);
	return;
}

#if 1
int main()
{
	lawnmover();
	return 0;
}
#endif
