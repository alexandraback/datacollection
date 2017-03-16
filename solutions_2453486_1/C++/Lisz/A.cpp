#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

char mp[4][4];

int Cal( int x, int y, char player , int addx , int addy ){
	int ans = 1 ;
	for( int i=x+addx , j=y+addy ; i<4 && j<4 && i>=0 && j>=0 ; i+=addx , j+=addy ){
		if( mp[i][j] == player || mp[i][j] == 'T' )
			ans ++ ;
		else
			break;
	}
	return ans ;
}

int cal( char player ){
	int Max = 0 ;
	if(mp[0][0]=='T'||mp[0][0]==player)
		Max = max( Max , Cal(0,0,player,1,1));
	if(mp[0][3]=='T'||mp[0][3]==player)
		Max = max( Max , Cal(0,3,player,1,-1));
	for(int i=0;i<4;i++){
		if(mp[0][i]=='T'||mp[0][i]==player)
			Max = max( Max , Cal(0,i,player,1,0));
		if(mp[i][0]=='T'||mp[i][0]==player)
			Max = max( Max , Cal(i,0,player,0,1));
	}
	return Max ;
}

bool havepoint(){
	for( int i=0;i<4;i++ )
		for(int j=0;j<4;j++ )
			if( mp[i][j] == '.' )
				return true ;
	return false ;
}

int main(){
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
	int cas;
	int casn = 1 ;
	scanf("%d",&cas);
	while(cas--){
		for(int i=0;i<4;i++)
			scanf("%s",mp[i]);
		printf("Case #%d: ",casn++ );
		int cntx = cal( 'X' ) ;
		if( cntx == 4 ){
			puts("X won");
			continue ;
		}
		int cnty = cal( 'O' );
		if( cnty == 4 )
			puts("O won");
		else
			puts(havepoint()?"Game has not completed":"Draw");
	}
	return 0;
}
