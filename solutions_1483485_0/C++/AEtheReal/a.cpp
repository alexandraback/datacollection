#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int m[26];

char sti[] = "yeq ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char sto[] = "aoz our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";


char s[11111];

int main() {

	FOR(i,0,26) m[i] = -1;
	FORS(i, sti) if(sti[i] != ' '){
		if(m[sti[i]-'a'] >= 0 && m[sti[i]-'a'] != sto[i]-'a') printf("WRONG %d %c %c\n",i,m[sti[i]-'a']+'a', sto[i]);
		m[sti[i]-'a'] = sto[i]-'a';
	}
	FOR(i,0,26) if(m[i] < 0){
		m[i] = 0;
		FOR(k,0,100)FOR(j,0,26) if(i!=j && m[i]==m[j]) m[i]++;
	}

int nt, tt=0; gets(s); sscanf(s, "%d", &nt); while(nt--){
	gets(s);
	FORS(i, s) if(s[i]!=' ') s[i] = m[s[i]-'a'] + 'a';

	printf("Case #%d: %s\n", ++tt, s);
}
	return 0;
}


