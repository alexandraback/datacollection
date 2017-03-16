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
const int MAXL = 10000;

enum {
	QP1 = 0,
	QPI,
	QPJ,
	QPK,
	QM1,
	QMI,
	QMJ,
	QMK
};

static const int MULT[8][8] = {
	{QP1, QPI, QPJ, QPK, QM1, QMI, QMJ, QMK},
	{QPI, QM1, QPK, QMJ, QMI, QP1, QMK, QPJ},
	{QPJ, QMK, QM1, QPI, QMJ, QPK, QP1, QMI},
	{QPK, QPJ, QMI, QM1, QMK, QMJ, QPI, QP1},
	{QM1, QMI, QMJ, QMK, QP1, QPI, QPJ, QPK},
	{QMI, QP1, QMK, QPJ, QPI, QM1, QPK, QMJ},
	{QMJ, QPK, QP1, QMI, QPJ, QMK, QM1, QPI},
	{QMK, QMJ, QPI, QP1, QPK, QPJ, QMI, QM1}
};

/******************************************************************************
 * Global & Static Variables
 *****************************************************************************/
int L;
int X;
int SIZE;
char buf[MAXL + 1];
int seq[MAXL];
int frontMuls[MAXL * 4];
int rearMuls[MAXL * 4];
int loopMul[4];
int fullMul;

/******************************************************************************
 * Global & Static Function Prototypes
 *****************************************************************************/
void makeDivTable();

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

bool proc()
{
	for (int i = 0; i < 4 * L; ++i) {
		if (i > SIZE) {
			break;
		}
		if (frontMuls[i] != QPI) {
			continue;
		}
		int jlimit = SIZE - (i + 2);
		if (jlimit > 4 * L) {
			jlimit = 4 * L;
		}
		for (int j = 0; j < jlimit; ++j) {
			if (rearMuls[j] == QPK) {
				return true;
			}
		}
	}
	return false;
}

void preMultiply()
{
	int f = QP1;
	int r = QP1;
	int pos = 0;
	for (int i = 0; i < 4 * L; ++i, ++pos) {
		if (pos >= L) {
			pos = 0;
		}
		f = MULT[f][seq[pos]];
		frontMuls[i] = f;
		r = MULT[seq[L - 1 - pos]][r];
		rearMuls[i] = r;
	}
	loopMul[0] = QP1;
	loopMul[1] = frontMuls[L - 1];
	loopMul[2] = frontMuls[2 * L - 1];
	loopMul[3] = frontMuls[3 * L - 1];
	fullMul = loopMul[X % 4];
}

void runCase()
{
	long long LLX;
	scanf("%d %lld", &L, &LLX);
	if (LLX > 12) {
		X = 12 + (LLX % 4);
	}
	else {
		X = (int)LLX;
	}
	SIZE = L * X;
	scanf("%s", buf);
	for (int i = 0; i < L; ++i) {
		seq[i] = buf[i] -'i' + QPI;
	}
	preMultiply();
	if (fullMul != QM1) {
		printf("NO\n");
		return;
	}
	printf("%s\n", proc() ? "YES" : "NO");
}
