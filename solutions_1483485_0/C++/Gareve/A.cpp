/**
* @author Gareve
*/
#define DEBUGs
#ifndef NDEBUG	
	#define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
	#define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;

string line;
char tr[256];

void resuelva(){
	getline(cin,line);
	for(int i=0;i<line.size();i++){
		line[i] = tr[line[i]];
	}
	cout << line << endl;
}
int main(){
	getline(cin,line);
	int nc;
	sscanf(line.c_str(),"%d",&nc);
	
	tr[' '] = ' ';
	tr['a'] = 'y';
	tr['b'] = 'h';
	tr['c'] = 'e';
	tr['d'] = 's';
	tr['e'] = 'o';
	tr['f'] = 'c';
	tr['g'] = 'v';
	tr['h'] = 'x';
	tr['i'] = 'd';
	tr['j'] = 'u';
	tr['k'] = 'i';
	tr['l'] = 'g';
	tr['m'] = 'l';
	tr['n'] = 'b';
	tr['o'] = 'k';
	tr['p'] = 'r';
	tr['q'] = 'z';
	tr['r'] = 't';
	tr['s'] = 'n';
	tr['t'] = 'w';
	tr['u'] = 'j';
	tr['v'] = 'p';
	tr['w'] = 'f';
	tr['x'] = 'm';
	tr['y'] = 'a';
	tr['z'] = 'q';


	for(int i=1;i<=nc;i++){
		printf("Case #%d: ",i);
		resuelva();
	}
}