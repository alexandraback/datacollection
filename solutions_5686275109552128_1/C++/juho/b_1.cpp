/******************************************************************************
 * Directives
 *****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/******************************************************************************
 * Header Files
 *****************************************************************************/
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <string>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

/******************************************************************************
 * Constants, Macros, Typedefs, Enums & Structures
 *****************************************************************************/
#define MAXD 1000
#define MAXP 1000

/******************************************************************************
 * Global & Static Variables
 *****************************************************************************/
int histo[MAXP + 1];
int globalMinTime;

/******************************************************************************
 * Global & Static Function Prototypes
 *****************************************************************************/
void runCase();

/******************************************************************************
 * Function Implementations
 *****************************************************************************/
int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		runCase();
		fprintf(stderr, "... %d\n", t);
	}
	return 0;
}

int getNextMaxp(int maxp)
{
	for (int i = maxp - 1; i > 0; --i) {
		if (histo[i] > 0) {
			return i;
		}
	}
	return 0;
}

void updateMinTime(int maxp, int depth)
{
	int minTime = maxp + depth;
	if (minTime < globalMinTime) {
		globalMinTime = minTime;
	}

	if (maxp < 4) {
		return;
	}

	if (depth + 4 > globalMinTime) {
		return;
	}

	int orgNextMaxp = maxp;
	if (histo[maxp] == 1) {
		orgNextMaxp = getNextMaxp(maxp);
	}
	--histo[maxp];
	for (int i = (maxp + 1) / 2, n = maxp - 1; i < n; i = i + maxp) {
		++histo[i];
		++histo[maxp - i];
		int nextMaxp = (orgNextMaxp > i) ? orgNextMaxp : i;
		updateMinTime(nextMaxp, depth + 1);
		--histo[i];
		--histo[maxp - i];
	}
	++histo[maxp];
}

void runCase()
{
	int D;
	scanf("%d", &D);
	memset(histo, 0 , sizeof(int) * (MAXP + 1));
	int maxp = 0;

	for (int i = 0; i < D; ++i) {
		int p;
		scanf("%d", &p);
		++histo[p];
		if (p > maxp) {
			maxp = p;
		}
	}

	globalMinTime = maxp;
	updateMinTime(maxp, 0);

	printf("%d\n", globalMinTime);
}
