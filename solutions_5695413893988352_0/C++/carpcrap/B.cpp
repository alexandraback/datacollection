#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <algorithm>
#define FR(i,a,b) for(i=a;i<b;++i)
#define FRS(i,a,b,s) for(i=a;i<b;i+=s)
#define FRE(i,a,b) for(i=a;i<=b;++i)
#define FRES(i,a,b,s) for(i=a;i<=b;i+=s)
// 0->tt-1		FR(i, 0, tt) printf(" 1");
// 0,2,4->tt-1	FRS(i, 0, tt, 2) printf(" 2");
// 0->tt		FRE(i, 0, tt) printf(" 3");
// 0,2,4->tt	FRES(i, 0, tt, 2) printf(" 4");
using namespace std;

int i, j, k;
int tt;

int minDiff;
string s[10];
void recur(int level) {
	if (level == s[0].length() + s[1].length()) {
		//cout << "!!! " << s[0] << " " << s[1];
		int a = atoi(s[0].c_str());
		int b = atoi(s[1].c_str());
		if (abs(a - b) < minDiff) {
			s[2] = s[0];
			s[3] = s[1];
			minDiff = abs(a - b);
		}
		return;
	}
	int i1 =0, i2=level;
	if (level >= s[0].length()) {
		i1++; i2 = level - s[0].length();
	}
	if (s[i1][i2] != '?') {
		recur(level + 1); return;
	}
	char c;
	FR(c, '0', '9' + 1) {
		s[i1][i2] = c;
		recur(level + 1);
		s[i1][i2] = '?';
	}
}
void run(){
	cin >> s[0] >> s[1];
	minDiff = 99999;
	recur(0);
	cout << " " << s[2] << " " << s[3];
}

int main(){
	int T;
	scanf("%d", &T);
	for(tt =1; tt<=T; tt++){
		printf("Case #%d:",tt); // standard
		run();
		printf("\n"); // endline
	}
	return 0;
}
