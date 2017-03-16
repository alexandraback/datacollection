#include<iostream>
#include<stdio.h>
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

string s;
char result[2000];
char cnt[250];
string number[10];
int d[100];
void run(){
	cin >> s;
	FR(i, 0, 250) cnt[i] = 0;
	int len = s.length();
	FR(i, 0, len) cnt[s[i]]++;
	d[8] = cnt['G'];
	d[4] = cnt['U'];
	d[2] = cnt['W'];
	d[6] = cnt['X'];
	d[0] = cnt['Z'];
	d[3] = cnt['H'] - d[8];
	d[7] = cnt['S'] - d[6];
	d[5] = cnt['V'] - d[7];
	d[1] = cnt['O'] - d[0] - d[2] - d[4];
	d[9] = cnt['I'] - d[5] - d[6] - d[8];
	printf(" ");
	FRE(i, 0, 9) FR(j, 0, d[i]) printf("%d",i);
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

/*
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
Z
E
R
O
O
N
E
T
W
O
T
H
R
E
E
F
O
U
R
F
I
V
E
S
I
X
S
E
V
E
N
E
I
G
H
T
N
I
N
E
"
*/