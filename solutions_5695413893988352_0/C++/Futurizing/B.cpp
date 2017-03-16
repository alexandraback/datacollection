#include <cstdio>
#include <cstring>

using namespace std;

char stra[20];
char strb[20];
int len;

int ansA;
int ansB;
int ansDiff;

void calcDiff() {
	int numA = 0;
	int numB = 0;
	int i;
	for (i = 0; i < len; i++) {
		numA = (numA * 10) + (stra[i] - '0');
		numB = (numB * 10) + (strb[i] - '0');
	}
	int diff = numA - numB;
	if (diff < 0) diff = -diff;

	if (
		ansDiff == -1 ||
		diff < ansDiff ||
		(diff == ansDiff && numB < ansB) ||
		(diff == ansDiff && numB == ansB & numA < ansA)
	) {
		ansDiff = diff;
		ansA = numA;
		ansB = numB;
	}
}

/*
  comp =  0 : equal
  comp = -1 : a < b
  comp =  1 : a > b
*/
void calc(int pos, int comp) {
	if (pos == len) {
		calcDiff();
	} else {
		char oldA = stra[pos];
		char oldB = strb[pos];
		if (comp == 0) {
			if (stra[pos] == '?' && strb[pos] == '?') {
				stra[pos] = '0'; strb[pos] = '0';
				calc(pos + 1, 0);

				stra[pos] = '0'; strb[pos] = '1';
				calc(pos + 1, -1);

				stra[pos] = '1'; strb[pos] = '0';
				calc(pos + 1, 1);

				stra[pos] = oldA;
				strb[pos] = oldB;
			} else if (stra[pos] == '?') {
				char base = strb[pos];

				stra[pos] = base;
				calc(pos + 1, 0);

				if (base != '0') {
					stra[pos] = base - 1;
					calc(pos + 1, -1);
				}

				if (base != '9') {
					stra[pos] = base + 1;
					calc(pos + 1, 1);
				}

				stra[pos] = oldA;
				strb[pos] = oldB;
			} else if (strb[pos] == '?') {
				char base = stra[pos];

				strb[pos] = base;
				calc(pos + 1, 0);

				if (base != '0') {
					strb[pos] = base - 1;
					calc(pos + 1, 1);
				}

				if (base != '9') {
					strb[pos] = base + 1;
					calc(pos + 1, -1);
				}

				stra[pos] = oldA;
				strb[pos] = oldB;
			} else {
				if (oldA < oldB) {
					calc(pos + 1, -1);
				} else if (oldA > oldB) {
					calc(pos + 1, 1);
				} else {
					calc(pos + 1, -0);
				}
			}
		} else if (comp == -1) {
			if (stra[pos] == '?') stra[pos] = '9';
			if (strb[pos] == '?') strb[pos] = '0';

			calc(pos + 1, comp);

			stra[pos] = oldA;
			strb[pos] = oldB;
		} else if (comp == 1) {
			if (stra[pos] == '?') stra[pos] = '0';
			if (strb[pos] == '?') strb[pos] = '9';

			calc(pos + 1, comp);

			stra[pos] = oldA;
			strb[pos] = oldB;
		} else {
			printf("THROW: WTF\n");
		}
	}
}

void testcase() {
	int i;

	scanf("%s %s", stra, strb);
	len = strlen(stra);

	ansDiff = -1;
	calc(0, 0);

	char ansAStr[20];
	char ansBStr[20];
	for (i = 0; i < len; i++) {
		ansAStr[len - i - 1] = ansA % 10 + '0';
		ansA /= 10;

		ansBStr[len - i - 1] = ansB % 10 + '0';
		ansB /= 10;
	}
	ansAStr[len] = ansBStr[len] = '\0';
	printf("%s %s\n", ansAStr, ansBStr);
}

int main() {
	int t, tc;

	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		testcase();
	}
	return 0;
}
