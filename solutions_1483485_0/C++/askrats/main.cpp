#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string>

#define FORr(i,A,B)	for (int i=(A); i<(B); ++i)
#define FOR(i, N)	FORr(i,0,N)

using namespace std;

int 	get_int()		{int a; 	scanf("%d", &a); 	return a;}
double	get_double()	{double a;	scanf("%lf", &a);	return a;}
char	get_char()		{char c; 	scanf("%c", &c); 	return c;}

char str_buf[100000];
string	get_str()		{scanf("%s", str_buf); return str_buf;}

const int cNumSample = 4;

char map[26];
char map_r[26];
char *sample[cNumSample][2] = {
	{
		"y qee",
		"a zoo",
	},
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
};

void set_map(char g, char e)
{
	if ( 'a' <= g && g <= 'z' && 'a' <= e && e <= 'z' ) {
		map[g - 'a'] = e;
		map_r[e - 'a'] = ' ';
	}
}

char get_map(char g)
{
	if ( 'a' <= g && g <= 'z' ) {
		return map[g - 'a'];
	}
	else if( g == ' ' ) {
		return ' ';
	}
	return '*';
}

void init_map()
{
	// init
	FOR(i, 26) {
		map[i] = ' ';
		map_r[i] = 'a' + i;
	}

	// solve sample
	FOR(s, cNumSample) {
		FOR(i, 100) {
			char ch = sample[s][0][i];
			if (ch == '\0') break;
			set_map(ch, sample[s][1][i]);
		}
	}

	// remain
	FOR(i_map, 26) {
		if (map[i_map] == ' ') {
			FOR(i_r, 26) {
				if (map_r[i_r] != ' ') {
					set_map(i_map + 'a', map_r[i_r]);
					break;
				}
			}
			break;
		}
	}

#if 0
	//
	FOR(i, 26) {
		printf("%c", 'a'+i);
	}
	printf("\n");
	FOR(i, 26) {
		printf("%c", map[i]);
	}
	printf("\n");
	FOR(i, 26) {
		printf("%c", map_r[i]);
	}
	printf("\n");
#endif
}

void solve()
{
	do {
		char ch = get_char();
		if ( ch == '\n' ) break;
		printf("%c", get_map(ch));
	} while (1);
}

int main()
{
	init_map();

	int T = get_int();
	get_char();

	FOR (t, T)
	{
		printf("Case #%d: ", t + 1);
		solve();
		printf("\n");
	}
}
