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

/*
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
*/




////////////////////////////////////////////////
// PROBLEM B - OUT OF GAS
////////////////////////////////////////////////

double carTimes[2048];
double carPosition[2048];

void solve_b()
{
	int TC;

	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		double D;
		int N, A;
		scanf("%lf %d %d", &D, &N, &A);




		printf("Case #%d:\n", tc);
	}
}





////////////////////////////////////////////////
// PROBLEM C - BOX FACTORY
////////////////////////////////////////////////

pair<int, long long> boxLine[128];
pair<int, long long> toyLine[128];

int solCount = 0;
pair<pair<int, long long>, long long> solutions[65536];
int sol2Count = 0;
pair<pair<int, long long>, long long> solutions2[65536];

void solve_c()
{
	int TC;

	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		// Read box and toy assembly line products
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lld %d", &boxLine[i].second, &boxLine[i].first);
		}
		for (int i = 0; i < M; ++i)
		{
			scanf("%lld %d", &toyLine[i].second, &toyLine[i].first);
		}

		// Single solution before box batch #0: before first line, no boxed toys shipped
		solCount = 1;
		solutions[0] = make_pair(make_pair(0, toyLine[0].second), 0);

		// Take box sets one-by-one, find solutions
		for (int box = 0; box < N; ++box)
		{
			int boxType = boxLine[box].first;
			long long boxCount = boxLine[box].second;
			

			// For each solution, we can either do nothing, stop at the end of a toy batch type #boxType, or stop in the middle if boxCount toys are found
			sol2Count = 0;
			for (int i = 0; i < solCount; ++i)
			{
				long long boxCnt = boxCount;
				pair<pair<int, long long>, long long> sol = solutions[i];

				// It's possible to do nothing, if we're not in the middle of a boxType toy batch
				if (!(sol.first.second > 0 && toyLine[sol.first.first].first == boxType))
				{
					int sameIndex = -1;
					for (int j = 0; sameIndex == -1 && j < sol2Count; ++j)
					{
						if (solutions2[j].first.first == sol.first.first && solutions2[j].first.second == sol.first.second)
						{
							sameIndex = j;
						}
					}
						
					if (sameIndex == -1)
					{
						solutions2[sol2Count++] = sol;
					}
					else
					{
						solutions2[sameIndex].second = std::max(solutions2[sameIndex].second, sol.second);
					}
				}

				while (sol.first.second > 0 && boxCnt > 0)
				{
					if (toyLine[sol.first.first].first == boxType)
					{
						long long packCount = std::min(boxCnt, sol.first.second);
						sol.first.second -= packCount;
						sol.second += packCount;
						boxCnt -= packCount;

						if (sol.first.second == 0)
						{
							sol.first.first++;
							if (sol.first.first < M)
								sol.first.second = toyLine[sol.first.first].second;
						}

						int sameIndex = -1;
						for (int j = 0; sameIndex == -1 && j < sol2Count; ++j)
						{
							if (solutions2[j].first.first == sol.first.first && solutions2[j].first.second == sol.first.second)
							{
								sameIndex = j;
							}
						}
						
						if (sameIndex == -1)
						{
							solutions2[sol2Count++] = sol;
						}
						else
						{
							solutions2[sameIndex].second = std::max(solutions2[sameIndex].second, sol.second);
						}
					}
					else
					{
						sol.first.first++;
						if (sol.first.first < M)
							sol.first.second = toyLine[sol.first.first].second;
						else
							sol.first.second = 0;
					}
				}
			}

			solCount = sol2Count;
			for (int i = 0; i < solCount; ++i)
			{
				solutions[i] = solutions2[i];
			}
		}

		long long maxPack = 0;
		for (int i = 0; i < solCount; ++i)
		{
			maxPack = std::max(maxPack, solutions[i].second);
		}

		printf("Case #%d: %lld\n", tc, maxPack);
	}
}





int main(int argc, char *argv[])
{
	//solve_a();
	//solve_b();
	solve_c();

	return 0;
}
