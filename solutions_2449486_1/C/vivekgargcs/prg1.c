#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char *pname;
int checkBrd(int myBrd[100][100],FILE *fpOut,int maxX,int maxY) {
        int i,j,invalid=0;
        int maxTop[100],maxBot[100];
        for (i=0;i<maxX;i++) {
        	for (j=0;j<maxY;j++) {
	        	if(j==0) 
	        		maxTop[i]=0;
	        	if(i==0)
	        		maxBot[j]=0;
        		if (maxTop[i] < myBrd[i][j]) {
				maxTop[i]= myBrd[i][j] ;
			}
			if (maxBot[j] < myBrd[i][j]) {
				maxBot[j]= myBrd[i][j] ;
			}
        	}
        }
	for (i=0;i<maxX;i++) {
        	for (j=0;j<maxY;j++) {
			if(maxTop[i] > myBrd[i][j] && maxBot[j] > myBrd[i][j] ) {
				invalid=1;
			}
		}
	}
        if (invalid == 1) {
        	fprintf(fpOut,"NO");
        	printf("NO");
        } else {
        	fprintf(fpOut,"YES");
        	printf("YES");
        }

        fprintf(fpOut,"\n");
        printf("\n");
        return(0);
}

void Usage(char *Msg,int status) {
	printf("Usage : %s FileName\n",pname);
	printf("Example : %s testFile1\n",pname);
	printf("%s\n",Msg);
	exit(status);
}
int main(int argc,char *argv[]) {
	char a;
	pname=argv[0];
	printf("VIVEK : Arguments count %d \n",argc);
	if(argc != 2) {
		Usage("ERROR: No Argument Found",255);
	} 
	FILE *fp,*fpOut;
	char *fileName=argv[1];
	fp=fopen(fileName,"r");
	fpOut=fopen("TTResult","w");
	char c;
	int totalCount,noSteps,i,j,k,stepLen,stepCount,time,myBrd[100][100],stepAB,maxX,maxY;
	fscanf(fp,"%d",&totalCount);
	printf("Count : %d\n",totalCount);
	fscanf(fp,"%c",&c);
	for(i=0;i<totalCount;i++) {
		fscanf(fp,"%d %d",&maxX,&maxY);
		for (j=0;j<maxX;j++) {
			for (k=0;k<maxY;k++) {
				fscanf(fp,"%d",&stepAB);
				printf(">>%d<<",stepAB);
				myBrd[j][k]=stepAB;
			}
			printf("\n");
		}
		printf("\n %d %d\n",maxX,maxY);
		fprintf(fpOut,"Case #%d: ",(i+1));
		checkBrd(myBrd,fpOut,maxX,maxY);
		fscanf(fp,"%c",&c);
		
	}
}
