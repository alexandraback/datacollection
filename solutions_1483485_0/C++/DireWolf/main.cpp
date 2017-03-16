#pragma comment(linker, "/STACK:268435456")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stack>

using namespace std;

char in[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"};
char out[] = {"our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"};

char *code = {"yhesocvxduiglbkrztnwjpfmaq"};

int main(){
	ofstream myout("A-small-attempt0.out");
	ifstream myin("A-small-attempt0.in");
		int t;
	myin >> t;
	char * pom = new char[101];
	myin.getline(pom,101);
	for(int i=0 ; i<t ; i++){
		myout << "Case #" << i+1 << ": ";
		myin.getline(pom,101);
		for(int j = 0 ; j<strlen(pom) ; j++){
			if(pom[j] != ' ')
				myout << code[pom[j] - 'a'];
			else
				myout << " ";
		}
		myout << endl;
	}
}