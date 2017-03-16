#include <stdio.h>
#include <stdlib.h>

FILE *ifp;
FILE *ofp;

int T;
int X, R, C;

int process();
void output(int, int);

int main(void){
	int i, j;

	ifp = fopen("D-large.in", "r");
	ofp = fopen("output.txt","w");

	fscanf(ifp, "%d", &T);
	
	for(i=0;i<T;i++){
		fscanf(ifp, "%d %d %d", &X, &R, &C);
		output(i+1, process());
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}

int process(){
	int size=R*C;

	if(size%X!=0)
		return 0;

	if((X+1)/2>=R || (X+1)/2>=C)
		return 0;

	if(R==1 || C==1)
		return 0;

	if(X>=7)
		return 0;

	return 1;
}

void output(int t, int res){
	fprintf(ofp, "Case #%d: %s\n", t, res?"GABRIEL":"RICHARD");
	//fprintf(ofp, "Case #%d: (%d,%d,%d) %s\n", t, X,R,C, res?"GABRIEL":"RICHARD");
}