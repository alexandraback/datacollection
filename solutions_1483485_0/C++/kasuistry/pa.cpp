
#include <cstdio>

int main(){
	
	char s[3][101] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};

	char r[3][101] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
	};

	char map[26];

	for(int i=0; i<26; ++i){
		map[i] = -1;
	}

	for(int i=0; i<3; ++i){
		for(int j=0; j<101; ++j){
			if(r[i][j] == '\0'){
				break;
			}
			if(r[i][j] >= 'a' && r[i][j] <= 'z'){
				map[s[i][j]-'a'] = r[i][j];
			}
		}
	}
	
	map['z'-'a'] = 'q';
	map['q'-'a'] = 'z';

	int testcase; scanf("%d", &testcase);
	char buf[101];
	gets(buf);

	for(int t=1; t<=testcase; ++t){
		gets(buf);
		printf("Case #%d: ", t);
		for(int i=0; i<101; ++i){
			if(buf[i] == '\0'){
				printf("\n");
				break;
			}
			printf("%c", (buf[i]==' ') ? ' ' : map[buf[i]-'a']);
		}
	}
	return 0;
}
