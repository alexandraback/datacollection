#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#define SUBMIT 1
using namespace std;

int cnt[256];
int res[10];
void file_reopen() {
	freopen("c:\\codejam\\input.txt", "r", stdin);
	freopen("c:\\codejam\\output.txt", "w", stdout);
}
char buf[2001];
int main(void) {
	if (SUBMIT) file_reopen();

	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		scanf("%s", buf);
		for (int i = 0; i < 256; i++) cnt[i] = 0;
		for (int i = 0; i < 10; i++) res[i] = 0;
		for (int i = 0; i < strlen(buf); i++) {
			if ('A' <= buf[i] && buf[i] <= 'Z') cnt[buf[i]]++;
		}
		res[0] = cnt['Z'];
		res[2] = cnt['W'];
		res[4] = cnt['U'];
		res[5] = cnt['F'] - res[4];
		res[6] = cnt['X'];
		res[7] = cnt['V'] - res[5];
		res[8] = cnt['G'];
		res[3] = cnt['H'] - res[8];
		res[9] = cnt['I'] - (res[5] + res[6] + res[8]);
		res[1] = cnt['N'] -( res[7] + res[9] * 2);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < res[i]; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
	}	
	return 0;
}