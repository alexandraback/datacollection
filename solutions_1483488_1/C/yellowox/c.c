#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _T_		100
#define _G_		120

#define MIN(a, b)	((a > b) ? b : a)
#define MAX(a, b)	((a > b) ? a : b)


typedef struct _INFO {
	char A[10];
	char B[10];

	int a;
	int b;

	int r;
} INFO;

INFO INPUT[_T_];
int LINES;

int
_parse_line(char *line, INFO *info)
{
	int i = 0;
	memset(info->A, 0, 10);
	while (*line && *line != ' ' && *line != '\n') {
		info->A[i++] = *line;

		line++;
	}
	info->a = atoi(info->A);

	line++; i = 0;
	memset(info->B, 0, 10);
	while (*line && *line != ' ' && *line != '\n') {
		info->B[i++] = *line;

		line++;
	}
	info->b = atoi(info->B);

	return 0;
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
_get_num(char *num, int j, int len)
{
	int i, k;
	char first;
	char temp[10];

	memcpy(temp, num, len);
	temp[len] = '\0';

	for (i = 0; i < j; i++) {
		first = temp[0];
		for (k = 0; k < (len - 1); k++) {
			temp[k] = temp[k+1];
		}

		temp[len - 1] = first;
	}

	return atoi(temp);
}

int
_get_result(INFO *info)
{
	int n, m, i, j, l;
	int count, same;
	char num[10];
	int mm[10];

	count = 0;
	for (n = info->a; n < info->b; n++) {
		if (n < 10) continue;

		sprintf(num, "%d", n);
		l = strlen(num);

		memset(mm, -1, sizeof(mm));

		for (i = 1; i < l; i++) {
			m = _get_num(num, i, l);
			mm[i] = m;

			same = 0;
			for (j = 1; j < i - 1; j++) {
				if (mm[j] == m) {
					same = 1;
					break;
				}
			}

			if (same == 0 && m > n && info->b >= m) {
				count++;
			}
		}
	}

	info->r = count;

	return info->r;
}

int
main(int argc, char *argv[])
{
	int i;
	FILE *fo;

	printf("Problem C\n");

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

