#include <stdio.h>

int main(){
	int i,j,cases,board[4][4],hasdot,match,val0,val1,val2,val3,val4,val5,val6,val7,val8,val9;
	char tmp;
	//freopen("as.in","r",stdin);
	//freopen("as.out","w+",stdout);
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		j=0;
		hasdot = 0;
		while(j<16){
			tmp = getchar();
			if(tmp!='\n' && tmp!='\r'){
				board[j/4][j%4] = tmp;
				if (tmp=='.') hasdot=1;
				j++;
			}
		}
		val1 = board[0][0]+board[0][1]+board[0][2]+board[0][3];
		val2 = board[1][0]+board[1][1]+board[1][2]+board[1][3];
		val3 = board[2][0]+board[2][1]+board[2][2]+board[2][3];
		val4 = board[3][0]+board[3][1]+board[3][2]+board[3][3];
		
		val5 = board[0][0]+board[1][0]+board[2][0]+board[3][0];
		val6 = board[0][1]+board[1][1]+board[2][1]+board[3][1];
		val7 = board[0][2]+board[1][2]+board[2][2]+board[3][2];
		val8 = board[0][3]+board[1][3]+board[2][3]+board[3][3];
		
		val9 = board[0][0]+board[1][1]+board[2][2]+board[3][3];
		val0 = board[3][0]+board[2][1]+board[1][2]+board[0][3];
		
		match = 'X'*4;
		if(val0 == match || val1 == match || val2 == match || val3 == match || val4 == match || val5 == match || val6 == match || val7 == match || val8 == match || val9 == match){
			printf("Case #%d: X won\n",i+1);
			continue;
		}
		match = 'X'*3+'T';
		if(val0 == match || val1 == match || val2 == match || val3 == match || val4 == match || val5 == match || val6 == match || val7 == match || val8 == match || val9 == match){
			printf("Case #%d: X won\n",i+1);
			continue;
		}
		match = 'O'*4;
		if(val0 == match || val1 == match || val2 == match || val3 == match || val4 == match || val5 == match || val6 == match || val7 == match || val8 == match || val9 == match){
			printf("Case #%d: O won\n",i+1);
			continue;
		}
		match = 'O'*3+'T';
		if(val0 == match || val1 == match || val2 == match || val3 == match || val4 == match || val5 == match || val6 == match || val7 == match || val8 == match || val9 == match){
			printf("Case #%d: O won\n",i+1);
			continue;
		}
		if(hasdot){
			printf("Case #%d: Game has not completed\n",i+1);
		}
		else{
			printf("Case #%d: Draw\n",i+1);
		}
	}
	return 0;
}
