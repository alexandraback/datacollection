#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s1[][100] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"};

char s2[][100] = {"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"};

char dict[200];
char s[200], ans[200];

int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; s1[i][j]; j++){
			dict[s1[i][j]] = s2[i][j];
		}
	}
	dict['q'] = 'z';
	dict['z'] = 'q';
	/*
	for(char i = 'a'; i <= 'z'; i++)
		if(dict[i])
			printf("%c : %c\n", i, dict[i]);
		else
			printf("%c\n", i);
	*/
	int n;
	scanf("%d ", &n);
	for(int re = 1; re <= n; re++){
		gets(s);
		strcpy(ans, s);
		for(int i = 0; s[i]; i++)
			if(islower(s[i])){
				ans[i] = dict[s[i]];
			}
		printf("Case #%d: ", re);
		puts(ans);
	}
}
