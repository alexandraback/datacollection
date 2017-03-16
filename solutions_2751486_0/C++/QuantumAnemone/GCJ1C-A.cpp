/*******************************************************************************
*	GCJ1C-A.cpp
*	Quantum Anemone
*******************************************************************************/

/*
*/

#include	<Windows.h>
#include	<stdio.h>
#include	<conio.h>
#include	<math.h>
#include	<io.h>
#include	<fcntl.h>
#include	<sys\stat.h>

FILE	*inputFile;
FILE	*outputFile;

char	*data, *input[300];
int		size, nWords = 0, cWord = 0;

void LoadData(char *filename)
{
	int		fh;
	fh = _open(filename, O_RDONLY | O_BINARY);
	if (fh == -1)
	{
		size = 0;
		return;
	}
	size = _filelength(fh);
	data = (char *)malloc(size);
	_read(fh, data, size);
	_close(fh);

	nWords = 0;
	char	*p = data;
	while (p < data + size)
	{
		while ((*p < '0') && (p < data + size))
		{
			*p = 0;
			p++;
		}
		if (p < data + size)
		{
			input[nWords++] = p;
		}
		while ((*p >= '0') && (p < data + size))
		{
			p++;
		}
	}
}

bool isConsonant(char c)
{
	if ((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u'))
		return false;
	if ((c=='A') || (c=='E') || (c=='I') || (c=='O') || (c=='U'))
		return false;
	return true;
}

#define	SIGMA(x) ((((x)*(x)) + (x)) / 2)

void solve(void)
{
	char	*name = input[cWord++];
	int		N = atoi(input[cWord++]);
	int		L = (int)strlen(name);

	int	i, j, k;
	int nValue = 0;
	int sigmaN = (N*N + N) / 2;
	for (i=0; i<L; i++)
	{
		for (j=i+N-1; j<L; j++)
		{
			// get the nVal of j
			for (k=j; (j-k < N) && isConsonant(name[k]); k--)
				;
			if (j-k >= N)
			{
				nValue += (L-j) * (k-i+2);
				i=k+1;
				break;
			}
		}
#if 0
		// what is the consonant length here?
		for (j=i; (j<L) && isConsonant(name[j]); j++)
			;
		if (j-i >= N)
		{
			nValue += SIGMA(j-2) - SIGMA(i);
			nValue += SIGMA(L-i-N+1) - SIGMA(L-j);
		}
#endif

	}

	printf_s("%s, %d, %d\n", name, N, nValue);
	fprintf_s(outputFile, "%d\n", nValue);
}

void main(int argc, char *argv[])
{
	unsigned __int64	frequency, t0, t1;

	QueryPerformanceCounter((LARGE_INTEGER *)&t0);

	printf_s("GCJ1C-A\n");
	printf_s("Quantum Anemone\n\n");

	// create output file
	char	outputFilename[256];
	sprintf_s(outputFilename, "%s.out", argv[1]);
	fopen_s(&outputFile, outputFilename, "w");
	printf_s("This program may output debug info to the console.\n");
	printf_s("The official output is written to the file %s.\n\n", outputFilename);

	// open input file
	LoadData(argv[1]);

	// how many cases?
	int	nCases = atoi(input[cWord++]);

	// solve them!
	for (int i=1; i<=nCases; i++)
	{
		printf_s("Case #%d: ", i);
		fprintf_s(outputFile, "Case #%d: ", i);
		solve();
	}

	// clean up
	fclose(outputFile);

	QueryPerformanceCounter((LARGE_INTEGER *)&t1);
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	printf_s("\nAll finished in %f seconds.\n", (t1-t0)/(float)frequency);
	_getch();
}
