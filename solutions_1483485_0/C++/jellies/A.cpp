#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

char data[26]={
'y',//a
'h',//b
'e',//c
's',//d
'o',//e
'c',//f
'v',//g
'x',//h
'd',//i
'u',//j
'i',//k
'g',//l
'l',//m
'b',//n
'k',//o
'r',//p
'z',//q
't',//r
'n',//s
'w',//t
'j',//u
'p',//v
'f',//w
'm',//x
'a',//y
'q',//z
};

int main(void){
	int casenum;
	scanf("%d ",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){
		string in,out;
		getline(cin,in);

		for(int i=0;i<in.size();i++){
			if(isalpha(in[i])){
				out+=data[(in[i]-'a')];
			}
			if(in[i]==' '){
				out+=' ';
			}
		}

		printf("Case #%d: %s\n",casecnt,out.c_str());
		fflush(stdout);
	}
	return 0;
}
