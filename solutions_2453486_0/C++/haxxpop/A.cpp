#include<stdio.h>
char a[5][5];
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e< t ; e++ ){
		for(int i = 0; i < 4 ; i++ ) scanf("%s",a[i]);
		int stat = 0;
		int empty = 0;
		for(int i =0;i < 4 ; i++ ){
			for(int j =0 ;j < 4 ; j++ ){
				if( a[i][j] == '.' ) empty= 1;
			}
		}
		for(int i = 0 ;i < 4 ; i++ ){
			int chk = 1 ;
			for(int j = 0 ;j < 4 ; j++ ){
				if( a[i][j] == '.' || a[i][j] == 'O' ) chk = 0;
			}
			if( chk ){ stat = 1; break; }

			chk =1;
			for(int j = 0 ; j< 4 ; j++ ){
				if( a[i][j] == '.' || a[i][j] == 'X' ) chk = 0;
			}
			if( chk ){ stat = 2; break; }

			chk = 1;
			for(int j = 0 ;j< 4 ; j++ ){
				if( a[j][i] == '.' || a[j][i] == 'O' ) chk = 0;
			}
			if( chk ){ stat = 1; break; }

			chk = 1;
			for(int j = 0 ; j < 4 ; j++ ){
				if( a[j][i] == '.' || a[j][i] == 'X' ) chk = 0;
			}
			if( chk ){ stat = 2; break; }
		}
		int chk= 1;
		for(int i = 0 ;i < 4 ; i++ ){
			if( a[i][i] == '.' || a[i][i] == 'O' ) chk = 0;
		}
		if( chk ) stat = 1;

		chk = 1;
		for(int i = 0 ; i < 4 ; i++ ){
			if( a[i][i] == '.' || a[i][i] == 'X' ) chk = 0;
		}
		if( chk ) stat = 2;

		chk = 1;
		for(int i = 0 ; i < 4 ; i++ ){
			if( a[i][3-i] == '.' || a[i][3-i] == 'O' ) chk = 0;
		}
		if( chk ) stat = 1;

		chk = 1;
		for(int i = 0 ;i < 4 ; i++ ){
			if( a[i][3-i] == '.' || a[i][3-i] == 'X' ) chk = 0;
		}
		if( chk ) stat = 2;
		printf("Case #%d: ",e+1);
		if( stat == 1 ) printf("X won\n");
		if( stat == 2 ) printf("O won\n");
		if( stat == 0 && empty == 0 ) printf("Draw\n");
		if( stat == 0 && empty == 1 ) printf("Game has not completed\n");
	}
}


