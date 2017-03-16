#include <iostream>
#include <cstdio>
using namespace std;
char map[256];
int main(){
	map[' '] = ' ';
	map['a'] = 'y';
	map['b'] = 'h';
	map['c'] = 'e';
	map['d'] = 's';
	map['e'] = 'o';
	map['f'] = 'c';
	map['g'] = 'v';
	map['h'] = 'x';
	map['i'] = 'd';
	map['j'] = 'u';
	map['k'] = 'i';
	map['l'] = 'g';
	map['m'] = 'l';
	map['n'] = 'b';
	map['o'] = 'k';
	map['p'] = 'r';
	map['q'] = 'z';
	map['r'] = 't';
	map['s'] = 'n';
	map['t'] = 'w';
	map['u'] = 'j';
	map['v'] = 'p';
	map['w'] = 'f';
	map['x'] = 'm';
	map['y'] = 'a';
	map['z'] = 'q';
	FILE *fin = fopen("input.txt","r"), *fout = fopen("output.txt","w");
	int T;
	fscanf(fin,"%d",&T);
	char c;
	fscanf(fin,"%c",&c);//Flush
	for (int i = 0; i < T; i++){
		fprintf(fout,"Case #%d: ",i+1);
		fscanf(fin,"%c",&c);
		while (c!='\n'){
			fprintf(fout,"%c",map[c]);
			fscanf(fin,"%c",&c);
		}
		fprintf(fout,"\n");
	}
	return 0;
}
