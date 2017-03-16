#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
string v[4];
bool winx(){
int i, j;
for (i=0; i<4; ++i){
	for (j=0; j<4; ++j){
			if (v[i][j]=='O' || v[i][j]=='.') break;
		}
		if (j>3) return 1; 
	}
for (i=0; i<4; ++i){
	for (j=0; j<4; ++j){
			if (v[j][i]=='O' || v[j][i]=='.') break;
		}
		if (j>3) return 1; 
	}
if ((v[0][0]=='X' || v[0][0]=='T') && (v[2][2]=='X' || v[2][2]=='T') && (v[1][1]=='X' || v[1][1]=='T') && (v[3][3]=='X' || v[3][3]=='T'))
	return 1;
if ((v[0][3]=='X' || v[0][3]=='T') && (v[1][2]=='X' || v[1][2]=='T') && (v[2][1]=='X' || v[2][1]=='T') && (v[3][0]=='X' || v[3][0]=='T'))
	return 1;
	return 0;
}
bool wino(){
int i, j;
for (i=0; i<4; ++i){
	for (j=0; j<4; ++j){
			if (v[i][j]=='X' || v[i][j]=='.') break;
		}
		if (j>3) return 1; 
	}
for (i=0; i<4; ++i){
	for (j=0; j<4; ++j){
			if (v[j][i]=='X' || v[j][i]=='.') break;
		}
		if (j>3) return 1; 
	}
if ((v[0][0]=='O' || v[0][0]=='T') && (v[2][2]=='O' || v[2][2]=='T') && (v[1][1]=='O' || v[1][1]=='T') && (v[3][3]=='O' || v[3][3]=='T'))
	return 1;
if ((v[0][3]=='O' || v[0][3]=='T') && (v[1][2]=='O' || v[1][2]=='T') && (v[2][1]=='O' || v[2][1]=='T') && (v[3][0]=='O' || v[3][0]=='T'))
	return 1;
	return 0;
}
bool have(){
int i, j;
for (i=0; i<4; ++i){
for (j=0; j<4; ++j){
if (v[i][j]=='.')
return 1;
}
}
return 0;
}
int main()
{
int i, t, j, k;
cin>>t;
for (i=1; i<=t; ++i){
printf("Case #%i: ", i);
for (j=0; j<4; ++j)
	cin>>v[j]; 
if (winx())
	printf("X won\n");
else if (wino())
	printf("O won\n");
else if (!have())
	printf("Draw\n");
else
	printf("Game has not completed\n");
}
return 0;
}