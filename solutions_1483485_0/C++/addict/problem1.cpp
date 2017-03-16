#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int replaced(char c) {
	switch (c) {
		case 'a':
			return 'y';
		case 'b':
			return 'h';
		case 'c':
			return 'e';
		case 'd':
			return 's';
		case 'e':
			return 'o';
		case 'f':
			return 'c';
		case 'g':
			return 'v';
		case 'h':
			return 'x';
		case 'i':
			return 'd';
		case 'j':
			return 'u';
		case 'k':
			return 'i';
		case 'l':
			return 'g';
		case 'm':
			return 'l';
		case 'n':
			return 'b';
		case 'o':
			return 'k';
		case 'p':
			return 'r';
		case 'q':
			return 'z';
		case 'r':
			return 't';
		case 's':
			return 'n';
		case 't':
			return 'w';
		case 'u':
			return 'j';
		case 'v':
			return 'p';
		case 'w':
			return 'f';
		case 'x':
			return 'm';
		case 'y':
			return 'a';
		case 'z':
			return 'q';
		case ' ':
			return ' ';
	}
	return c;
}

int main () {
	FILE* In;
	FILE* Out;

	fopen_s(&In, "A-small-attempt1.in", "r");
	fopen_s(&Out, "A-small.out", "w");

	int nTestCases, iTestCase;
	fscanf_s(In, "%d\n", &nTestCases);
	for (iTestCase=0; iTestCase < nTestCases; iTestCase++) {

		int i, n, sec;
		char str[110];
		char str1[110];
		fgets(str, 110, In);
		//fscanf_s(In, "%s", &str);
		i = 0;
		while (str[i] != '\0') {
			str1[i] = replaced(str[i]);
			i++;
		}
		str1[i] = '\0';
		//Write Out Results
		fprintf_s(Out, "Case #%d: ", iTestCase+1);
		fprintf_s(Out, "%s", str1);

	}

	if (In) fclose(In);
	if (Out) fclose(Out);

	return 0;
}
