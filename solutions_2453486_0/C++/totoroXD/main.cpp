#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#include<string>
using namespace std;
char brd[5][5];
int cnt;

bool check_row(int i, char p)
{
	int cntp=0,cntt=0;
	for(int j=0; j<4; j++){
		if(brd[i][j]==p){
			cntp++;
		}
		else if(brd[i][j]=='T'){
			cntt++;
		}
	}
	return cntp==4 || (cntp==3 && cntt==1);
}
bool check_col(int i, char p)
{
	int cntp=0,cntt=0;
	for(int j=0; j<4; j++){
		if(brd[j][i]==p){
			cntp++;
		}
		else if(brd[j][i]=='T'){
			cntt++;
		}
	}
	return cntp==4 || (cntp==3 && cntt==1);
}
bool check_diag(char p){
	int cntp=0,cntt=0;
	for(int i=0; i<4; i++){
		if(brd[i][i]==p){
			cntp++;
		}
		else if(brd[i][i]=='T'){
			cntt++;
		}
	}
	if(cntp==4 || (cntp==3 && cntt==1))return 1;
	cntp=0,cntt=0;
	for(int i=0; i<4; i++){
		if(brd[i][3-i]==p){
			cntp++;
		}
		else if(brd[i][3-i]=='T'){
			cntt++;
		}
	}
	return cntp==4 || (cntp==3 && cntt==1);
}
bool check_full()
{
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(brd[i][j]=='.')return 0;
		}
	}
	return 1;
}
void input()
{
	for(int i=0; i<4; i++)scanf("%s",&brd[i]);
}
void solve()
{
	printf("Case #%d: ",cnt+1);
	for(int i=0; i<4; i++){
		if(check_row(i, 'X')){
			printf("X won\n");
			return ;
		}
		else if(check_col(i, 'X')){
			printf("X won\n");
			return ;
		}
		else if(check_row(i, 'O')){
			printf("O won\n");
			return ;
		}
		else if(check_col(i, 'O')){
			printf("O won\n");
			return ;
		}
	}
	if(check_diag('O'))
		printf("O won\n");
	else if(check_diag('X'))
		printf("X won\n");
	else if(check_full())
		printf("Draw\n");
	else
		printf("Game has not completed\n");
}
int main ()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int zz;
	scanf("%d",&zz);
	for(cnt=0; cnt<zz; cnt++){
		input();
		solve();
	}
}
