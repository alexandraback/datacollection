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
static const int MAX = 1000;

/******************************************************************************
 * Global & Static Variables
 *****************************************************************************/
int smax;
char buf[MAX + 2];
int shyness[MAX + 1];

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
	}
	return 0;
}

void runCase()
{
	scanf("%d %s", &smax, buf);
	for (int i = 0; i <= smax; ++i) {
		shyness[i] = buf[i] - '0';
	}

	int cum = 0;
	int need = 0;
	for (int i = 0; i <= smax; ++i) {
		if (cum <= i) {
			need += (i - cum);
			cum = i;
		}
		cum += shyness[i];
	}
	printf("%d\n", need);
}
