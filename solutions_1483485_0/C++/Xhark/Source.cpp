#include <stdio.h>
#include <string.h>
char mp[26];
char buf[1024*1024+1];
int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	const char *A[3] = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};
	const char *B[3] = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"
	};
	int i, len;
	for(i=0;i<26;i++) mp[i] = -1;
	for(i=0;i<3;i++){
		int j;
		len = strlen(A[i]);
		for(j=0;j<len;j++){
			if (A[i][j] != ' ') {
				if (mp[ A[i][j]-'a' ] == -1) {
					mp[ A[i][j]-'a' ] = B[i][j];
				} else {
					if (mp[ A[i][j]-'a' ] != B[i][j]) printf("!");
				}
			}
		}
	}
	mp['q'-'a'] = 'z';
	mp['z'-'a'] = 'q';
	for(i=0;i<26;i++){
		if (mp[i] == -1) printf("%c", i+'a');
	}
	int T;
	scanf("%d\n",&T);
	while(T-->0){
		static int cs = 1;
		printf("Case #%d: ", cs++);
		fgets(buf, 1024*1024, stdin);
		int i, len;
		len = strlen(buf);
		for(i=0;i<len;i++){
			if ('a'<=buf[i] && buf[i]<='z') printf("%c", mp[buf[i]-'a']);
			else printf("%c",buf[i]);
		}
	}
	return 0;
}