#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

/*
bool cmp(struct  a, struct iin b) {
	return (a.start > b.start);
}
*/

char input[101][105];
char s_input[101][105];

int main() {
	int T, nm= 1;
	int i, j, k;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (i=0;i<n;i++) {
			scanf("%s", s_input[i]);
		}
		for (i=0;i<n;i++) {
			int ct= 1;
			input[i][0]= s_input[i][0];
			for (j=1;s_input[i][j]!='\0';j++) {
				//printf("j= %d, ct= %d, old= %c, new= %c\n", j, ct, s_input[i][j], input[i][ct-1]);
				if (s_input[i][j] != input[i][ct-1]) {
					input[i][ct++]= s_input[i][j];
				}
			}
			input[i][ct]= '\0';
		}
		//for (i=0;i<n;i++) {
		//	printf("%s\n", input[i]);
		//}
		int per[101];
		for (i=0;i<n;i++) {
			per[i]= i;
		}
		int ans= 0;
		do {
			int save[300]= {0};
			char pre= input[per[0]][0];
			save[pre]= 1;
			int pass= 1;
			for (i=0;i<n;i++) {
				int round= per[i];
				for (j=0;input[round][j]!='\0';j++) {
					if (save[input[round][j]]==1 && input[round][j]!=pre) {
						pass= 0;
						break;
					}
					else {
						save[input[round][j]]= 1;
						pre= input[round][j];
					}
				}
				if (!pass) break;
			}
			if (pass) ans++;
		}
		while (next_permutation(per,per+n));
		printf("Case #%d: %d\n", nm++, ans);
	}
	return 0;
}
