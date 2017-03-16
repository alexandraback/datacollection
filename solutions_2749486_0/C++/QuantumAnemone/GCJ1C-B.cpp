/*******************************************************************************
*	GCJ1C-B.cpp
*	Quantum Anemone
*******************************************************************************/

/*
*/

#include	<Windows.h>
#include	<stdio.h>
#include	<conio.h>
#include	<math.h>

FILE	*inputFile;
FILE	*outputFile;

char	path[1000000];
int		pathLen, d, x, y;

void north(void)
{
	path[pathLen++] = 'N';
	y += d;
	d++;
}

void south(void)
{
	path[pathLen++] = 'S';
	y -= d;
	d++;
}

void east(void)
{
	path[pathLen++] = 'E';
	x += d;
	d++;
}

void west(void)
{
	path[pathLen++] = 'W';
	x -= d;
	d++;
}

void solve(void)
{
	int		X, Y, dx, dy, dm, dp;
	fscanf_s(inputFile, "%d", &X);
	fscanf_s(inputFile, "%d", &Y);
	pathLen = 0;
	x = y = 0;
	d = 1;

	while (1)	// gross nav
	{
		// x or y?
		dx = abs(X-x);
		dy = abs(Y-y);
		if (dx > dy)
		{
			// can we get X closer?
			dm = abs(X - (x-d));
			dp = abs(X - (x+d));
			if ((dm < dx) && (dm < dp))
			{
				// go west
				west();
			}
			else if ((dp < dx) && (dp < dm))
			{
				// go east
				east();
			}
			else
			{
				break;
			}
		}
		else
		{
			// can we get Y closer?
			dm = abs(Y - (y-d));
			dp = abs(Y - (y+d));
			if ((dm < dy) && (dm < dp))
			{
				// go south
				south();
			}
			else if ((dp < dy) && (dp < dm))
			{
				// go north
				north();
			}
			else
			{
				break;
			}
		}
	}
	// fine nav
	while (x < X)
	{
		// go west, then east
		west(); east();
	}
	while (x > X)
	{
		// go east, then west
		east(); west();
	}
	while (y < Y)
	{
		// go south, then north
		south(); north();
	}
	while (y > Y)
	{
		// go north, then south
		north(); south();
	}

	path[pathLen] = 0;

	printf_s("%d %s\n", pathLen, path);
	fprintf_s(outputFile, "%s\n", path);
}

void main(int argc, char *argv[])
{
	unsigned __int64	frequency, t0, t1;

	QueryPerformanceCounter((LARGE_INTEGER *)&t0);

	printf_s("GCJ1C-B\n");
	printf_s("Quantum Anemone\n\n");

	// create output file
	char	outputFilename[256];
	sprintf_s(outputFilename, "%s.out", argv[1]);
	fopen_s(&outputFile, outputFilename, "w");
	printf_s("This program may output debug info to the console.\n");
	printf_s("The official output is written to the file %s.\n\n", outputFilename);

	// open input file
	fopen_s(&inputFile, argv[1], "r");

	// how many cases?
	int	nCases;
	fscanf_s(inputFile, "%d", &nCases);

	// solve them!
	for (int i=1; i<=nCases; i++)
	{
		printf_s("Case #%d: ", i);
		fprintf_s(outputFile, "Case #%d: ", i);
		solve();
	}

	// clean up
	fclose(inputFile);
	fclose(outputFile);

	QueryPerformanceCounter((LARGE_INTEGER *)&t1);
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	printf_s("\nAll finished in %f seconds.\n", (t1-t0)/(float)frequency);
	_getch();
}
