/******************************************************************************
 * Directives
 *****************************************************************************/
#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

/******************************************************************************
 * Header Files
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 * Constants, Macros, Typedefs, Enums & Structures
 *****************************************************************************/

/******************************************************************************
 * Global & Static Variables
 *****************************************************************************/
int A, N;
int motes[100];
int needadds[100];

/******************************************************************************
 * Global & Static Function Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function Implementations
 *****************************************************************************/
void sort(int *data, int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (data[i] > data[j]) {
				int tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
		}
	}
}

void runCase()
{
	scanf("%d %d", &A, &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &motes[i]);
	}

	if (A == 1) {
		printf("%d\n", N);
		return;
	}

	sort(motes, N);
	for (int i = 0; i < N; i++) {
		needadds[i] = 0;
	}

	int accum = 0;
	int remove = 0;
	for (int i = 0; i < N; i++) {
		int target = motes[i];
		int addnew = 0;
		while (A <= target) {
			addnew++;
			A = A * 2 - 1;
		}
		needadds[i] = addnew;
		accum += addnew;
		A += target;
	}

	int minop = accum;
	accum = 0;
	for (int i = 0; i < N; i++) {
		if (needadds[i] == 0) {
			continue;
		}
		int op = N - i + accum;
		if (minop > op) {
			minop = op;
		}
		accum += needadds[i];
	}
	printf("%d\n", minop);
}

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		runCase();
	}
	return 0;
}
