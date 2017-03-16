#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int t,n,m,ct;
char s[100][100];
int cnth[4];

void init(){
	for ( int i = 0 ; i < 4 ; i++ ) scanf("%s",s[i]);
}
void work(){
	bool empty = false ;
	int winner = 0;
	for ( int i = 0 ; i < 4 ; i++ )
		for ( int j = 0 ; j < 4 ; j++ )
			empty |= (s[i][j]=='.');
	for ( int i = 0 ; i < 4 ; i++ ){
		cnth[i] = 0;
		for ( int j = 0 ; j < 4 ; j++ ){
			switch (s[i][j]){
			case 'O': cnth[i] += 2;break;
			case 'T': cnth[i] += 0;break;
			case 'X': cnth[i] += -2;break;
			case '.': cnth[i] += -1000000;break;
			}
		}
		if (cnth[i]<-50000) continue;
		if (cnth[i]>=6) winner = 1;
		if (cnth[i]<=-6) winner = -1;
	}
	for ( int i = 0 ; i < 4 ; i++ ){
		cnth[i] = 0;
		for ( int j = 0 ; j < 4 ; j++ ){
			switch (s[j][i]){
			case 'O': cnth[i] += 2;break;
			case 'T': cnth[i] += 0;break;
			case 'X': cnth[i] += -2;break;
			case '.': cnth[i] += -1000000;break;
			}
		}
		if (cnth[i]<-50000) continue;
		if (cnth[i]>=6) winner = 1;
		if (cnth[i]<=-6) winner = -1;
	}
	for ( int i = 0 ; i < 2 ; i++ ){
		cnth[i] = 0;
		for ( int j = 0 ; j < 4 ; j++ ){
			switch (s[j][(i==1)?(3-j):j]){
			case 'O': cnth[i] += 2;break;
			case 'T': cnth[i] += 0;break;
			case 'X': cnth[i] += -2;break;
			case '.': cnth[i] += -1000000;break;
			}
		}
		if (cnth[i]<-50000) continue;
		if (cnth[i]>=6) winner = 1;
		if (cnth[i]<=-6) winner = -1;
	}
	if (winner==1) printf("O won\n");
	if (winner==-1) printf("X won\n");
	if (winner==0 && empty==false) printf("Draw\n");
	if (winner==0 && empty==true) printf("Game has not completed\n");
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	for ( scanf("%d",&t),ct = 1 ; ct <= t ; ct++ ){
		printf("Case #%d: ",ct);
		init();
		work();
	}
}
