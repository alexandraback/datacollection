#include <stdio.h>
#include <string.h>

char tran(char ch) {
	switch(ch){
		case 'y': return 'a';
		case 'n': return 'b';
		case 'f': return 'c';
		case 'i': return 'd';
		case 'c': return 'e';
		case 'w': return 'f';
		case 'l': return 'g';
		case 'b': return 'h';
		case 'k': return 'i';
		case 'u': return 'j';
		case 'o': return 'k';
		case 'm': return 'l';
		case 'x': return 'm';
		case 's': return 'n';
		case 'e': return 'o';
		case 'v': return 'p';
		case 'z': return 'q';
		case 'p': return 'r';
		case 'd': return 's';
		case 'r': return 't';
		case 'j': return 'u';
		case 'g': return 'v';
		case 't': return 'w';
		case 'h': return 'x';
		case 'a': return 'y';
		case 'q': return 'z';
		default: return ' ';
	}
}

int main(int argc, char const *argv[])
{
	FILE *fin,*fout;
	int len,t,i,count;
	char g[102];

	fin  = fopen("a.in","r");
	fscanf(fin,"%d\n", &t);
	fout = fopen("a.out","w");
	for (count = 1; count <= t; count++) {
		fgets(g, 102, fin);
		len = strlen(g);
		for (i=0;i<len;i++) g[i] = tran(g[i]);
		fprintf(fout,"Case #%d: %s\n", count, g);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}