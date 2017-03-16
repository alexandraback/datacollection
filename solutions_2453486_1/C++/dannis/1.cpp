#include <stdio.h>
#define N 4

char input[N][N];
char problem[2*N+2][N];
void showinput() {
	int i,j;
	for (i=0;i<N;i++){
			for (j=0;j<N;j++)
				printf("%c",input[i][j]);
			printf("\n");
	}
}
void calccolumn() {
	int i,j;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			problem[i][j]=input[i][j];
	for (;i<2*N;i++)
			for (j=0;j<N;j++)
				problem[i][j]=input[j][i-N];
	for (j=0;j<N;j++)
		problem[i][j]=input[j][j];
	for (j=0;j<N;j++)
		problem[i+1][j]=input[j][N-1-j];
}
void showcolumn() {
	int i,j;
	for (i=0;i<2*N+2;i++) {
		for (j=0;j<N;j++)
			printf("%c",problem[i][j]);
		printf("\n");
	}
}
int checkresult(char * ch) {
	//返回值1为Xwin,2为Owin,3为未结束，4为draw;
	int i=0,x=0,o=0,u=0;
	for (i=0;i<N;i++)
		switch (ch[i]) {
			case 'T':
				break;
			case 'X':
				x=1;
				break;
			case 'O':
				o=1;
				break;
			case '.':
				u=1;
				break;
	}
	if (u==1)
		return 3;
	if (x==1&&o==1)
		return 4;
	if (x==1)
		return 1;
	return 2;
}	
int getresult() {
	int i,uncompleted=0;
	for (i=0;i<2*N+2;i++)
		switch (checkresult(problem[i])) {
			case 1:
				return 1;
			case 2:
				return 2;
			case 3:
				uncompleted=1;
				break;
			case 4:
				;
	}
	if (uncompleted)
		return 3;
	return 4;
}
int main() {
	freopen("d:\\c\\A-large.in","r",stdin);
	freopen("d:\\c\\A-large.out","w",stdout);
	int i,j,x,t;
	char ch;
	scanf("%d ",&t);
	for (x=1;x<=t;x++) {
		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) {
				scanf("%c",&ch);
				input[i][j]=ch;
			}
			scanf("%c",&ch);
		}
		scanf("%c",&ch);
		//showinput();
		calccolumn();
		//showcolumn();
		printf("Case #%d: ",x);
		switch (getresult()) {
			case 1:
				printf("X won");
				break;
			case 2:
				printf("O won");
				break;
			case 3:
				printf("Game has not completed");
				break;
			case 4:
				printf("Draw");
		}
		if (x<t)
			printf("\n");
	}
	//while(1);
	return 0;
}




