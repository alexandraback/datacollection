#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

char translate(char);
char translate(char c)
{
	char t;
	switch (c)
	{
		case ' ': t = ' '; break;
		case 'a': t = 'y'; break;
		case 'b': t = 'h'; break;
		case 'c': t = 'e'; break;
		case 'd': t = 's'; break;
		case 'e': t = 'o'; break;
		case 'f': t = 'c'; break;
		case 'g': t = 'v'; break;
		case 'h': t = 'x'; break;
		case 'i': t = 'd'; break;
		case 'j': t = 'u'; break;
		case 'k': t = 'i'; break;
		case 'l': t = 'g'; break;
		case 'm': t = 'l'; break;
		case 'n': t = 'b'; break;
		case 'o': t = 'k'; break;
		case 'p': t = 'r'; break;
		case 'q': t = 'z'; break;
		case 'r': t = 't'; break;
		case 's': t = 'n'; break;
		case 't': t = 'w'; break;
		case 'u': t = 'j'; break;
		case 'v': t = 'p'; break;
		case 'w': t = 'f'; break;
		case 'x': t = 'm'; break;
		case 'y': t = 'a'; break;
		case 'z': t = 'q'; break;
	}
	return t;
}



int main(void)
{
	char lfeed[1024];
	ifstream in("A.in");
	ofstream out("A.out");
	in.getline(lfeed,1024);
	int cases = atoi(lfeed);
	
	for (int caseid = 1 ; caseid <= cases ; caseid ++)
	{
		in.getline(lfeed,1024);
		out << "Case #" << caseid << ": ";
		for (int k = 0 ; k < strlen(lfeed) ; k ++) out << translate(lfeed[k]);
		out << endl;
	}
	
	in.close();
	out.close();
	return 0;
}
