// Google Code Jam 2012 - Round 1C
// by vdave, Hungary, 2012

#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <utility>

using namespace std;

/////////////////////////
// COMMON UTILITY METHODS
/////////////////////////

char line[2048];

int iToken;
char *lineSplit[1024];
int wordLength[1024];

void split()
{
	iToken = 0;
	char *sInput = line;

	// Strip leading whitespace
	while ((*sInput) == ' ' || (*sInput) == '\n' || (*sInput) == '\t') sInput++;

	while (*sInput)
	{
		// Mark beginning of next word
		lineSplit[iToken] = sInput;
		iToken++;

		// Find end of the current work
		while ((*sInput) != ' ' && (*sInput) != '\n' && (*sInput) != '\t' && (*sInput))
		{
			sInput++;
		}

		if (*sInput)
		{
			// If not end of the string, make split and skip whitespaces
			*sInput = '\0';
			sInput++;
			while ((*sInput) == ' ' || (*sInput) == '\n' || (*sInput) == '\t') sInput++;
		}
	}
}




////////////////////////////////////////////////
// PROBLEM A - DIAMOND INHERITANCE
////////////////////////////////////////////////

unsigned int superClasses[1024][32];

int linkCount[1024];
char linked[1024][1024];

int outLinkCount[1024];
int outLinks[1024][1024];


void solve_a()
{
	int TC;

	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		// Data cleanup
		for (int i = 0; i < 1024; ++i)
		{
			linkCount[i] = 0;
			memset(linked[i], 0, 1024);

			outLinkCount[i] = 0;

			for (int j = 0; j < 32; ++j)
				superClasses[i][j] = 0;
			superClasses[i][i / 32] = 1U << (i % 32);
		}

		// Read class inheritance graph
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			int M, t;
			scanf("%d", &M);
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &t);
				t--;

				// Class #i inherits from Class #t.
				linked[i][t] = 1;
				linkCount[i]++;

				outLinks[t][outLinkCount[t]++] = i;
			}
		}

		// Topological sort, find diamonds on the way
		bool isDiamond = false;
		while (!isDiamond)
		{
			// Find an unprocessed class, where all superclasses have already been processed
			int procInd = -1;
			for (int i = 0; i < N; ++i)
			{
				if (linkCount[i] == 0)
				{
					procInd = i;
					break;
				}
			}
			if (procInd == -1)
				break;

			// Mark class #procInd as processed
			linkCount[procInd] = -1;

			// Process all outgoing inheritances (where class #procInd is the superclass)
			for (int i = 0; i < outLinkCount[procInd]; ++i)
			{
				// Class #nextInd inherits from class #procInd
				int nextInd = outLinks[procInd][i];

				// Decrease the incoming link count for class #nextInd
				linkCount[nextInd]--;

				// Merge inheritance data from #procInd into #nextInd and check for common classes => diamond
				for (int j = 0; j < 32; ++j)
				{
					if (superClasses[nextInd][j] & superClasses[procInd][j])
						isDiamond = true;

					superClasses[nextInd][j] |= superClasses[procInd][j];
				}
			}
		}

		if (isDiamond)
			printf("Case #%d: Yes\n", tc);
		else
			printf("Case #%d: No\n", tc);
	}
}





////////////////////////////////////////////////
// PROBLEM B - 
////////////////////////////////////////////////

void solve_b()
{
	int TC;

	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{


		printf("Case #%d:\n", tc);
	}
}





////////////////////////////////////////////////
// PROBLEM C - 
////////////////////////////////////////////////

void solve_c()
{
	int TC;

	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{


		printf("Case #%d:\n", tc);
	}
}





int main(int argc, char *argv[])
{
	solve_a();
	//solve_b();
	//solve_c();

	return 0;
}
