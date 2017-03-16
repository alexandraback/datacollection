#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define rep(i,n) for(i=0;i<(n);i++)
#define MAX 105

char inps[][100] = {
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"our language is impossible to understand",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"there are twenty six factorial possibilities",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"so it is okay if you want to just give up"
};

char mp[200];
char flag[200];

void init() {
	int i, j;
	memset(mp, 0, sizeof(mp));
	memset(flag,0,sizeof(flag));
	rep(i, 3) {
		for(j=0;inps[2*i][j];j++) {
			mp[ inps[2*i][j] ] = inps[2*i+1][j];
			flag[inps[2*i+1][j]] = 1;
		}
	}
	//rep(i, 26) if(flag[i+'a'] == 0) printf(" %c\n", i+'a');
	//rep(i, 26) if(flag[i+'a'] == 0) 
	//rep(i, 26) if(mp[i+'a'] == 0) printf(" m = %c\n",i+'a');
	mp['z'] = 'q';
	mp['q'] = 'z';

}

int main() {
	int T, kase = 1;
	char s[200];
	int i;
	scanf(" %d",&T); gets(s);
	init();
	while(T--) {
		printf("Case #%d: ", kase++);
		gets(s);
		for(i=0;s[i];i++) {
			if(s[i] == '\n' || s[i] == '\r') break;
			printf("%c", mp[s[i]]);
		}printf("\n");
		
	}
	return 0;
}