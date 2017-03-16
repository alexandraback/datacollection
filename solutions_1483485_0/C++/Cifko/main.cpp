#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "string.h"
#include "math.h"

FILE *fin, *fout;

#define INPUT_FILE_NAME "A-small-attempt0"
#define INPUT_FILE INPUT_FILE_NAME##".in"
#define OUTPUT_FILE INPUT_FILE_NAME##".out"

#define print(format,...) {fprintf(fout, format, __VA_ARGS__); printf(format, __VA_ARGS__);}

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

void problem(int nCase);
void init();

void main(int argc, char **argv)
{
	int N,k;
	printf("%s\n", INPUT_FILE);
	fopen_s(&fin, INPUT_FILE, "rt");
	fopen_s(&fout, OUTPUT_FILE, "wt");
	fscanf_s(fin, "%d\n", &N);
	k=0;
	init();
	while(N--)
	{
		++k;
		print("Case #%d: ", k);
		problem(k);
		print("\n");
	}
	fclose(fin);
	fclose(fout);
}

char charmap[256];

void init()
{
	charmap['y'] = 'a';
	charmap['n'] = 'b';
	charmap['f'] = 'c';
	charmap['i'] = 'd';
	charmap['c'] = 'e';
	charmap['w'] = 'f';
	charmap['l'] = 'g';
	charmap['b'] = 'h';
	charmap['k'] = 'i';
	charmap['u'] = 'j';
	charmap['o'] = 'k';
	charmap['m'] = 'l'; 
	charmap['x'] = 'm';
	charmap['s'] = 'n';
	charmap['e'] = 'o';
	charmap['v'] = 'p';
	charmap['z'] = 'q';
	charmap['p'] = 'r'; 
	charmap['d'] = 's';
	charmap['r'] = 't';
	charmap['j'] = 'u';
	charmap['g'] = 'v';
	charmap['t'] = 'w';
	charmap['h'] = 'x';
	charmap['a'] = 'y';
	charmap['q'] = 'z';
	charmap[' '] = ' ';
}

void problem(int nCase)
{
	char line[110];
	int i;
	fgets(line, 110, fin);
	for (i=0;line[i]!=0 && line[i]!=0xA && line[i]!=0xD;++i)
	{
		fprintf_s(fout, "%c", charmap[line[i]]);
	}
}