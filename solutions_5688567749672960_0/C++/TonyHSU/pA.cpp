#include<cstdio>
#include<string.h>

int look[1000001];

int main() {
	for (int tar=0;tar<=1000000;tar++) {
		look[tar] = tar;
	}
	for (int tar=1;tar<=1000000;tar++) {
		if (look[tar] > look[tar-1]+1) {
			look[tar] = look[tar-1]+1;
		}
		char tmp[10];
		sprintf(tmp, "%d", tar);
		int len = strlen(tmp);
		int i;
		for (i=len-1;i>=0;i--) {
			if (tmp[i]!='0') break;
		}
		char tmp2[10];
		tmp[i+1] = '\0';
		tmp2[i+1] = '\0';
		for (int j=0;j<=i;j++) {
			tmp2[j] = tmp[i-j];
		}
		int ans2;
		sscanf(tmp2, "%d", &ans2);
		if (look[tar] + 1 < look[ans2]){
			look[ans2] = look[tar] + 1;
			if (ans2 < tar) {
				tar = ans2-1;
			}
		}
	}
	int T;
	scanf("%d", &T);
	for (int nm=1;nm<=T;nm++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", nm, look[n]);
	}
	return 0;
}
