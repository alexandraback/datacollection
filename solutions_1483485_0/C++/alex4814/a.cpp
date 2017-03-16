#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define length 200

char trans[26];
char g[length];
char s[length];
char s1[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char s2[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char s3[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
char g1[] = "our language is impossible to understand";
char g2[] = "there are twenty six factorial possibilities";
char g3[] = "so it is okay if you want to just give up";

void gettrans(char *p, char *t)
{
	int i;
	int len = strlen(p);
	for (i = 0; i < len; ++i) {
		if (t[i] == ' ') continue;
		trans[t[i] - 'a'] = p[i];
	}
}

void decryption()
{
	int i;
	int len = strlen(s);
	for (i = 0; i < len - 1; ++i)
		g[i] = s[i] == ' ' ? ' ' : trans[s[i] - 'a'];
	g[i] = '\0';
}

int main()
{
	FILE *fin = freopen("A-small-attempt2.in.txt", "r", stdin);
	FILE *fout = freopen("out.txt", "w", stdout);
	int i, c, t;
	gettrans(g1, s1);
	gettrans(g2, s2);
	gettrans(g3, s3);
	trans['q' - 'a'] = 'z';
	trans['z' - 'a'] = 'q';
	/*
	for (i = 0; i < 26; ++i) {
		printf("%c %c\n", i + 'a', trans[i]);
	}
	int in[26] = {0};
	for (i = 0; i < 26; ++i)
		if (trans[i]) in[trans[i] - 'a'] = 1;
	for (i = 0; i < 26; ++i)
		if (!in[i]) printf("%c\n", i + 'a'); 
	*/
	fscanf(fin, "%d", &t);
	fgetc(fin);
	for (c = 1; c <= t; ++c) {
		fgets(s, length, fin);
		decryption();
		fprintf(fout, "Case #%d: %s\n", c, g);
	}
	return 0;
}
