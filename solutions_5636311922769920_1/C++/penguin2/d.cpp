#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <algorithm>

#define LL long long
#define LD long double
#define PROBLEM_T "D"
#define INPUT_T "large"
#define FM(i,a,b) for(int i=a;i<b;i++) //(b-a) times a ~ b-1
#define FILE_OPEN(x,y) char name1[50],name2[50],P_T[]=PROBLEM_T ,I_T[]=INPUT_T;sprintf(name1, "%s-%s.in",P_T,I_T);sprintf(name2,"%s-%s.out" ,P_T,I_T);x=fopen(name1,"r");y=fopen(name2, "w");// open file
#define FILE_CLOSE(x,y) fclose(fp1);fclose(fp2); //close file
#define D_INPUT_A(fp1,x) int x;fscanf(fp1,"%d ",&x);
#define D_INPUT_B(fp1,x,y) int x; int y;fscanf(fp1,"%d %d " ,&x,&y);
#define D_INPUT_C(fp1,x,y,z) int x;int y;int z;fscanf(fp1,"%d %d %d ",&x,&y,&z);
#define INPUT_A(fp1,x) fscanf(fp1,"%d ",&x);
#define INPUT_B(fp1,x,y) fscanf(fp1,"%d %d ",&x,&y);
#define INPUT_C(fp1,x,y,z) fscanf(fp1,"%d %d %d ",&x,&y,&z);
#define INPUT_CHAR(fp1,x) fscanf(fp1,"%s ",x);
#define OUTPUT(fp2,x) fprintf(fp2,"Case #%d: %d\n",n+1,x);
#define OUTPUT_B(fp2,x,y) fprintf(fp2,"Case #%d: %d %d\n",n+1,x,y);
#define OUTPUT_CHAR(fp2,x) fprintf(fp2,"Case #%d: %s\n",n+1,x);

const LD EPS = 1e-10;
const LD PI = acos(-1.0);

int main() {
	int cp;
	FILE *fp1, *fp2; FILE_OPEN(fp1, fp2)

		D_INPUT_A(fp1, T)
		FM(n, 0, T) {
		D_INPUT_C(fp1, K, C, S) //init
		if (C == 1) cp = K;
		else cp = K / 2 + K % 2;

		if(S < cp) OUTPUT_CHAR(fp2,"IMPOSSIBLE")
		else {
			fprintf(fp2, "Case #%d:", n + 1);
			if(C == 1) FM(i, 0, K) fprintf(fp2, " %d", i + 1);
			else FM(i, 0, cp) fprintf(fp2, " %d", (i + 1)*K - i);
			fprintf(fp2, "\n");
		}
	}
	FILE_CLOSE(fp1, fp2) return 0;
}
