// a.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 110
const string map = "yhesocvxduiglbkrztnwjpfmaq";
char s[MAXN];

void init(){
	gets(s);
}

void cal(){
	char c;
	for ( int i = 0; i < strlen(s); i ++ ){
		c = s[i];
		if ( c >= 'a' && c <= 'z' )
			cout << map[c-'a'];
		else
			cout << c;
	}
	cout << endl;
}


void tt(){
	char cc[26];
	for ( int i = 0; i < 26; i ++ ){
		cc[ map[i]-'a' ] = (char)(i+'a');
	}
	cout << cc << endl; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	//tt();
	int t, i;
	scanf( "%d\n", &t );
	for ( i = 1; i <= t; i ++ ){
		init();
		cout << "Case #" << i << ": ";
		cal();
	}
	return 0;
}

