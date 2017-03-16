#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <cstdlib>

using namespace std;

const int tmax = (int)1e5 + 100;

#define pb push_back
#define mp make_pair

char matrix[5][5];

bool hasCompleted( ){
	for( int i = 0; i < 4; i++)
		for( int j = 0; j < 4; j++)
			if( matrix[i][j] == '.' ) return false;
	return true;
}

#define px( y ) ( y == 'X' ? 0 : 1)

int winner(){
	for( int i = 0; i < 4; i++){
		int cx[5];
		memset(cx,0,sizeof(cx));	
		for( int j = 0; j < 4; j++){
			if( matrix[i][j] =='T' )
				cx[2]++;
			else if( matrix[i][j] == '.' )
				cx[3]++;
			else
				cx[px(matrix[i][j])]++;
		}
		if( cx[0] == 4 || (cx[0] == 3 && cx[2] == 1) ) return 0;
		if( cx[1] == 4 || (cx[1] == 3 && cx[2] == 1) ) return 1;
	}
	for( int i = 0; i < 4; i++){
		int cx[5];
		memset(cx,0,sizeof(cx));	
		for( int j = 0; j < 4; j++){
			if( matrix[j][i] =='T' )
				cx[2]++;
			else if( matrix[j][i] == '.' )
				cx[3]++;
			else
				cx[px(matrix[j][i])]++;
		}
		if( cx[0] == 4 || (cx[0] == 3 && cx[2] == 1) ) return 0;
		if( cx[1] == 4 || (cx[1] == 3 && cx[2] == 1) ) return 1;
	}
	int cx[5];
	memset(cx,0,sizeof(cx));
	for( int i = 0; i < 4; i++){				
		if( matrix[i][i] =='T' )
			cx[2]++;
		else if( matrix[i][i] == '.' )
			cx[3]++;
		else
			cx[px(matrix[i][i])]++;
	}
	if( cx[0] == 4 || (cx[0] == 3 && cx[2] == 1) ) return 0;
	if( cx[1] == 4 || (cx[1] == 3 && cx[2] == 1) ) return 1;
	memset(cx,0,sizeof(cx));
	for( int i = 0; i < 4; i++){				
		if( matrix[i][3 - i] =='T' )
			cx[2]++;
		else if( matrix[i][3 - i] == '.' )
			cx[3]++;
		else
			cx[px(matrix[i][3 - i])]++;
	}
	if( cx[0] == 4 || (cx[0] == 3 && cx[2] == 1) ) return 0;
	if( cx[1] == 4 || (cx[1] == 3 && cx[2] == 1) ) return 1;
	return -1;
}

int main()
{
	/*freopen("A-large.in", "r", stdin);
	freopen("saida-Large.out", "w", stdout);*/
	int t, tt = 1;
	scanf("%d", &t);
	while(t--){
		for( int i = 0; i < 4; i++)
			for( int j = 0; j < 4; j++)
				scanf(" %c", &matrix[i][j]);
		int hwin = winner();
		bool flag = hasCompleted();
		printf("Case #%d: ", tt++);
		if( hwin == -1 && !flag )
			printf("Game has not completed\n");
		else if( hwin == -1 )
			printf("Draw\n");
		else
			printf("%c won\n", (hwin == 0 ? 'X' : 'O'));		
	}
	
	return 0;
}

