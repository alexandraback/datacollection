#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <algorithm>

#define LL long long
#define LD long double
#define PROBLEM_T "C"
#define INPUT_T "small"
#define FM(i,a,b) for(int i=a;i<b;i++) //(b-a) times a ~ b-1
#define FILE_OPEN(x,y) char name1[50],name2[50],P_T[]=PROBLEM_T ,I_T[]=INPUT_T;sprintf(name1, "%s-%s.in",P_T,I_T);sprintf(name2,"%s-%s.out" ,P_T,I_T);x=fopen("temp.txt","r");y=fopen(name2, "w");// open file
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
const int N = 16;
const int J = 50;

int main() {
	FILE *fp1, *fp2; FILE_OPEN(fp1, fp2)
		char *answer; answer = (char *)malloc(sizeof(char)*(N + 1)); answer[N] = '\0';
	int i = 0, j = 0, k = 0, count = 0, key = 1;
	fprintf(fp2, "Case #1:\n");
	while(true) {
		memset(answer, '1', sizeof(char)*N);
		switch(key) {
		case 1:
			answer[i + 1] = '0';
			answer[i + 2] = '0';
			i += 2;
			if (i == N - 2) {
				key = 2;
				i = 2;
			}
			break;
		case 2:
			answer[j + 1] = '0';
			answer[j + 2] = '0';
			answer[i + 1] = '0';
			answer[i + 2] = '0';
			i += 2;
			if (i == N - 2) {
				j += 2;
				i = j + 2;
			}
			if (j == N - 4) {
				key = 3;
				j = 2;
				i = 4;
			}
			break;
		case 3:
			answer[i + 1] = '0';
			answer[i + 2] = '0';
			answer[j + 1] = '0';
			answer[j + 2] = '0';
			answer[k + 1] = '0';
			answer[k + 2] = '0';
			i += 2;
			if (i == N - 2) {
				j += 2;
				i = j + 2;
			}
			if (j == N - 4) {
				k += 2;
				j = k + 2;
				i = k + 4;
			}
			if (k == N - 4) {
				key = 4;
				break;
			}
		default: break;
		}
		fprintf(fp2, "%s", answer);
		FM(i, 3, 12) fprintf(fp2, " %d", i);
		fprintf(fp2, "\n");
			count++;
		if (count == J) break;
		
	}

	free(answer);
	FILE_CLOSE(fp1, fp2) return 0;
}
