#include <assert.h>
#include <stdio.h>
#include <string.h>

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

const char *C[] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

const char *P[] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

char s[100000];
int TC, M[255];

int main(){
	int has[255] = {0};
	REP(i,3){
		REP(j,strlen(C[i])){
			has[P[i][j]] = 1;
			if (M[C[i][j]])
				assert(M[C[i][j]] == P[i][j]);
			else 
				M[C[i][j]] = P[i][j];
		}
	}
	for (int i='a'; i<='z'; i++)
		if (!has[i]) fprintf(stderr,"unused plain = %c\n",i);
	M['q'] = 'z';
	M['z'] = 'q';
	sscanf(gets(s),"%d",&TC);
	for (int tc=1; TC--; tc++){
		printf("Case #%d: ",tc);
		gets(s);
		REP(i,strlen(s)) if (!M[s[i]]) fprintf(stderr,"unknown ciper = %c\n",s[i]);
		REP(i,strlen(s)) printf("%c",M[s[i]]?M[s[i]]:'?');
		puts("");
	}
}
