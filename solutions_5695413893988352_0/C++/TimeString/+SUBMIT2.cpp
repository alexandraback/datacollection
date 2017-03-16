#include <stdio.h>
#include <string.h>

long long base10[20];
long long now_min_diff;
char reg[20];
char rec[20];
long long re_num_g;
long long re_num_c;

long long abs(long long n) {
	if (n < 0)
		return -n;
	return n;
}

void dfs(int level, char prefix_status, char input_g[], char input_c[], int str_len, char cur_g[], char cur_c[]) {
	//printf("dfs %d %c\n", level, prefix_status);
	if (level == str_len) {
		long long num_g, num_c;
		sscanf(cur_g, "%lld", &num_g);
		sscanf(cur_c, "%lld", &num_c);
		long long diff = abs(num_g - num_c);
		bool update = false;
		if (diff < now_min_diff)
			update = true;
		else if (diff == now_min_diff) {
			if (num_g < re_num_g)
				update = true;
			else if (num_g == re_num_g) {
				if (num_c < re_num_c)
					update = true;
			}
		}
		//printf("   find %lld %lld (%s %s)\n", num_g, num_c, cur_g, cur_c);

		if (update) {
			now_min_diff = diff;
			strcpy(reg, cur_g);
			strcpy(rec, cur_c);
			re_num_g = num_g;
			re_num_c = num_c;
		}
		return;
	}

	if (prefix_status == 'g') {
		if (input_g[level] == '?')
			cur_g[level] = '0';
		else
			cur_g[level] = input_g[level];
		if (input_c[level] == '?')
			cur_c[level] = '9';
		else
			cur_c[level] = input_c[level];
		dfs(level+1, prefix_status, input_g, input_c, str_len, cur_g, cur_c);
	}
	else if (prefix_status == 'c') {
		if (input_g[level] == '?')
			cur_g[level] = '9';
		else
			cur_g[level] = input_g[level];
		if (input_c[level] == '?')
			cur_c[level] = '0';
		else
			cur_c[level] = input_c[level];
		dfs(level+1, prefix_status, input_g, input_c, str_len, cur_g, cur_c);
	}
	else {
		if (input_g[level] != '?' && input_c[level] != '?') {
			char next_status = 'x';
			if (input_g[level] > input_c[level])
				next_status = 'g';
			else if (input_g[level] < input_c[level])
				next_status = 'c';
			cur_g[level] = input_g[level];
			cur_c[level] = input_c[level];
			dfs(level+1, next_status, input_g, input_c, str_len, cur_g, cur_c);
		}
		else if (input_g[level] == '?' && input_c[level] == '?') {
			cur_g[level] = '0';
			cur_c[level] = '0';
			dfs(level+1, 'x', input_g, input_c, str_len, cur_g, cur_c);
			cur_g[level] = '1';
			cur_c[level] = '0';
			dfs(level+1, 'g', input_g, input_c, str_len, cur_g, cur_c);
			cur_g[level] = '0';
			cur_c[level] = '1';
			dfs(level+1, 'c', input_g, input_c, str_len, cur_g, cur_c);
		}
		else if (input_g[level] == '?') {
			cur_c[level] = input_c[level];
			cur_g[level] = cur_c[level];
			dfs(level+1, 'x', input_g, input_c, str_len, cur_g, cur_c);
			if (cur_c[level] < '9') {
				cur_g[level] = cur_c[level] + 1;
				dfs(level+1, 'g', input_g, input_c, str_len, cur_g, cur_c);
			}
			if (cur_c[level] > '0') {
				cur_g[level] = cur_c[level] - 1;
				dfs(level+1, 'c', input_g, input_c, str_len, cur_g, cur_c);
			}
		}
		else if (input_c[level] == '?') {
			cur_g[level] = input_g[level];
			cur_c[level] = cur_g[level];
			dfs(level+1, 'x', input_g, input_c, str_len, cur_g, cur_c);
			if (cur_g[level] < '9') {
				cur_c[level] = cur_g[level] + 1;
				dfs(level+1, 'c', input_g, input_c, str_len, cur_g, cur_c);
			}
			if (cur_g[level] > '0') {
				cur_c[level] = cur_g[level] - 1;
				dfs(level+1, 'g', input_g, input_c, str_len, cur_g, cur_c);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}

	base10[0] = 1; 
	for (int i = 1; i < 20; i++)
		base10[i] = base10[i-1] * 10;

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		char g[100], c[100];
		int len;
		scanf("%s%s", g, c);
		len = strlen(g);
		long long weights[20];
		for (int i = 0; i < len; i++)
			weights[i] = base10[len - 1 - i];
		char curg[100], curc[100];
		strcpy(curg, g);
		strcpy(curc, c);
		now_min_diff = base10[len];
		dfs(0, 'x', g, c, len, curg, curc);

		printf("Case #%d: %s %s\n", ecount, reg, rec);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
