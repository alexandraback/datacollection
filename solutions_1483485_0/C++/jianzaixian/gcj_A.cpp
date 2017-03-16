//============================================================================
// Name        : gcj_A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "fstream"
#include "string.h"
#include "stdio.h"

#define N 1000
#define M 40
using namespace std;

char temp[M][N];
int main() {
	/*ifstream cin("a.in");
	ofstream cout("b.out");*/
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	char r[]="yhesocvxduiglbkrztnwjpfmaq";
	for (int i = 0; i < T; ++i) {
		gets(temp[i]);
		int length=strlen(temp[i]);
		for (int j = 0; j < length; ++j) {
			if(temp[i][j]!=' '&&temp[i][j]!='\n')
			temp[i][j]=r[temp[i][j]-'a'];
		}


	}
	for(int i =0;i<T;i++){
		printf("Case #%d: %s\n",i+1,temp[i]);
	}
	return 0;
}
