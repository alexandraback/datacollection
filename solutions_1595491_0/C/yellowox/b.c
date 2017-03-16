#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _T_		100
#define _G_		120

#define MIN(a, b)	((a > b) ? b : a)
#define MAX(a, b)	((a > b) ? a : b)


typedef struct _INFO {
	int n;
	int s;
	int p;

	int t[30];
	int r;
} INFO;

INFO INPUT[_T_];
int LINES;

int
_parse_line(char *line, INFO *info)
{
	char temp[10];
	int i, j;

	i = 0;
	memset(temp, 0, 10);
	while (*line && *line != ' ' && *line != '\n') {
		temp[i++] = *line;

		line++;
	}
	info->n = atoi(temp);

	line++; i = 0;
	memset(temp, 0, 10);
	while (*line && *line != ' ' && *line != '\n') {
		temp[i++] = *line;

		line++;
	}
	info->s = atoi(temp);

	line++; i = 0;
	memset(temp, 0, 10);
	while (*line && *line != ' ' && *line != '\n') {
		temp[i++] = *line;

		line++;
	}
	info->p = atoi(temp);

	for (j = 0; j < info->n; j++) {
		line++; i = 0;
		memset(temp, 0, 10);
		while (*line && *line != ' ' && *line != '\n') {
			temp[i++] = *line;

			line++;
		}

		info->t[j] = atoi(temp);
	}

	return info->n;
}

int
_get_input(char *filename)
{
	char line[1024];
	int ret = -1, i;

	FILE *file = fopen(filename, "r");

	if (!file) {
		printf("%s : failed to open input file\n", __func__);
		goto _end_get_input;
	}

	if (!fgets(line, 10, file)) {
		printf("%s : failed to get count\n", __func__);
		goto _end_get_input;
	}

	LINES = atoi(line);

	if (LINES < 0 || LINES > _T_) {
		printf("%s : failed to get case count\n", __func__);
		goto _end_get_input;
	}

	for (i = 0; i < LINES; i++) {
		if (!fgets(line, sizeof(line), file)) {
			printf("%s : failed to get line %d\n", __func__, i);
			goto _end_get_input;
		}

		_parse_line(line, &INPUT[i]);
	}

	ret = 0;

_end_get_input:
	if (file) fclose(file);

	return ret;
}

int
_get_result(INFO *info)
{
	int a, i, r, count, s;

	count = 0; s = 0;
	for (i = 0; i < info->n; i++) {
		if (info->t[i] < info->p) continue;

		a = info->t[i] / 3;
		r = info->t[i] - (a * 3);

		if (a >= info->p) count++;
		else if (((a + 1) == info->p) && r) count++;
		else if (((a + 1) == info->p) && !r) s++;
		else if (((a + 2) == info->p) && r == 2) s++;
	}

	info->r = count + MIN(info->s, s);

	return info->r;
}

int
main(int argc, char *argv[])
{
	int i;
	FILE *fo;

	printf("Problem B\n");

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
		_get_result(&INPUT[i]);

		fprintf(fo, "Case #%d: %d\n", i + 1, INPUT[i].r);
	}

	fclose(fo);

	return 0;
}

