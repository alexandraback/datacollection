#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int i,j,k,t;
	char buf;
	char map[256];
	FILE *in,*out;
	in = fopen("test.in","r");
	out = fopen("test.out","w");
	map['a'] = 'y'; map['b'] = 'h'; map['c'] = 'e';
	map['d'] = 's'; map['e'] = 'o'; map['f'] = 'c'; 
	map['g'] = 'v'; map['h'] = 'x'; map['i'] = 'd'; 
	map['j'] = 'u'; map['k'] = 'i'; map['l'] = 'g'; 
	map['m'] = 'l'; map['n'] = 'b'; map['o'] = 'k'; 
	map['p'] = 'r'; map['q'] = 'z'; map['r'] = 't'; 
	map['s'] = 'n'; map['t'] = 'w'; map['u'] = 'j'; 
	map['v'] = 'p'; map['w'] = 'f'; map['x'] = 'm'; 
	map['y'] = 'a'; map['z'] = 'q'; map[' '] = ' ';
	fscanf(in,"%d\n",&t);
	for (i = 0; i < t; i++)
	{
		fprintf(out,"Case #%d: ",i+1);
		while (fscanf(in,"%c",&buf)!=EOF&&buf!='\n')
		{
			fprintf(out,"%c",map[buf]);
		}
		fprintf(out,"\n");
	}
	

	
	//fprintf(out,"Case #%d: %d %d\n",count,i+1,j+1);
    return 0;	
}