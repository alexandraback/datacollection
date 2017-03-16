#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define GABRIEL		1
#define RICHARD		2

#define SUCCESS		GABRIEL
#define FAIL		RICHARD

int get_result(int xarg, int rarg, int carg)
{
	int min, max;

	if (rarg > carg) {
		min = carg;
		max = rarg;
	} else {
		min = rarg;
		max = carg;
	}

	if ((rarg * carg) % xarg != 0)
		return FAIL;

	if (xarg > max)
		return FAIL;

	if (xarg > (min * 2))
		return FAIL;

	if (min == 2 && xarg >= (min * 2))
		return FAIL;

	return SUCCESS;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[4096];
	int cnt;
	int i;

	fp = fopen("test.in", "r");
	if (!fp) {
		printf("Failed to open test.in\n");
		return -1;
	}

	if (!fgets(buf, sizeof(buf), fp)) {
		printf("Failed to fgets: %d\n", __LINE__);
		return -1;
	}

	cnt = atoi(buf);

	for (i = 0; i < cnt; i++) {
		int res;
		int xarg, rarg, carg;

		if (!fgets(buf, sizeof(buf), fp)) {
			printf("Failed to fgets #%d\n", i);
			return -1;
		}

		sscanf(buf, "%d %d %d", &xarg, &rarg, &carg);

		res = get_result(xarg, rarg, carg);

		//printf("%s", buf);
		printf("Case #%d: %s\n", i + 1, res == GABRIEL ? "GABRIEL" : "RICHARD");
		//printf("\n");
	}

	fclose(fp);

	return 0;
}
