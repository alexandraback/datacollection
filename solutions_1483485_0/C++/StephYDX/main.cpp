#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <time.h>
using namespace std;
typedef long long llong;

inline int bit(int x, int i){ return (x>>i) & 1;}
inline int setb(int x, int i){ return x | (1 << i);}
inline int clrb(int x, int i){ return x & (~(1 << i));}
inline int lowb(int x){return x & (-x);}

const char *hint[][2]={
{
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"our language is impossible to understand",
},
{
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "there are twenty six factorial possibilities",
},
{
    "de kr kd eoya kw aej tysr re ujdr lkgc jv",
    "so it is okay if you want to just give up",
},
{
	"y qee",
 	"a zoo",
},
{
	"z",
	"q",
},
};

char rep[256];

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("As0.txt", "w", stdout);
	for(int i = 0;i < 256; ++i) rep[i] = '_';
	int cnt_h = sizeof(hint) / sizeof(hint[0]);
	for(int i = 0;i < cnt_h; ++i){
		const char *s1 = hint[i][0];
		const char *s2 = hint[i][1];
		while(*s1){
			/*
			if(rep[*s1] != '_' && rep[*s1] != *s2){
				puts("ERROR");
				printf("%c -> %c %c", *s1, rep[*s1], *s2);
			}*/
			rep[*s1] = *s2;
			++s1;
			++s2;
		}
	}
	//for(int i = 'a'; i <= 'z'; ++i) printf("%c",i);puts("");
	//for(int i = 'a'; i <= 'z'; ++i) printf("%c",rep[i]);puts("");
	int TT;
	char buf[105];
	scanf("%d", &TT);
	gets(buf);
	for(int cas = 1; cas <= TT; ++cas){
		gets(buf);
		for(int i = 0;buf[i]; ++i){
			buf[i] = rep[buf[i]];
		}
		printf("Case #%d: %s\n", cas, buf);
	}
	return 0;
}

