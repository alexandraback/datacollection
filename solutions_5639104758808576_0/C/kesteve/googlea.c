#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_extra_audience(char *buf)
{
	int maxs;

	int cur_up = 0;
	int extra_needed = 0;
	int shy;

	sscanf(buf, "%d ", &maxs);

	buf = strchr(buf, ' ') + 1;

	for (shy = 0; shy <= maxs; shy++) {
		int this_level_cnt = buf[shy] - 48;

		if (this_level_cnt == 0)
			continue;

		if (cur_up < shy) {
			extra_needed += (shy - cur_up);
			cur_up += (shy - cur_up) + this_level_cnt;
		} else {
			cur_up += this_level_cnt;
		}
	}

	return extra_needed;
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

		if (!fgets(buf, sizeof(buf), fp)) {
			printf("Failed to fgets #%d\n", i);
			return -1;
		}

		res = get_extra_audience(buf);

		printf("Case #%d: %d\n", i + 1, res);
	}

	fclose(fp);

	return 0;
}
