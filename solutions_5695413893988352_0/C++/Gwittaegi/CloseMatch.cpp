#include <cstdio>
#include <string>
#include <iostream>
#define MAX 999999999999999999
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))

using namespace std;

long long min, resC, resJ;
string cStr, jStr;

void Pro(int l, int n, long long cN, long long jN, int comp) {
	if (l == n) {
		int k = ABS(cN, jN);
		if (min > k || (min == k && (resC > cN || (resC == cN && resJ > jN)))) {
			min = k;
			resC = cN;
			resJ = jN;
		}
	}
	else {
		if (cStr[l] == '?' && jStr[l] == '?') {
			if (comp == 0) {
				Pro(l + 1, n, cN * 10, jN * 10, 0);
				Pro(l + 1, n, cN * 10 + 1, jN * 10, 1);
				Pro(l + 1, n, cN * 10, jN * 10 + 1, -1);
			}
			else if (comp == -1)
				Pro(l + 1, n, cN * 10 + 9, jN * 10, comp);
			else Pro(l + 1, n, cN * 10, jN * 10 + 9, comp);
		}
		else if (cStr[l] == '?') {
			if (comp == 0) {
				Pro(l + 1, n, cN * 10 + (jStr[l] - '0'), jN * 10 + (jStr[l] - '0'), 0);
				if (jStr[l] != '0')Pro(l + 1, n, cN * 10 + (jStr[l] - '0') - 1, jN * 10 + (jStr[l] - '0'), -1);
				if (jStr[l] != '9')Pro(l + 1, n, cN * 10 + (jStr[l] - '0') + 1, jN * 10 + (jStr[l] - '0'), 1);
			}
			else if (comp == -1)
				Pro(l + 1, n, cN * 10 + 9, jN * 10 + (jStr[l] - '0'), comp);
			else Pro(l + 1, n, cN * 10, jN * 10 + (jStr[l] - '0'), comp);
		}
		else if (jStr[l] == '?') {
			if (comp == 0) {
				Pro(l + 1, n, cN * 10 + (cStr[l] - '0'), jN * 10 + (cStr[l] - '0'), 0);
				if (cStr[l] != '0')Pro(l + 1, n, cN * 10 + (cStr[l] - '0'), jN * 10 + (cStr[l] - '0') - 1, 1);
				if (cStr[l] != '9')Pro(l + 1, n, cN * 10 + (cStr[l] - '0'), jN * 10 + (cStr[l] - '0') + 1, -1);
			}
			else if (comp == -1)
				Pro(l + 1, n, cN * 10 + (cStr[l] - '0'), jN * 10, comp);
			else Pro(l + 1, n, cN * 10 + (cStr[l] - '0'), jN * 10 + 9, comp);
		}
		else {
			int k;
			if (comp == 0) {
				if (cStr[l] > jStr[l]) k = 1;
				else if (cStr[l] < jStr[l])k = -1;
				else k = 0;
			}
			else k = comp;
			Pro(l + 1, n, cN * 10 + (cStr[l] - '0'), jN * 10 + (jStr[l] - '0'), k);
		}
	}
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tc = 0;++tc <= t;tc) {
		cin >> cStr >> jStr;

		int len = cStr.length();

		resC = resJ = min = 999999999999999999;
		Pro(0, len, 0, 0, 0);

		printf("Case #%d: ", tc);

		int i = 0;
		for (long long k = resC;k;++i, k /= 10);
		for (;i < len;++i)printf("0");
		if (resC != 0)printf("%lld", resC);
		printf(" ");

		i = 0;
		for (long long k = resJ;k;++i, k /= 10);
		for (;i < len;++i)printf("0");
		if (resJ != 0)printf("%lld", resJ);
		printf("\n");

	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}