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

using namespace std;

/******************************************************************************
 * Constants, Macros, Typedefs, Enums & Structures
 *****************************************************************************/

/******************************************************************************
 * Global & Static Variables
 *****************************************************************************/
int X, R, C;
int longer, shorter;

/******************************************************************************
 * Global & Static Function Prototypes
 *****************************************************************************/
void runCase();
bool simpleJudge();
void printResult(bool possible);

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
	}
	return 0;
}

void runCase()
{
	scanf("%d %d %d", &X, &R, &C);
	if (R > C) {
		longer = R;
		shorter = C;
	}
	else {
		longer = C;
		shorter = R;
	}

	if (simpleJudge()) {
		return;
	}

	printf("Don't know\n");
}

bool simpleJudge()
{
	if (((R * C) % X) != 0) {
		printResult(false);
		return true;
	}

	if (longer < X || (shorter < (X + 1) / 2)) {
		printResult(false);
		return true;
	}

	if (X >= 7) {
		printResult(false);
		return true;
	}

	if (X == 1 || X == 2 || X == 3) {
		printResult(true);
		return true;
	}

	if (X == 4) {
		if (shorter < 3) {
			printResult(false);
			return true;
		}
		else {
			printResult(true);
			return true;
		}
	}

	return false;
}

void printResult(bool possible)
{
	if (possible) {
		printf("GABRIEL\n");
	}
	else {
		printf("RICHARD\n");
	}
}
