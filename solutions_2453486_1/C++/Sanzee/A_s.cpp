// Author : Muhammad Rifayat Samee
// Problem : A
// Algorithm:
#pragma warning (disable : 4786)
#pragma comment(linker, "/STACK:16777216")

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 987654321
#define pi (2*acos(0.0))
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define i64 long long
#else
#define i64 __int64
#endif

using namespace std;
char str1[5][5];
char str2[5][5];
int main(){

	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	int cases,i,j,k,f,wx,wo,ct=1;
	scanf("%d",&cases);
	while(cases--){
		for(i=0;i<4;i++){
			scanf("%s",str1[i]);
		}
		wx = 0;
		wo = 0;
		f = 0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				str2[i][j] = str1[i][j];
				if(str1[i][j] == 'T'){
					str1[i][j] = 'X';
					str2[i][j] = 'O';

				}
				if(str1[i][j] == '.')f = 1;
			}
		}
		
		if(str2[0][0] == str2[0][1] && str2[0][0] == str2[0][2] && str2[0][0] == str2[0][3]){
			 if(str2[0][0] == 'O')
				wo++;
		}
		if(str2[1][0] == str2[1][1] && str2[1][0] == str2[1][2] && str2[1][0] == str2[1][3]){
			if(str2[1][0] == 'O')
				wo++;
		}
		if(str2[2][0] == str2[2][1] && str2[2][0] == str2[2][2] && str2[2][0] == str2[2][3]){
			if(str2[2][0] == 'O')
				wo++;
		}
		if(str2[3][0] == str2[3][1] && str2[3][1] == str2[3][2] && str2[3][2] == str2[3][3]){
			if(str2[3][0] == 'O')
				wo++;
		}
		if(str2[0][0] == str2[1][0] && str2[0][0] == str2[2][0] && str2[0][0] == str2[3][0]){
			if(str2[0][0] == 'O')
				wo++;
		}
		if(str2[0][1] == str2[1][1] && str2[1][1] == str2[2][1] && str2[0][1] == str2[3][1]){
			if(str2[0][1] == 'O')
				wo++;
		}
		if(str2[0][3] == str2[1][3] && str2[1][3] == str2[2][3] && str2[2][3] == str2[3][3]){
			if(str2[0][3] == 'O')
				wo++;
		}
		if(str2[0][2] == str2[1][2] && str2[1][2] == str2[2][2] && str2[0][2] == str2[3][2]){
			if(str2[0][2] == 'O')
				wo++;
		}
		if(str2[0][0] == str2[1][1] && str2[1][1] == str2[2][2] && str2[0][0] == str2[3][3]){
			if(str2[0][0] == 'O')
				wo++;
		}
		if(str2[0][3] == str2[1][2] && str2[1][2] == str2[2][1] && str2[2][1] == str2[3][0]){
			if(str2[0][3] == 'O')
				wo++;
		}
		//
		if(str1[0][0] == str1[0][1] && str1[0][0] == str1[0][2] && str1[0][0] == str1[0][3]){
			 if(str1[0][0] == 'X')
				wx++;
		}
		if(str1[1][0] == str1[1][1] && str1[1][0] == str1[1][2] && str1[1][0] == str1[1][3]){
			if(str1[1][0] == 'X')
				wx++;
		}
		if(str1[2][0] == str1[2][1] && str1[2][0] == str1[2][2] && str1[2][0] == str1[2][3]){
			if(str1[2][0] == 'X')
				wx++;
		}
		if(str1[3][0] == str1[3][1] && str1[3][1] == str1[3][2] && str1[3][2] == str1[3][3]){
			if(str1[3][0] == 'X')
				wx++;
		}
		if(str1[0][0] == str1[1][0] && str1[0][0] == str1[2][0] && str1[0][0] == str1[3][0]){
			if(str1[0][0] == 'X')
				wx++;
		}
		if(str1[0][1] == str1[1][1] && str1[1][1] == str1[2][1] && str1[0][1] == str1[3][1]){
			if(str1[0][1] == 'X')
				wx++;
		}
		if(str1[0][2] == str1[1][2] && str1[1][2] == str1[2][2] && str1[0][2] == str1[3][2]){
			if(str1[0][2] == 'X')
				wx++;
		}
		if(str1[0][3] == str1[1][3] && str1[1][3] == str1[2][3] && str1[2][3] == str1[3][3]){
			if(str1[0][3] == 'X')
				wx++;
		}
		if(str1[0][0] == str1[1][1] && str1[1][1] == str1[2][2] && str1[0][0] == str1[3][3]){
			if(str1[0][0] == 'X')
				wx++;
		}
		if(str1[0][3] == str1[1][2] && str1[1][2] == str1[2][1] && str1[2][1] == str1[3][0]){
			if(str1[0][3] == 'X')
				wx++;
		}
		printf("Case #%d: ",ct++);
		if(wo)
			printf("O won\n");
		else if(wx){
			printf("X won\n");
		}
		else{
			if(f == 0){
				printf("Draw\n");
			}
			else
				printf("Game has not completed\n");
		}
	}
	return 0;
}
