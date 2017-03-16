#include<stdio.h>
#define click 1


int R, M, C;
bool swapflag;
int table[51][51];



int process(){

	int i = R, j = C;
	if (M == 0)
		return 0;
	for (i = R; i > 3; i--){
		for (j = C; j > 0; j--){

			table[i][j] = -1;
			M--;
			if (M <= 0){
				goto M1;
			}
		}
	}

M1:	if (M == 0){ //3*n + a case 
		if (table[i][1] == 0 && table[i][2]==-1){ //ÇÏ³ª »ßÁ®³ª¿È
			table[i][2] = 0;
			table[i - 1][C] = -1;
		}
	}
	else if ((M>0 && (table[3][C]==0 && table[4][1] == -1)) || R==3){ // 3*n - a case
		for (j = C; j > 3; j--){
			for (i = 3; i >= 1; i--){
				table[i][j] = -1;
				M--;
				if (M <= 0){
					goto M2;
				}
			}
		}
	M2:	if (M == 0){ //3*(3+a)+ b case
			if (i == 2){ //ÇÏ³ª »ßÁ®³ª¿È
				table[2][j] = 0;
				table[3][j - 1] = -1;
			}
		}
		else if ((table[3][3] == 0 && table[1][4] == -1)||(R==3 && C==3)){ //3*3

			switch (M){
			case 8:
				table[2][2] = table[2][1] = table[1][2] = -1;
			case 5:
				table[2][3] = table[1][3] = -1;
			case 3:
				table[3][2] = table[3][1] = -1;
			case 1:
				table[3][3] = -1;
			case 0:
				M = 0;
				break;
			default:
				return -1; //impossible
			}
		}

	}
	else if (R == 2){ // 2*n case
		if (M == 2*C - 1 || (M % 2 == 0 && 2*C - M > 2)){
			for (j = C; M>0; j--){
				table[1][j] = table[2][j] = -1;
				M -= 2;
			}
			table[1][1] = click;
		}
		else{
			return -1;
		}
	}
	else if (R == 1){
		for (j = C; j >= 1 && M--; j--)
			table[1][j] = -1;
	}
	if (M>0)
		return -1;
	return 0;
}

void newTable(){
	for (int i = 0; i <= 50; i++){
		for (int j = 0; j <= 50; j++)
			table[i][j] = 0;
	}
}

void getData(){
	scanf("%d %d %d", &R, &C, &M);
	swapflag = 0;
	if (R > C){
		int t = R;
		R = C;
		C = t;
		swapflag = 1;		
	}
	newTable();
}
void printAns(int type){
	int i, j;
	
	if (type == -1){
		printf("Impossible\n");
		return;
	}
	table[1][1] = 1;

	if (swapflag){
		for (i = 1; i <= C; i++){
			for (j = 1; j <= R; j++){
				switch (table[j][i]){
				case -1:
					printf("*");
					break;
				case 0:
					printf(".");
					break;
				case 1:
					printf("c");
					break;
				}
			}
			printf("\n");
		}		
	}
	else{
		for (i = 1; i <= R; i++){
			for (j = 1; j <= C; j++){
				switch (table[i][j]){
				case -1:
					printf("*");
					break;
				case 0:
					printf(".");
					break;
				case 1:
					printf("c");
					break;
				}
			}
			printf("\n");
		}
	}

	
	
}

int main(){
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	//printf("%d\n", T);
	for (int i = 1; i <= T; i++){
		getData();
		printf("Case #%d:\n", i);
		//printf("%d %d\n", M, R);
		printAns(process());
	}
}