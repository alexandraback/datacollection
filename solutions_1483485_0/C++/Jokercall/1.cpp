#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int T;


char convert(char a){

	switch(a){
	case 'a': return 'y';
	case 'b': return 'h';
	case 'c': return 'e';
	case 'd': return 's';
	case 'e': return 'o';
	case 'f': return 'c';
	case 'g': return 'v';
	case 'h': return 'x';
	case 'i': return 'd';
	case 'j': return 'u';
	case 'k': return 'i';
	case 'l': return 'g';
	case 'm': return 'l';
	case 'n': return 'b';
	case 'o': return 'k';
	case 'p': return 'r';
	case 'q': return 'z';
	case 'r': return 't';
	case 's': return 'n';
	case 't': return 'w';
	case 'u': return 'j';
	case 'v': return 'p';
	case 'w': return 'f';
	case 'x': return 'm';
	case 'y': return 'a';
	case 'z': return 'q';
	case ' ': return ' ';
	default : return ' ';

	}

}

char str[500];


void input(){
	cin.getline(str, 400);
}
void solve(){
	FILE *fp = fopen("out1.out","w");
	input();
	for(int k=0; k< T ;k++){
		input();
		int len = strlen(str);
		fprintf(fp,"Case #%d: ",k+1);
		for(int i=0; i < len ; i++){
			fprintf(fp,"%c",convert(str[i]));
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
int main()
{
	cin>>T;
	solve();
}