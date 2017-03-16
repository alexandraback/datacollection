#include<stdio.h>
int T,dir[4][2]={{0,1},{1,1},{1,0},{1,-1}};
bool X,O,draw;
char t[5][5];

bool check(char c)
{
	int cnt;
	for( int i = 0; i < 4; i++ ){
		for( int j = 0; j < 4; j++ ){
			for( int m = 0; m < 4; m++ ){
				cnt = 0;
				for( int k = i,l = j; k >= 0 && k < 4 && l >= 0 && l < 4; k+=dir[m][0], l+=dir[m][1] ){
					if( t[k][l] == 'T' || t[k][l] == c ) cnt++;
					else	break;
				}
				if( cnt == 4 )	return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("pa.out","w",stdout);


	scanf(" %d",&T);
	for( int cas = 1; cas <= T; cas++ ){
		draw = 1;
		for( int i = 0; i < 4; i++ ){
			for( int j = 0; j < 4; j++ ){
				scanf(" %c",&t[i][j]);
				if( t[i][j] == '.' )draw = 0;
			}
		}
		X = check('X');
		O = check('O');
		printf("Case #%d: ",cas);
		if(X)			printf("X won\n");
		else if(O)		printf("O won\n");
		else if(draw)	printf("Draw\n");
		else			printf("Game has not completed\n");
	}

	return 0;
}
