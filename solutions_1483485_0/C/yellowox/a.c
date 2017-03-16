#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _T_		30
#define _C_		120

char *G[3] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

char *E[3] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

char M[26];
char l[26];

char INPUT[_T_][_C_ + 1];
char OUTPUT[_T_][_C_ + 1];

int LINES;

int
_make_map(void)
{
	int i, count;
	char *e, *g;
	char a, b;

	memset(M, '?', 26);
	memset(l, ' ', 26);

	M['q' - 'a'] = 'z';
	l['z' - 'a'] = 'o';

	for (i = 0; i < 3; i++) {
		e = E[i];
		g = G[i];

		while (*e) {
			if (*g != ' ') {
				M[(*g - 'a')] = *e;
				l[(*e - 'a')] = 'o';
			}

			e++, g++;
		}
	}

	count = 0;
	for (i = 0; i < 26; i++) {
		if (l[i] != 'o') {
			count++;
			a = i;
		}

		if (M[i] == '?') {
			b = i;
		}
	}

	if (count == 1) {
		M[b] = a + 'a';

		return 0;
	}

	return -1;
}

int
_translate(char *input, char *output)
{
	while (*input) {
		if (*input == '\n')
			break;

		if (*input != ' ')
			*output = M[*input - 'a'];
		else
			*output = *input;

		input++, output++;
	}

	return 0;
}

int
_get_input(char *filename)
{
	char num[10];
	int ret = -1, i;

	FILE *file = fopen(filename, "r");

	if (!file) {
		printf("%s : failed to open input file\n", __func__);
		goto _end_get_input;
	}

	if (!fgets(num, 10, file)) {
		printf("%s : failed to get count\n", __func__);
		goto _end_get_input;
	}

	LINES = atoi(num);
	if (LINES < 0 || LINES > _T_) {
		printf("%s : failed to get case count\n", __func__);
		goto _end_get_input;
	}

	for (i = 0; i < LINES; i++) {
		if (!fgets(INPUT[i], _C_, file)) {
			printf("%s : failed to get line %d\n", __func__, i);
			goto _end_get_input;
		}
	}

	ret = 0;

_end_get_input:
	if (file) fclose(file);

	return ret;
}

int
main(int argc, char *argv[])
{
	int i;
	FILE *fo;

	printf("Problem A\n");

	i = _make_map();
	if (i == 0) {
		printf("abcdefghijklmnopqrstuvwxyz\n");
		for (i = 0; i < 26; i++)
			putc(M[i], stdout);

		putc('\n', stdout);

		i = 0;
	} else {
		printf("invalid vector\n");
		return -1;
	}

	i = _get_input(argv[1]);
	if (i < 0)
		return i;
	else
		printf("get input file %d cases\n", LINES);


	fo = fopen(argv[2], "w");
	if (!fo) {
		printf("failed to open output file\n");
		return -1;
	}

	for (i = 0; i < LINES; i++) {
		memset(OUTPUT[i], 0, _C_+1);
		_translate(INPUT[i], OUTPUT[i]);

		fprintf(fo, "Case #%d: %s\n", i + 1, OUTPUT[i]);
	}

	fclose(fo);

	return 0;
}

